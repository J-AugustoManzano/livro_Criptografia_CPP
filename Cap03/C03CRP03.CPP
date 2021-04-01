// C03CRP03.CPP - AFFLINE

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
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

int modpos(double DIVIDENDO, double DIVISOR)
{
  return (int)(DIVIDENDO - DIVISOR * floor(DIVIDENDO / DIVISOR));
}

string codMensagem(string TEXTO, int A, int B)
{
  string MENSAGEM;
  int I;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
      TEXTO[I] = ' ';
    if (TEXTO[I] >= 'A' and TEXTO[I] <= 'Z')
      TEXTO[I] = modpos((A * (TEXTO[I] - 65) + B), 26) + 65;
    MENSAGEM += TEXTO[I];
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO, int A, int B)
{
  string MENSAGEM;
  int I;
  int C = imm(A, 26);
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
      TEXTO[I] = ' ';
    if (TEXTO[I] >= 'A' && TEXTO[I] <= 'Z')
      TEXTO[I] = modpos(C * ((TEXTO[I] - 65) - B), 26) + 65;
    MENSAGEM += TEXTO[I];
  }
  return MENSAGEM;
}

int main(void)
{

  string MENS_ORIG, MENS_CIFR, MENS_DECI;

  cout << "CRIPTOGRAFIA" << endl;
  cout << endl;

  cout << "Informe mensagem a ser cifrada ..: ";
  getline(cin, MENS_ORIG);
  transform(MENS_ORIG.begin(), MENS_ORIG.end(), MENS_ORIG.begin(), ::toupper);

  MENS_CIFR = codMensagem(MENS_ORIG, 5, 21);
  MENS_DECI = decMensagem(MENS_CIFR, 5, 21);

  cout << endl;
  cout << "Mensagem original ......: " << MENS_ORIG << endl;
  cout << "Mensagem com cifragem ..: " << MENS_CIFR << endl;
  cout << "Mensagem sem cifragem ..: " << MENS_DECI << endl;

  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();

  return 0;
}
