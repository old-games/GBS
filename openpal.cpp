#include "wx_pch.h"
#include "openpal.h"
#include "slstrings.h"

enum AlphaPos
{
	NoAlpha,
	AlphaFirst,
	AlphaLast,
	AlphaNum
};

static const wxString ALPHA_CHOICES[AlphaNum] =
{
	"No alpha",
	"Alpha first (ARGB)",
	"Alpha last (RGBA)"
};


PalDialog::PalDialog(wxWindow* parent) : OpenPaletteDialog(parent)
{
	mFileName = "";
	mAlphaChoice->Set(AlphaNum, ALPHA_CHOICES);
	mAlphaChoice->SetSelection(NoAlpha);
}

PalDialog::~PalDialog()
{

}

void PalDialog::FileChanged( wxFileDirPickerEvent& event )
{
	wxFile file;
	file.Open(palPicker->GetPath(), wxFile::read);
	offsetCtrl->SetRange(0, file.Length()-3);
	file.Close();
}

void PalDialog::OKPressed( wxCommandEvent& event )
{
	wxFile file;
	if (palPicker->GetPath().IsEmpty() || !file.Open(palPicker->GetPath(), wxFile::read))
	{
		return;
	}

	file.Seek(offsetCtrl->GetValue(), wxFromStart);
	AlphaPos alpha = (AlphaPos) mAlphaChoice->GetSelection();
	bool rgb = RGBBtn->GetValue();

	for (int i = 0; i < 256; i ++)
	{
		if (alpha == AlphaFirst)
		{
			file.Seek(1, wxFromCurrent);
		}

		int offset = i * 3;

		if (rgb)
		{
			file.Read((mPalBuf + offset), 3);
		}
		else
		{
			file.Read((mPalBuf + offset + 2), 1);
			file.Read((mPalBuf + offset + 1), 1);
			file.Read((mPalBuf + offset), 1);
		}

		if (alpha == AlphaLast)
		{
			file.Seek(1, wxFromCurrent);
		}
	}

	if (shlCheck->IsChecked())
		for (int i = 0; i<768; i++)
			mPalBuf[i]<<=2;
	file.Close();
	mFileName = palPicker->GetPath();
	event.Skip();
}

void PalDialog::SaveState(wxFile* tmp)
{
	saveString(tmp, mFileName);
	unsigned int val;
	val = (unsigned int) RGBBtn->GetValue();
	tmp->Write(&val, 4);
	val = (unsigned int) mAlphaChoice->GetSelection();
	tmp->Write(&val, 4);
	val = (unsigned int) shlCheck->IsChecked();
	tmp->Write(&val, 4);
}

void PalDialog::LoadState(wxFile* tmp)
{
	tmp->Read(mPalBuf, 768);
	loadString(tmp, mFileName);
	palPicker->SetPath(mFileName);
	uint val;
	tmp->Read(&val, 4);
	RGBBtn->SetValue((bool) val);
	BGRBtn->SetValue(!((bool) val));
	tmp->Read(&val, 4);
	mAlphaChoice->SetSelection(val);
	tmp->Read(&val, 4);
	shlCheck->SetValue((bool) val);
}
