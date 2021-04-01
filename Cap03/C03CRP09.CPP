// C03CRP09.CPP - COLUNA TRANSPOSTA

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string chaveNumSimples(string CHAVE)
{
  string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string RETNR = "";
  int VLR, I, J;
  char *CHVNR;
  VLR = 1;
  CHVNR = new char[CHAVE.length()];
  for (I = 0; I < ALFABETO.length(); I++)
    for (J = 0; J < CHAVE.length(); J++)
      if (CHAVE[J] == ALFABETO[I])
      {
        CHVNR[J] = VLR + 48;
        VLR++;
      }
  RETNR = string(CHVNR);
  delete [] CHVNR;
  return RETNR;
}

string ordChave(string CHAVE)
{
  string CHVNR = "";
  int I, J, X;
  CHVNR = chaveNumSimples(CHAVE);
  for (I = 0; I <= (CHVNR.length() - 1) - 1; I++)
    for (J = I + 1; J <= CHVNR.length() - 1; J++)
      if (CHVNR[I] > CHVNR[J])
      {
        X = CHVNR[I];
        CHVNR[I] = CHVNR[J];
        CHVNR[J] = X;
      }
  return CHVNR;
}

string codMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM = "", CHVNR = "";
  int I, J, CONT, COLUNAS, LINHAS;
  char **TABELA;
  COLUNAS = CHAVE.length();
  LINHAS = TEXTO.length() / COLUNAS;
  if (TEXTO.length() % COLUNAS != 0)
    LINHAS++;
  TABELA = new char*[LINHAS];
  for (J = 0; J <= LINHAS - 1; J++)
    TABELA[J] = new char[COLUNAS];
  CONT = 0;
  for (I = 0; I <= LINHAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
    {
      TABELA[I][J] = TEXTO[CONT];
      CONT++;
    }
  CHVNR = chaveNumSimples(CHAVE);
  CONT = 1;
  while (CONT < COLUNAS + 1)
    for (I = 0; I <= COLUNAS - 1; I++)
      if (CHVNR[I] == (CONT + 48))
      {
        for (J = 0; J <= LINHAS - 1; J++)
          MENSAGEM += TABELA[J][I];
        CONT++;
      }
  for (I = 0; I <= LINHAS - 1; I++)
    delete [] TABELA[I];
  delete [] TABELA;
  return MENSAGEM;
}

string decMensagem(string TEXTO , string CHAVE)
{
  string MENSAGEM = "", CHVNR = "";
  int I, J, CONT, LINHAS, COLUNAS;
  char **TABELA, **TABSAI;
  CHVNR = ordChave(CHAVE);
  CHAVE = chaveNumSimples(CHAVE);
  COLUNAS = CHAVE.length();
  LINHAS = TEXTO.length() / COLUNAS;
  if (TEXTO.length() % COLUNAS != 0)
    LINHAS++;
  TABELA = new char*[LINHAS];
  TABSAI = new char*[LINHAS];
  for (J = 0; J <= LINHAS - 1; J++)
  {
    TABELA[J] = new char[COLUNAS];
    TABSAI[J] = new char[COLUNAS];
  }
  CONT = 0;
  for (J = 0; J <= COLUNAS - 1; J++)
    for (I = 0; I <= LINHAS - 1; I++)
      if (CONT < TEXTO.length())
      {
        TABELA[I][J] = TEXTO[CONT];
        CONT++;
      }
  for (CONT = 0; CONT <= COLUNAS - 1; CONT++)
    for (J = 0; J <= COLUNAS - 1; J++)
      if (CHVNR[CONT] == CHAVE[J])
      {
        for (I = 0; I <= LINHAS - 1; I++)
          TABSAI[I][J] = TABELA[I][CONT];
        break;
      }
  for (I = 0; I <= LINHAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
       MENSAGEM += TABSAI[I][J];
  for (I = 0; I <= LINHAS - 1; I++)
  {
    delete [] TABELA[I];
    delete [] TABSAI[I];
  }
  delete [] TABELA;
  delete [] TABSAI;
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
