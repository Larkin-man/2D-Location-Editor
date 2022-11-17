//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCreate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCreateForm *CreateForm;
//---------------------------------------------------------------------------
__fastcall TCreateForm::TCreateForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCreateForm::BitBtn2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
