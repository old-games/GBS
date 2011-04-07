#include "wx_pch.h"

#include "slstrings.h"

int UTFtoRUS(wxString in, unsigned char *out)
{
    wxCSConv cs(_("CP1251"));
    if (cs.IsOk()) {
        strcpy((char *) out, in.mb_str(cs));
        return in.Length();
    } else wxMessageBox(_("CP1251"));
    return -1;
};

wxString RUStoUTF(unsigned char *in)
{
    wxCSConv cs(_("CP1251"));
    if (cs.IsOk()) {
        wxString out(in, cs);
        return out;
    } else wxMessageBox(_("CP1251"));
    return _("");
};

void loadString(wxFile *file, wxString &str)
{
    unsigned char *buf= (unsigned char *) malloc(512);
    unsigned long size;
    file->Read(&size, sizeof(size));
    file->Read(buf, size);
    str=RUStoUTF(buf);
    free(buf);
};

void saveString (wxFile *file, wxString str)
{
    unsigned char *buf= (unsigned char *) malloc(512);
    unsigned long size=UTFtoRUS(str, buf)+1;
    buf[size]=0;
    file->Write(&size, sizeof(size));
    file->Write(buf, size);
    free(buf);
};
