// CAACRP01.CPP

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string myhash(string MENSAGEM)
{
   unsigned long HASH = 0, I;
   stringstream STR_HASH;
   for (I = 0; I <= MENSAGEM.length() - 1; I++)
     HASH = HASH + MENSAGEM[I];
   STR_HASH << setfill('0') << setw(6) << HASH;
   return STR_HASH.str();
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
