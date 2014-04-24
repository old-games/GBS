#ifndef __DATA_MODE_H__
#define __DATA_MODE_H__

enum PaletteMode
{
	CGA1,
	CGA2,
	CGA3,
	EGA,
	VGA,
	GREY1,
	GREY2,
	TRUECOLOR,
	CUSTOM
};



namespace DataMode
{
	enum Mode
	{
		dmRaw,
		dmGraphicPlanarEga,
		dmRowPlanarEga,
		dmBytePlanaerEga,
		dmNum
	};

	extern const wxString Names[dmNum];
}

typedef unsigned long long DataBuffer;

class DataProcessor
{
	public:
		explicit DataProcessor(const unsigned char* r,
			const unsigned char* g, const unsigned char* b);

		void SetSource(const DataBuffer* src, size_t size)
		{
			mSource = src;
			mMaxSourceSize = size;
		}

		void ProcessData(DataMode::Mode mode, PaletteMode palMode,
			int width, int height,
			unsigned char *dest, int maxColours);
		
		bool ExportToBMP(const wxString& name);
	private:

		void ProcessRaw();
		void ProcessTrueColour();
		void ProcessGPEGA();
		void ProcessRPEGA();
		void ProcessBPEGA();
		void ApplyEgaPoint(uint& destOffset, uint offset1,
			uint offset2, uint offset3, uint offset4);

		const DataBuffer*	mSource;
		size_t				mMaxSourceSize;
		const unsigned char*			mRed;
		const unsigned char*			mGreen;
		const unsigned char*			mBlue;

		DataMode::Mode	mMode;
		PaletteMode		mPalMode;
		int				mWidth;
		int				mHeight;
		unsigned char*	mDest;
		size_t			mMaxColours;
};





#endif // __DATA_MODE_H__

