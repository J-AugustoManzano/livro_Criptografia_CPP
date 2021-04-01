// C02CRP09.CPP - VIGENERE

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string codMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM;
  int I, J = 0;
  for (I = 0; I <= TEXTO.length() - 1; I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += (TEXTO[I] + CHAVE[J] - 2 * 65) % 26 + 'A';
    J = (J + 1) % CHAVE.length();
  }
  return MENSAGEM;
}

string decMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM;
  int I, J = 0;
  for (I = 0; I < TEXTO.length(); I++)
  {
    if (TEXTO[I] == ' ')
    {
      MENSAGEM += ' ';
      I++;
    }
    MENSAGEM += (TEXTO[I] - CHAVE[J] + 26) % 26 + 'A';
    J = (J + 1) % CHAVE.length();
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
