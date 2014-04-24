#include "wx_pch.h"
#include "bmpie.h"

bool BMPIE::loadBMP(void* dest, wxString name, int chw, int chh, int* bpp)
{
    BMFH bhead;
    BMIH ihead;
    unsigned short bfType;
    wxFile file;
    if (!file.Open(name, wxFile::read))
    {
        wxLogError("Unable to open BMP file: %s", name);
        return false;
    }
    file.Read(&bfType, 2);
    if (bfType!=0x4D42)
    {
        wxLogError("Unknown file type: %s", name);
        return false;
    }
    file.Read(&bhead, sizeof(bhead));
    file.Read(&ihead, sizeof(ihead));
    *bpp = ihead.biBitCount;
    if (ihead.biBitCount!=8 && ihead.biBitCount!=24)
    {
        wxLogError("Only 8 and 24 bpp images are supported.");
        return false;
    }
    if (ihead.biWidth != chw || ihead.biHeight != chh)
    {
        wxLogError("Size of image must be equal to defined. There is width: %d, and height: %d", ihead.biWidth, ihead.biHeight);
        return false;
    }
    unsigned char* buf = (unsigned char*) malloc((chw+4) * chh * (ihead.biBitCount >> 3));
    file.Seek(bhead.bfOffBits, wxFromStart);
    file.Read(buf, file.Length() - bhead.bfOffBits);
    file.Close();
    BMP2BUF(dest, buf, chw, chh, *bpp);
    free(buf);
    return true;
}

//
bool BMPIE::saveBMP(void* src, wxString name, int width, int height, int bpp)
{
    unsigned short bfType=0x4D42;
    char nil=0;
    unsigned int bufsize = (width+4) * height * (bpp >> 3);
    unsigned char *newbuf=(unsigned char *) malloc(bufsize);
    memset(newbuf, 0, bufsize);
    //
    BMFH bhead;
    BMIH ihead;
    bhead.bfReserved1=0;
    bhead.bfReserved2=0;
    bhead.bfOffBits=1078;
    if (bpp != 8) bhead.bfOffBits = sizeof(BMFH) + sizeof(BMIH) + 2;
    //
    ihead.biSize = sizeof(ihead);
    ihead.biWidth = width;
    ihead.biHeight = height;
    ihead.biPlanes = 1;
    ihead.biBitCount = bpp;
    ihead.biCompression = 0;
    ihead.biSizeImage = BUF2BMP(newbuf, src, width, height, bpp);
    bhead.bfSize=ihead.biSizeImage+sizeof(ihead)+sizeof(bhead) + 2;
    if (bpp == 8) bhead.bfSize += 1024;
    ihead.biXPelsPerMeter = 0;
    ihead.biYPelsPerMeter = 0;
    ihead.biClrUsed = 0;
    ihead.biClrImportant = 0;
    //
    wxFile bfile;
    if (!bfile.Create(name, true))
    {
        wxLogError("Unable to create BMP file: %s", name);
        free(newbuf);
        return false;
    }
    bfile.Write(&bfType, 2);
    bfile.Write(&bhead, sizeof(bhead));
    bfile.Write(&ihead, sizeof(ihead));
    if (bpp == 8)
        for (int i=0; i<256; i++) {
            bfile.Write(&blue[i], 1);
            bfile.Write(&green[i], 1);
            bfile.Write(&red[i], 1);
            bfile.Write(&nil, 1);
        }
    bfile.Write(newbuf, ihead.biSizeImage);
    free(newbuf);
    bfile.Close();
    return true;
}

// из-за дебильного формата БМП создаются такие уёбки, как этот
void BMPIE::BMP2BUF(void *dest, unsigned char *src, int w, int h, int bpp)
{
    int JUNK = (3 * w) % 4;
    uint64* buf = (uint64*) dest;
    unsigned int pos_in = 0;
    unsigned int pos_out = 0;
    switch (bpp)
    {
        case 8:
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    buf[pos_out] = src[pos_in];
                    ++pos_out;
                    ++pos_in;
                }
                pos_in+=JUNK;
            }
        break;
        case 24:
            wxColour col;
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    col.Set(src[pos_in+2], src[pos_in+1], src[pos_in]);
                    pos_in+=3;
                    buf[pos_out] = col.GetRGB();
                    ++pos_out;
                }
                pos_in+=JUNK;
            }
        break;
    }
}

int BMPIE::BUF2BMP(unsigned char *dest, void *src, int w, int h, int bpp)
{
    int JUNK = (3 * w) % 4;
    uint64* buf = (uint64*) src;
    unsigned int pos_in = w * (h - 1);
    unsigned int dwidth = -(w << 1);
    unsigned int pos_out = 0;
    switch (bpp)
    {
        case 8:
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    dest[pos_out] = buf[pos_in];
                    ++pos_out;
                    ++pos_in;
                }
                pos_in +=dwidth;
                pos_out+=JUNK;
            }
        break;
        case 24:
            wxColour col;
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    col.SetRGB(buf[pos_in]);
                    ++pos_in;
                    dest[pos_out] = col.Blue(); ++pos_out;
                    dest[pos_out] = col.Green(); ++pos_out;
                    dest[pos_out] = col.Red(); ++pos_out;
                }
                pos_in +=dwidth;
                pos_out+=JUNK;
            }
        break;
    }
    return (w+JUNK)*h* (bpp >> 3);
}
