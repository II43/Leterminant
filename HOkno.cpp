//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "LMat.h"
#include "HOkno.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  //INICIALIZACE
  Matice *matH = new Matice(3);
  matH->Matice123();
  ZapisMATdoTabulky(matH);
  strEdit1 = "3";
  DecimalSeparator = '.';
  String s;
  s.sprintf("MAX: %d",MAXVMAT);
  Label3->Caption = s;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
  try {
    if (Edit1->Text != strEdit1 && Edit1->Text != "") {
      int n;
      n = Edit1->Text.ToInt();
      if (n > MAXVMAT) {
        n = MAXVMAT;
        String s;
        s.sprintf("%d",n);
        Edit1->Text = s;
      }
      Matice *matH = NactiMATzTabulky();
      matH->DoplnMatici(n,n,0);
      matH->SvMatS(n);
      matH->SvMatR(n);
      ZapisMATdoTabulky(matH);
      StringGrid1->RowCount = n;
      StringGrid1->ColCount = n;
      strEdit1 = Edit1->Text;
    }
  }
  catch(...) {
    Application->MessageBox("Toto neni cele cislo!",NULL,MB_OK);
    Edit1->Text = strEdit1;
  }
}
//---------------------------------------------------------------------------

Matice* __fastcall TForm1::NactiMATzTabulky()
{
  Matice *matT = new Matice(StringGrid1->ColCount,StringGrid1->RowCount);
  String s;
  int is,ir;
  try {
     for(is=0;is<matT->RvMatS();is++) for(ir=0;ir<matT->RvMatR();ir++) {
      matT->Sp(is,ir,StringGrid1->Cells[is][ir].ToDouble());
    }
  }
  catch(...) {
    s.sprintf("Na pozici (%d,%d) neni realne cislo!",is+1,ir+1);
    Application->MessageBox(s.c_str(),NULL,MB_OK);
    return NULL;
  }
  return matT;
}

void __fastcall TForm1::ZapisMATdoTabulky(Matice *matT)
{
  String strHod;
  int is,ir;
  StringGrid1->ColCount = matT->RvMatS();
  StringGrid1->RowCount = matT->RvMatR();
  for(is=0;is<matT->RvMatS();is++) for(ir=0;ir<matT->RvMatR();ir++) {
     strHod = String(matT->Rp(is,ir));
     StringGrid1->Cells[is][ir] = strHod;
  }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  //Transponovana matice
  Matice *matH;
  Matice *matTransp;
  matH = NactiMATzTabulky();
  matTransp = matH->TransponovanaMatice();
  ZapisMATdoTabulky(matTransp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  //Adjugovana matice
  Matice *matH;
  Matice *matAdj;
  matH = NactiMATzTabulky();
  matAdj = matH->AdjugovanaMatice(StringGrid1->Col,StringGrid1->Row);
  ZapisMATdoTabulky(matAdj);
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  //Determinant
  String str;
  double det;
  Matice *matH;
  matH = NactiMATzTabulky();
  det = matH->Determinant();
  str.sprintf("%f",det);
  Edit2->Text = str;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   //Adjugovana matice
  Matice *matH;
  Matice *matInv;
  matH = NactiMATzTabulky();
  matInv = matH->InverzniMatice();
  if (matInv != NULL) ZapisMATdoTabulky(matInv);
  else {
    Application->MessageBox("Matice nelze invertovat - má nulový determinant",NULL,MB_OK);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Matice *matH = new Matice(StringGrid1->ColCount,StringGrid1->RowCount);
  matH->JednotkovaMatice();
  ZapisMATdoTabulky(matH);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Matice *matH = new Matice(StringGrid1->ColCount,StringGrid1->RowCount);
  matH->Matice123();
  ZapisMATdoTabulky(matH);
}
//---------------------------------------------------------------------------






