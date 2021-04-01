// C02CRP12.CPP - NUMERICA TEXTUAL

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

long strpos(const string MENSAGEM, const char CARACTERE)
{
  int I;
  for (I = 0; MENSAGEM[I]; I++)
  {
    if (MENSAGEM[I] == CARACTERE)
      return I;
  }
  return 0;
}

string codMensagem(string NUMERO)
{
  string VALOR;
  string NUMERICO = "0123456789";
  string CIFRADOR = "AWQRCXEZYG";
  int I;
  for (I = 0; I <= NUMERO.length() - 1; I++)
  {
    if (NUMERO[I] == '.')
    {
      VALOR += 'I';
      I++;
    }
    if (NUMERO[I] == ',')
    {
      VALOR += 'K';
      I++;
    }
    if (NUMERO[I] >= '0' and NUMERO[I] <= '9')
      VALOR += CIFRADOR[strpos(NUMERICO, NUMERO[I])];
  }
  return VALOR;
}

string decMensagem(string NUMERO)
{
  string VALOR;
  string NUMERICO = "0123456789";
  string CIFRADOR = "AWQRCXEZYG";
  int I;
  for (I = 0; I <= NUMERO.length() - 1; I++)
  {
    if (NUMERO[I] == 'I')
    {
      VALOR += '.';
      I++;
    }
    if (NUMERO[I] == 'K')
    {
      VALOR += ',';
      I++;
    }
    if (NUMERO[I] >= 'A' and NUMERO[I] <= 'Z')
      VALOR += NUMERICO[strpos(CIFRADOR, NUMERO[I])];
  }
  return VALOR;
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
