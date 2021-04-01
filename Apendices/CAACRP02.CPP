// CAACRP02.CPP

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

unsigned long myhash(string MENSAGEM)
{
   unsigned HASH = 31, I;
   for (I = 0; I <= MENSAGEM.length() - 1; I++)
     HASH = (HASH * 54059) ^ (MENSAGEM[I] * 76963);
   return HASH;
}

int main(void)
{

  string TEXTO;

  cout << "HASH" << endl;
  cout << endl;

  cout << "Informe mensagem a ser cifrada ..: ";
  getline(cin, TEXTO);

  cout << endl;
  cout << "Hash da mensagem ................: " << myhash(TEXTO) << endl;

  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();

  return 0;
}
