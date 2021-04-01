// C03CRP07.CPP - POLYBIUS (6 X 6) ALFABETICO

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
  string ALFABETO = "DG4AN16RV0THI5EQOW3CKZ7YLJ9UXS2PFB8M";
  string DIMENSAO = "ABCDEF";
  int I;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += DIMENSAO[(strpos(ALFABETO, TEXTO[I]) / 6)];
    MENSAGEM += DIMENSAO[(strpos(ALFABETO, TEXTO[I]) % 6)];
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO)
{
  ostringstream MENSAGEM;
  string ALFABETO = "DG4AN16RV0THI5EQOW3CKZ7YLJ9UXS2PFB8M";
  string DIMENSAO = "ABCDEF";
  int I, X, Y;
  for (I = 0; I <= TEXTO.length() - 1; I += 2)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM << ' ';
      I++;
    }
    X = strpos(DIMENSAO, TEXTO[I]) * 6;
    Y = strpos(DIMENSAO, TEXTO[I + 1]);
      MENSAGEM << ALFABETO[X + Y];
  }
  return MENSAGEM.str();
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
