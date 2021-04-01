// C03CRP13.CPP - FRACIONAMENTO TRIFIDA (NUMERICO)

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

string codMensagem(string TEXTO)
{
  string MENSAGEM;
  string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ*";
  string PAG = "111222333111222333111222333";
  string LIN = "111111111222222222333333333";
  string COL = "123123123123123123123123123";
  int I;

  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += PAG[strpos(ALF, TEXTO[I])];
    MENSAGEM += LIN[strpos(ALF, TEXTO[I])];
    MENSAGEM += COL[strpos(ALF, TEXTO[I])];
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO)
{
  string MENSAGEM;
  string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ*";
  int I, CODIGO;
  char P, L, C;
  I = 0;
  while (I <= TEXTO.length() - 1)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    P = TEXTO[I];
    L = TEXTO[I + 1];
    C = TEXTO[I + 2];
    CODIGO = (P - 48) * 100 + (L - 48) * 10 + (C - 48);
    switch (CODIGO)
    {
      case 111: MENSAGEM += ALF[ 0]; break;
      case 112: MENSAGEM += ALF[ 1]; break;
      case 113: MENSAGEM += ALF[ 2]; break;
      case 211: MENSAGEM += ALF[ 3]; break;
      case 212: MENSAGEM += ALF[ 4]; break;
      case 213: MENSAGEM += ALF[ 5]; break;
      case 311: MENSAGEM += ALF[ 6]; break;
      case 312: MENSAGEM += ALF[ 7]; break;
      case 313: MENSAGEM += ALF[ 8]; break;
      case 121: MENSAGEM += ALF[ 9]; break;
      case 122: MENSAGEM += ALF[10]; break;
      case 123: MENSAGEM += ALF[11]; break;
      case 221: MENSAGEM += ALF[12]; break;
      case 222: MENSAGEM += ALF[13]; break;
      case 223: MENSAGEM += ALF[14]; break;
      case 321: MENSAGEM += ALF[15]; break;
      case 322: MENSAGEM += ALF[16]; break;
      case 323: MENSAGEM += ALF[17]; break;
      case 131: MENSAGEM += ALF[18]; break;
      case 132: MENSAGEM += ALF[19]; break;
      case 133: MENSAGEM += ALF[20]; break;
      case 231: MENSAGEM += ALF[21]; break;
      case 232: MENSAGEM += ALF[22]; break;
      case 233: MENSAGEM += ALF[23]; break;
      case 331: MENSAGEM += ALF[24]; break;
      case 332: MENSAGEM += ALF[25]; break;
      case 333: MENSAGEM += ALF[26]; break;
    }
    I += 3;
  }
  return MENSAGEM;
}

int main(void)
{

  string MENS_ORIG, MENS_CIFR, MENS_DECI, CHAVE;

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
