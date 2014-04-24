#ifndef HEXNUM_H_INCLUDED
#define HEXNUM_H_INCLUDED

#include "hexnumdialog.h"
#include <wx/valtext.h>
#include <wx/log.h>

class HexNum : public HexNumberDialog
{
    public:
        HexNum(wxWindow* parent) : HexNumberDialog(parent)
        {
            wxTextValidator valid(wxFILTER_INCLUDE_CHAR_LIST, &mHexString);
            valid.SetCharIncludes("1234567890ABCDEFabcdef");
            textCtrl->SetValidator( valid );
        }

        unsigned long GetNumber()
        {
            unsigned long res = 0xFFFFFFFF;
            mHexString = textCtrl->GetValue();
            if (!mHexString.ToULong(&res, 16))
            {
                wxLogError("Unable to convert number in hexadecimal: %s", mHexString);
            }
            return res;
        }
    private:
        wxString mHexString;
};
#endif // HEXNUM_H_INCLUDED
