//---------------------------------------------------------------------------
#ifndef LMatH
#define LMatH

//-------DEFINICE MATICE-----------------------------------------------------
# define MAXVMAT 50
# define MAXRADEKMAT 50
# define MAXSLOUPCUMAT 50

class Matice {
private:
  //MATEMATICKE FUNKCE
public:
  int vMatR;                                                    //pocet radek matice
  int vMatS;                                                    //pocet sloupcu matice
  double p[MAXSLOUPCUMAT][MAXRADEKMAT];                         //prvky matice
  // KONSTRUKTORY A (RETURN,SET) FUNKCE
  Matice(int vM)                   {vMatS = vM; vMatR = vM;}
  Matice(int vMS,int vMR)          {vMatS = vMS; vMatR = vMR;}
  int RvMatS()                     {return vMatS;}
  void SvMatS(int s)               {vMatS = s;}
  int RvMatR()                     {return vMatR;}
  void SvMatR(int r)               {vMatR = r;}
  double Rp(int s,int r)           {return p[s][r];}
  void Sp(int s,int r,double hod)  {p[s][r] = hod;}
  //MATEMATICKE FUNKCE
  Matice* AdjugovanaMatice(int js,int jr);                      //vraci adjugovanou matici k prvku (js,jr)
  Matice* TransponovanaMatice();                                //vraci transponovanou matici
  double Determinant();                                         //vraci determinant matice
  Matice* InverzniMatice();
  //OBSLUZNE FUNKCE
  void JednotkovaMatice();                                      //udela z matice jednotkovou matici
  void DoplnMatici(int nvMatS,int nvMatR,double hod);
  void Matice123();

  void NactiMatici(double mat[MAXSLOUPCUMAT][MAXRADEKMAT]);     //nacte matici
};

//-------DEFINICE POLYNOMU-----------------------------------------------------
#define MAXVPOLYNOM
class CPolynom {
private:
  int vP;
  double an[MAXVPOLYNOM];
public:
  double NajdiREMinimum();
  //double NajdiIMMinimum();
};
//---------------------------------------------------------------------------
#endif
