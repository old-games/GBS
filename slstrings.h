#ifndef SLSTRINGS_H_INCLUDED
#define SLSTRINGS_H_INCLUDED

int UTFtoRUS(wxString in, unsigned char *out);

wxString RUStoUTF(unsigned char *in);

void loadString(wxFile *file, wxString &str);

void saveString (wxFile *file, wxString str);

#endif // SLSTRINGS_H_INCLUDED
