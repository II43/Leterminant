//---------------------------------------------------------------------------


#pragma hdrstop

#include <math.h>

#include "LMat.h"

//---------MATICE------------------------------------------------------------

//---------MATEMATICKE FUNKCE------------------------------------------------

Matice* Matice::AdjugovanaMatice(int js,int jr)
{
  Matice *matT = new Matice(vMatS-1,vMatR-1);
  int is,ir,ks = 0,kr = 0;
  if (js >= vMatS || jr >= vMatR) return NULL;
  for(is=0;is<vMatS-1;is++) {
    if (is == js && ks == 0) ks++;
    kr = 0;
    for(ir=0;ir<vMatR-1;ir++) {
      if (ir == jr && kr == 0) kr++;
      matT->Sp(is,ir,p[is+ks][ir+kr]);
    }
  }
  return matT;
}

Matice* Matice::TransponovanaMatice()
{
  Matice *matT = new Matice(vMatR,vMatS);
  int is,ir;
  for(is=0;is<vMatS;is++) for(ir=0;ir<vMatR;ir++) {
    matT->Sp(ir,is,p[is][ir]);
  }
  return matT;
}

double Matice::Determinant()
{
  double det=0;
  Matice *matAdj;
  int is;
  //Rozvoj determinantu podle 1.radku
  if (vMatS > 1 && vMatR > 1) {
    for (is=0;is<vMatS;is++) {
      if (Rp(is,0) != 0) {
        matAdj = AdjugovanaMatice(is,0);
        det += pow(-1,is)*Rp(is,0)*matAdj->Determinant();
        delete matAdj;
      }
    }
  }
  if (vMatS == 1 && vMatR == 1) return Rp(0,0);
  return det;
}

Matice* Matice::InverzniMatice()
{
  Matice *matInvT = new Matice(vMatR,vMatS);
  Matice *matAdj;
  Matice *matR;
  double detH = Determinant();
  double detAdj,p;
  if (detH != 0) {
    int is,ir;
    for(is=0;is<vMatS;is++) for(ir=0;ir<vMatR;ir++) {
      matAdj = AdjugovanaMatice(is,ir);
      detAdj = matAdj->Determinant();
      p = pow(-1,is)*pow(-1,ir)*detAdj/detH;
      matInvT->Sp(is,ir,p);
      delete matAdj;
    }
    matR = matInvT->TransponovanaMatice();
    return matR;
  }
  return NULL;
}

//---------OBSLUZNE FUNKCE---------------------------------------------------
void Matice::JednotkovaMatice()
{
  int ix,iy;
  for(ix=0;ix<vMatS;ix++) for(iy=0;iy<vMatR;iy++) {
    if (ix == iy) p[ix][iy] = 1;
    else p[ix][iy] = 0;
  }
}

void Matice::DoplnMatici(int nvMatS,int nvMatR,double hod)
{
  int ix,iy;
  for(ix=0;ix<nvMatS;ix++) for(iy=0;iy<nvMatR;iy++) {
    if (ix >= vMatS || iy >= vMatR) {
      p[ix][iy] = hod;
    }
  }
}

void Matice::Matice123()
{
  int ix,iy;
  for(ix=0;ix<vMatS;ix++) for(iy=0;iy<vMatR;iy++) {
    p[ix][iy] = (ix+1)*2+(iy*vMatR);
  }
}

void Matice::NactiMatici(double mat[MAXSLOUPCUMAT][MAXRADEKMAT])
{
  int ix,iy;
  for(ix=0;ix<vMatS;ix++) for(iy=0;iy<vMatR;iy++) {
    p[ix][iy] = mat[ix][iy];
  }
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
