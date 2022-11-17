//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCreate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Create *Form_Create;
//---------------------------------------------------------------------------
__fastcall TForm_Create::TForm_Create(TComponent* Owner)
				: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Create::Button_CancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm_Create::FormKeyPress(TObject *Sender, char &Key)
{
	if (Key == 27) Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Create::Button_CreateClick(TObject *Sender)
{
	try
	{
		W = StrToInt(Edit_W->Text);
		H = StrToInt(Edit_H->Text);
		mOK = true;
		Close();
	}
	catch ( ... ) { MessageBox(0, "Возможно только целое число", "Ошибка", MB_OK); }
}
//---------------------------------------------------------------------------
