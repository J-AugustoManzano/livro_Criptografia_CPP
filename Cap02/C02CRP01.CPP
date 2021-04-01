// C02CRP01.CPP - ATBASH

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string codMensagem(string TEXTO)
{
  string MENSAGEM;
  int I;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
      MENSAGEM += ' ';
    if (TEXTO[I] >= 'A' and TEXTO[I] <= 'Z')
      MENSAGEM += 155 - TEXTO[I];
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO)
{
  string MENSAGEM;
  int I;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
      MENSAGEM += ' ';
    if (TEXTO[I] >= 'A' and TEXTO[I] <= 'Z')
      MENSAGEM += 155 - TEXTO[I];
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
