// C02CRP15.CPP - RAIL FENCE

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string codMensagem(string TEXTO)
{
  string MENSAGEM;
  int I, J;
  for (I = 0; I < 2; I++)
    for (J = I; J <= TEXTO.length() - 1; J += 2)
      MENSAGEM += TEXTO[J];
  return MENSAGEM;
}

string decMensagem(string TEXTO)
{
  string MENSAGEM;
  int I, J, COLUNAS;
  for (I = 0; I < TEXTO.length() / 2; I++)
    for (J = 0; J < TEXTO.length(); J += (TEXTO.length() / 2))
      MENSAGEM += TEXTO[I + J];
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

  MENS_CIFR = codMensagem(MENS_ORIG);
  MENS_DECI = decMensagem(MENS_CIFR);

  cout << endl;
  cout << "Mensagem original ......: " << MENS_ORIG << endl;
  cout << "Mensagem com cifragem ..: " << MENS_CIFR << endl;
  cout << "Mensagem sem cifragem ..: " << MENS_DECI << endl;

  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
