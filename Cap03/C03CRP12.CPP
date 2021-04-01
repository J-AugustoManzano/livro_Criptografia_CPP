// C03CRP12.CPP - GRONSFELD

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

string codMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM, CHVNR;
  string NUMERICO = "0123456789";
  string ALFABETO = "ABCDEFGHIJ";
  int I, J = 0;
  for (I = 0; I <= CHAVE.length() - 1; I++)
    if (CHAVE[I] >= '0' and CHAVE[I] <= '9')
      CHVNR += ALFABETO[strpos(NUMERICO, CHAVE[I])];
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += (TEXTO[I] + CHVNR[J] - 2 * 65) % 26 + 'A';
    J = (J + 1) % CHVNR.length();
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM, CHVNR;
  string NUMERICO = "0123456789";
  string ALFABETO = "ABCDEFGHIJ";
  int I, J = 0;
  for (I = 0; I <= CHAVE.length() - 1; I++)
    if (CHAVE[I] >= '0' and CHAVE[I] <= '9')
      CHVNR += ALFABETO[strpos(NUMERICO, CHAVE[I])];
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += (TEXTO[I] - CHVNR[J] + 26) % 26 + 'A';
    J = (J + 1) % CHVNR.length();
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
