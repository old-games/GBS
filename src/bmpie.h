#ifndef BMPIE_H_INCLUDED
#define BMPIE_H_INCLUDED

#define DEF_BITS 8
typedef struct { //declares BitMap File Header structure
unsigned long bfSize;
unsigned short bfReserved1;
unsigned short bfReserved2;
unsigned long bfOffBits;
} BMFH;

#define DEF_BITS 8

typedef struct { //declares BitMap Info Header structure
unsigned long biSize;
long biWidth;
long biHeight;
unsigned short biPlanes;
unsigned short biBitCount;
unsigned long biCompression;
unsigned long biSizeImage;
unsigned long biXPelsPerMeter;
unsigned long biYPelsPerMeter;
unsigned long biClrUsed;
unsigned long biClrImportant;
} BMIH;

// BMP Import/Export class
class BMPIE
{
    public:
        BMPIE(unsigned char *r, unsigned char *g, unsigned char *b)
        {
            red = r;
            green = g;
            blue = b;
        };
        ~BMPIE() {};
        bool loadBMP(void* dest, wxString name, int chw, int chh, int* bpp);
        bool saveBMP(void* src, wxString name, int width, int height, int bpp);
    private:

        int BUF2BMP(unsigned char *dest, void *src, int w, int h, int bpp);
        void BMP2BUF(void *dest, unsigned char *src, int w, int h, int bpp);

        unsigned char* red;
        unsigned char* green;
        unsigned char* blue;

};

#endif // BMPIE_H_INCLUDED
