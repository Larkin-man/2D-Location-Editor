//---------------------------------------------------------------------------

#ifndef FormCreateH
#define FormCreateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCreateForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TUpDown *H;
	TUpDown *W;
	void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCreateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreateForm *CreateForm;
//---------------------------------------------------------------------------
#endif
