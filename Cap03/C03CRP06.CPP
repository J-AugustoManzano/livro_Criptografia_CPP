// C03CRP06.CPP - POLYBIUS (6 X 6) NUMERICO

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
  string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  int I;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += (strpos(ALFABETO, TEXTO[I]) / 6) + 1 + 48;
    MENSAGEM += (strpos(ALFABETO, TEXTO[I]) % 6) + 1 + 48;
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO)
{
  ostringstream MENSAGEM;
  string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  string DIMENSAO = "123456";
  int I, X, Y;
  for (I = 0; I <= TEXTO.length() - 1; I += 2)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM << ' ';
      I++;
    }
    if (TEXTO[I] >= '1' and TEXTO[I] <= '6')
    {
      X = strpos(DIMENSAO, TEXTO[I]) * 6;
      Y = strpos(DIMENSAO, TEXTO[I + 1]);
      MENSAGEM << ALFABETO[X + Y];
    }
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
