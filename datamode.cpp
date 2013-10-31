#include "wx_pch.h"
#include "datamode.h"


namespace DataMode
{

/* static */ const wxString Names[dmNum] =
	{
		"Raw",
		"Graphic-planar EGA",
		"Row-planar EGA",
		"Byte-planar EGA"
	};

} // namespace DataMode



DataProcessor::DataProcessor(const unsigned char* r,
	const unsigned char* g, const unsigned char* b):
	mSource(NULL),
	mMaxSourceSize(0),
	mRed(r),
	mGreen(g),
	mBlue(b),
	mMode(DataMode::dmRaw),
	mPalMode(CGA1),
	mWidth(0),
	mHeight(0),
	mDest(NULL),
	mMaxColours(0)
{
}



void DataProcessor::ProcessRaw()
{
	unsigned char col = 0;
	unsigned int srcOffset = 0;
	unsigned int destOffset = 0;

	for (int i = 0; i < mHeight; ++i)
	{
		for (int j = 0; j < mWidth; ++j)
		{
			col = mSource[srcOffset++];

			if (col < mMaxColours)
			{
				mDest[destOffset++] = mRed[col];
				mDest[destOffset++] = mGreen[col];
				mDest[destOffset++] = mBlue[col];
			}
			else
			{
				destOffset += 3;
			}
		}
	}
}



void DataProcessor::ProcessTrueColour()
{
	wxColour color;
	unsigned int destOffset = 0;
	size_t size = mWidth * mHeight;

	for (uint i = 0; i < size; ++i)
	{
		color.SetRGB(mSource[i]);
		mDest[destOffset++] = color.Red();
		mDest[destOffset++] = color.Green();
		mDest[destOffset++] = color.Blue();
	}
}



inline unsigned char EGAPlanesToPalNumber(uchar r, uchar g, uchar b, uchar i)
{
	//wxLogDebug("r: %d, g: %d, b: %d, i: %d,", r, g, b, i);
	assert(i < 2 && r < 2 && g < 2 && b < 2);
	return (i << 3) | (r << 2) | (g << 1) | b;
}



void DataProcessor::ProcessGPEGA()
{
	unsigned char col = 0;
	unsigned int srcOffset = 0;
	unsigned int destOffset = 0;
	//wxLogDebug("%dx%d", mWidth, mHeight);
	int offset = mHeight * mWidth;
	int offset1 = offset * 2;
	int offset2 = offset * 3;

	for (int i = 0; i < mHeight; ++i)
	{
		for (int j = 0; j < mWidth; ++j)
		{
			ApplyEgaPoint(destOffset, srcOffset,
				srcOffset + offset,
				srcOffset + offset1,
				srcOffset + offset2);
			++srcOffset;
		}
	}
}



inline void DataProcessor::ApplyEgaPoint(uint& destOffset, uint offset1,
	uint offset2, uint offset3, uint offset4)
{
	//wxLogDebug("%d, %d, %d, %d", offset1, offset2, offset3, offset4);
	uchar b = mSource[offset1];
	uchar g = mSource[offset2];
	uchar r = mSource[offset3];
	uchar i = mSource[offset4];
	uchar col = EGAPlanesToPalNumber(r, g, b, i);

	if (col < mMaxColours)
	{
		mDest[destOffset++] = mRed[col];
		mDest[destOffset++] = mGreen[col];
		mDest[destOffset++] = mBlue[col];
	}
	else
	{
		destOffset += 3;
	}
}



void DataProcessor::ProcessRPEGA()
{
	unsigned char col = 0;
	unsigned int srcOffset = 0;
	unsigned int destOffset = 0;
	//wxLogDebug("%dx%d", mWidth, mHeight);
	int offset = 2;
	int offset1 = 4;
	int offset2 = 6;

	for (int i = 0; i < mHeight; ++i)
	{
		for (int j = 0; j < mWidth >> 1; ++j)
		{
			ApplyEgaPoint(destOffset, srcOffset,
				srcOffset + offset, srcOffset + offset1, srcOffset + offset2);
			++srcOffset;
			ApplyEgaPoint(destOffset, srcOffset,
				srcOffset + offset, srcOffset + offset1, srcOffset + offset2);
			srcOffset += 7;
		}
	}
}



void DataProcessor::ProcessBPEGA()
{
	unsigned char col = 0;
	unsigned int srcOffset = 0;
	unsigned int destOffset = 0;
	//int step = 1; //mWidth >> 2;
	int ofs1 = 1;
	int ofs2 = 2;
	int ofs3 = 3;

	for (int i = 0; i < mHeight; ++i)
	{
		for (int j = 0; j < mWidth; ++j)
		{
			ApplyEgaPoint(destOffset, srcOffset,
				srcOffset + ofs1, srcOffset + ofs2, srcOffset + ofs3);
			srcOffset += 4;
		}

	}

}



void DataProcessor::ProcessData(DataMode::Mode mode, PaletteMode palMode,
		int width, int height,
		unsigned char *dest, int maxColours)
{
	mMode = mode;
	mPalMode = palMode;
	mWidth = width;
	mHeight = height;
	mDest = dest;
	mMaxColours = maxColours;

	if (palMode != TRUECOLOR)
	{
		switch (mode)
		{
			case DataMode::dmRaw:
				ProcessRaw();
			break;

			case DataMode::dmGraphicPlanarEga:
				ProcessGPEGA();
			break;

			case DataMode::dmRowPlanarEga:
				ProcessRPEGA();
			break;

			case DataMode::dmBytePlanaerEga:
				ProcessBPEGA();
			break;

			default:
				assert(false);
		}
	}
	else
	{
		ProcessTrueColour();
	}
}


