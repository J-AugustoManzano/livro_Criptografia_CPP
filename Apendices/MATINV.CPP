#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(void)
{
  int A, B, C, D;
  ofstream ARQTXT;

  ARQTXT.open("MATINV.TXT", ios::trunc);

  cout << "MATRIZ 2x2 E MATRIZ INVERSA" << endl;
  cout << endl;
  cout << "Aguarde processamento do arquivo..." << endl;
  cout << endl;

  for (A = 1; A <= 100; ++A)
    for (B = 1; B <= 100; ++B)
      for (C = 1; C <= 100; ++C)
        for (D = 1; D <= 100; ++D)
          if ((A * D) - (B * C) == 1)
          {
             ARQTXT << "Matriz = ";
             ARQTXT << setw(4) << A << ".";
             ARQTXT << setw(4) << B << ".";
             ARQTXT << setw(4) << C << ".";
             ARQTXT << setw(4) << D << " /// ";
             ARQTXT << "Matriz inversa = ";
             ARQTXT << setw(4) << D << ".";
             ARQTXT << setw(4) << B*(-1) << ".";
             ARQTXT << setw(4) << C*(-1) << ".";
             ARQTXT << setw(4) << A << endl;
             ARQTXT.clear();
          }

  ARQTXT.close();
  cout << "Arquivo gravado." << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
