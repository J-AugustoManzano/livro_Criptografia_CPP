// C02CRP13.CPP -  NUMERICA TECLADO TELEFONICO

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;

long strpos(const string MENSAGEM, const char CARACTERE)
{
  int I, LETRA;
  for (I = 0; MENSAGEM[I]; I++)
  {
    if (MENSAGEM[I] == CARACTERE)
      return I;
  }
  return 0;
}

int getlet(int LETRA1, int LETRA2)
{
  return LETRA1 + rand() % (LETRA2 + 1 - LETRA1);
}

string codMensagem(string NUMERO)
{
  string VALOR;
  string NUMERICO = "0123456789";
  int I, LETRA;
  srand(time(NULL));
  for (I = 0; I <= NUMERO.length() - 1; I++)
  {
    if (NUMERO[I] == '.')
      VALOR += getlet('U', 'W'), I++;
    if (NUMERO[I] == ',')
      VALOR += getlet('X', 'Z'), I++;
    if (NUMERO[I] >= '0' and NUMERO[I] <= '9')
    {
      switch (strpos(NUMERICO, NUMERO[I]))
      {
         case 0: LETRA = getlet('Q', 'R'); break;
         case 1: LETRA = getlet('S', 'T'); break;
         case 2: LETRA = getlet('A', 'B'); break;
         case 3: LETRA = getlet('C', 'D'); break;
         case 4: LETRA = getlet('E', 'F'); break;
         case 5: LETRA = getlet('G', 'H'); break;
         case 6: LETRA = getlet('I', 'J'); break;
         case 7: LETRA = getlet('K', 'L'); break;
         case 8: LETRA = getlet('M', 'N'); break;
         case 9: LETRA = getlet('O', 'P'); break;
      }
      VALOR += LETRA;
    }
  }
  return VALOR;
}

string decMensagem(string NUMERO)
{
  string VALOR;
  string CIFRADOR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string NUMERICO = "22334455667788990011...,,,";
  int I;
  for (I = 0; I <= NUMERO.length() - 1; I++)
  {
    if (NUMERO[I] == 'U' or NUMERO[I] == 'V' or NUMERO[I] == 'W')
      VALOR += '.', I++;
    if (NUMERO[I] == 'X' or NUMERO[I] == 'Y' or NUMERO[I] == 'Z')
      VALOR += ',', I++;
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
