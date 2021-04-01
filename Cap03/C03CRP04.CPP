// C03CRP04.CPP - SHOKRANIAN

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
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

string codMensagem(string TEXTO)
{
  string MENSAGEM;
  string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string DG1 = "00000000001111111111222222";
  string DG2 = "01234567890123456789012345";
  int I;

  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += DG1[strpos(ALF, TEXTO[I])];
    MENSAGEM += DG2[strpos(ALF, TEXTO[I])];
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO)
{
  string MENSAGEM;
  string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int I, CODIGO;
  char DG1, DG2;
  I = 0;
  while (I <= TEXTO.length() - 1)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    DG1 = TEXTO[I];
    DG2 = TEXTO[I + 1];
    CODIGO = (DG1 - 48) * 10 + (DG2 - 48);
    switch (CODIGO)
    {
      case  0: MENSAGEM += ALF[ 0]; break;
      case  1: MENSAGEM += ALF[ 1]; break;
      case  2: MENSAGEM += ALF[ 2]; break;
      case  3: MENSAGEM += ALF[ 3]; break;
      case  4: MENSAGEM += ALF[ 4]; break;
      case  5: MENSAGEM += ALF[ 5]; break;
      case  6: MENSAGEM += ALF[ 6]; break;
      case  7: MENSAGEM += ALF[ 7]; break;
      case  8: MENSAGEM += ALF[ 8]; break;
      case  9: MENSAGEM += ALF[ 9]; break;
      case 10: MENSAGEM += ALF[10]; break;
      case 11: MENSAGEM += ALF[11]; break;
      case 12: MENSAGEM += ALF[12]; break;
      case 13: MENSAGEM += ALF[13]; break;
      case 14: MENSAGEM += ALF[14]; break;
      case 15: MENSAGEM += ALF[15]; break;
      case 16: MENSAGEM += ALF[16]; break;
      case 17: MENSAGEM += ALF[17]; break;
      case 18: MENSAGEM += ALF[18]; break;
      case 19: MENSAGEM += ALF[19]; break;
      case 20: MENSAGEM += ALF[20]; break;
      case 21: MENSAGEM += ALF[21]; break;
      case 22: MENSAGEM += ALF[22]; break;
      case 23: MENSAGEM += ALF[23]; break;
      case 24: MENSAGEM += ALF[24]; break;
      case 25: MENSAGEM += ALF[25]; break;
    }
    I += 2;
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
