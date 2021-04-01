// C02CRP04.CPP - CAESAR

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
      TEXTO[I] = ' ' - 3;
    if (TEXTO[I] >= 'X' and TEXTO[I] <= 'Z')
      TEXTO[I] -= 26;
    MENSAGEM += TEXTO[I] + 3;
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
      TEXTO[I] = ' ' + 3;
    if (TEXTO[I] >= 'A' and TEXTO[I] <= 'C')
      TEXTO[I] += 26;
    MENSAGEM += TEXTO[I] - 3;
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
