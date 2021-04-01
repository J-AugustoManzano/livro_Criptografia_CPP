// C03CRP08.CPP - DELLA PORTA

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string codMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM;
  string ALFAB01 /* AB */ = "NOPQRSTUVWXYZABCDEFGHIJKLM";
  string ALFAB02 /* CD */ = "ZNOPQRSTUVWXYBCDEFGHIJKLMA";
  string ALFAB03 /* EF */ = "YZNOPQRSTUVWXCDEFGHIJKLMAB";
  string ALFAB04 /* GH */ = "XYZNOPQRSTUVWDEFGHIJKLMABC";
  string ALFAB05 /* IJ */ = "WXYZNOPQRSTUVEFGHIJKLMABCD";
  string ALFAB06 /* KL */ = "VWXYZNOPQRSTUFGHIJKLMABCDE";
  string ALFAB07 /* MN */ = "UVWXYZNOPQRSTGHIJKLMABCDEF";
  string ALFAB08 /* OP */ = "TUVWXYZNOPQRSHIJKLMABCDEFG";
  string ALFAB09 /* QR */ = "STUVWXYZNOPQRIJKLMABCDEFGH";
  string ALFAB10 /* ST */ = "RSTUVWXYZNOPQJKLMABCDEFGHI";
  string ALFAB11 /* UV */ = "QRSTUVWXYZNOPKLMABCDEFGHIJ";
  string ALFAB12 /* WX */ = "PQRSTUVWXYZNOLMABCDEFGHIJK";
  string ALFAB13 /* YZ */ = "OPQRSTUVWXYZNMABCDEFGHIJKL";
  int I, J;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
      TEXTO[I] = ' ';
    if (TEXTO[I] >= 'A' and TEXTO[I] <= 'Z')
    {
      J = I % CHAVE.length();
      if (CHAVE[J] == 'A' or CHAVE[J] == 'B')
        TEXTO[I] = ALFAB01[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'C' or CHAVE[J] == 'D')
        TEXTO[I] = ALFAB02[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'E' or CHAVE[J] == 'F')
        TEXTO[I] = ALFAB03[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'G' or CHAVE[J] == 'H')
        TEXTO[I] = ALFAB04[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'I' or CHAVE[J] == 'J')
        TEXTO[I] = ALFAB05[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'K' or CHAVE[J] == 'L')
        TEXTO[I] = ALFAB06[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'M' or CHAVE[J] == 'N')
        TEXTO[I] = ALFAB07[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'O' or CHAVE[J] == 'P')
        TEXTO[I] = ALFAB08[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'Q' or CHAVE[J] == 'R')
        TEXTO[I] = ALFAB09[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'S' or CHAVE[J] == 'T')
        TEXTO[I] = ALFAB10[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'U' or CHAVE[J] == 'V')
        TEXTO[I] = ALFAB11[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'W' or CHAVE[J] == 'X')
        TEXTO[I] = ALFAB12[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'Y' or CHAVE[J] == 'Z')
        TEXTO[I] = ALFAB13[TEXTO[I] - 65];
    }
    MENSAGEM += TEXTO[I];
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO , string CHAVE)
{
  string MENSAGEM;
  string ALFAB01 /* AB */ = "NOPQRSTUVWXYZABCDEFGHIJKLM";
  string ALFAB02 /* CD */ = "ZNOPQRSTUVWXYBCDEFGHIJKLMA";
  string ALFAB03 /* EF */ = "YZNOPQRSTUVWXCDEFGHIJKLMAB";
  string ALFAB04 /* GH */ = "XYZNOPQRSTUVWDEFGHIJKLMABC";
  string ALFAB05 /* IJ */ = "WXYZNOPQRSTUVEFGHIJKLMABCD";
  string ALFAB06 /* KL */ = "VWXYZNOPQRSTUFGHIJKLMABCDE";
  string ALFAB07 /* MN */ = "UVWXYZNOPQRSTGHIJKLMABCDEF";
  string ALFAB08 /* OP */ = "TUVWXYZNOPQRSHIJKLMABCDEFG";
  string ALFAB09 /* QR */ = "STUVWXYZNOPQRIJKLMABCDEFGH";
  string ALFAB10 /* ST */ = "RSTUVWXYZNOPQJKLMABCDEFGHI";
  string ALFAB11 /* UV */ = "QRSTUVWXYZNOPKLMABCDEFGHIJ";
  string ALFAB12 /* WX */ = "PQRSTUVWXYZNOLMABCDEFGHIJK";
  string ALFAB13 /* YZ */ = "OPQRSTUVWXYZNMABCDEFGHIJKL";
  int I, J;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
      TEXTO[I] = ' ';
    if (TEXTO[I] >= 'A' and TEXTO[I] <= 'Z')
    {
      J = I % CHAVE.length();
      if (CHAVE[J] == 'A' or CHAVE[J] == 'B')
        TEXTO[I] = ALFAB01[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'C' or CHAVE[J] == 'D')
        TEXTO[I] = ALFAB02[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'E' or CHAVE[J] == 'F')
        TEXTO[I] = ALFAB03[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'G' or CHAVE[J] == 'H')
        TEXTO[I] = ALFAB04[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'I' or CHAVE[J] == 'J')
        TEXTO[I] = ALFAB05[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'K' or CHAVE[J] == 'L')
        TEXTO[I] = ALFAB06[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'M' or CHAVE[J] == 'N')
        TEXTO[I] = ALFAB07[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'O' or CHAVE[J] == 'P')
        TEXTO[I] = ALFAB08[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'Q' or CHAVE[J] == 'R')
        TEXTO[I] = ALFAB09[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'S' or CHAVE[J] == 'T')
        TEXTO[I] = ALFAB10[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'U' or CHAVE[J] == 'V')
        TEXTO[I] = ALFAB11[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'W' or CHAVE[J] == 'X')
        TEXTO[I] = ALFAB12[TEXTO[I] - 65]; else
      if (CHAVE[J] == 'Y' or CHAVE[J] == 'Z')
        TEXTO[I] = ALFAB13[TEXTO[I] - 65];
    }
    MENSAGEM += TEXTO[I];
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

  cout << "Informe chave de cifragem .......: ";
  getline(cin, CHAVE);
  transform(CHAVE.begin(), CHAVE.end(), CHAVE.begin(), ::toupper);

  MENS_CIFR = codMensagem(MENS_ORIG, CHAVE);
  MENS_DECI = decMensagem(MENS_CIFR, CHAVE);

  cout << endl;
  cout << "Mensagem original ......: " << MENS_ORIG << endl;
  cout << "Mensagem com cifragem ..: " << MENS_CIFR << endl;
  cout << "Mensagem sem cifragem ..: " << MENS_DECI << endl;

  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();

  return 0;
}
