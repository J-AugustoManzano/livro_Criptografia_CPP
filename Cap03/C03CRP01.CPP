// C03CRP01.CPP

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int imm(int A, int M)
{
  int X;
  for (X = 1; X <= M; X++)
  {
    if ((A * X) % M == 1)
      return X;
  }
}

int main(void)
{

  int VALOR, MODULO;

  cout << "INVERSO MULTIPLICATIVO" << endl;
  cout << endl;

  cout << "Informe valor ...: ";
  cin >> VALOR;
  cin.ignore(80, '\n');

  cout << "Informe modulo ..: ";
  cin >> MODULO;
  cin.ignore(80, '\n');

  cout << endl;
  cout << "Resultado .......: " << imm(VALOR, MODULO) << endl;

  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
