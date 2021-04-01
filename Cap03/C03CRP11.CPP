// C03CRP11.CPP - PERMUTACAO SIMPLES

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string chaveNumSimples(string CHAVE)
{
  string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string RETNUM = "";
  int VLR, I, J;
  char *CHVNUM;
  VLR = 1;
  CHVNUM = new char[CHAVE.length()];
  for (I = 0; I < ALFABETO.length(); I++)
    for (J = 0; J < CHAVE.length(); J++)
      if (CHAVE[J] == ALFABETO[I])
      {
        CHVNUM[J] = VLR + 48;
        VLR++;
      }
  RETNUM = string(CHVNUM);
  delete [] CHVNUM;
  return RETNUM;
}

string ordChave(string CHAVE)
{
  string CHVNUM = "";
  int I, J, X;
  CHVNUM = chaveNumSimples(CHAVE);
  for (I = 0; I <= (CHVNUM.length() - 1) - 1; I++)
    for (J = I + 1; J <= CHVNUM.length() - 1; J++)
      if (CHVNUM[I] > CHVNUM[J])
      {
        X = CHVNUM[I];
        CHVNUM[I] = CHVNUM[J];
        CHVNUM[J] = X;
      }
  return CHVNUM;
}

string codMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM = "", CHVNR = "";
  int I, J, LINHAS, COLUNAS, CONT, TOTAL, CTLIN;
  char **TABELA, **TABSAI;
  COLUNAS = CHAVE.length();
  LINHAS = TEXTO.length() / CHAVE.length();
  CHVNR = chaveNumSimples(CHAVE);
  CHAVE = ordChave(CHAVE);
  if (TEXTO.length() % COLUNAS != 0)
    LINHAS++;
  TOTAL = COLUNAS * LINHAS;
  TABELA = new char*[LINHAS];
  TABSAI = new char*[LINHAS];
  for (J = 0; J <= LINHAS - 1; J++)
  {
    TABELA[J] = new char[COLUNAS];
    TABSAI[J] = new char[COLUNAS];
  }
  if (TEXTO.length() < TOTAL)
    for (I = TEXTO.length(); I <= TOTAL - 1; I++)
      TEXTO += '*';
  CONT = 0;
  for (I = 0; I <= LINHAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
    {
      TABELA[I][J] = TEXTO[CONT];
      CONT++;
    }
  for (I = 0; I <= COLUNAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
      if (CHAVE[I] == CHVNR[J])
        for (CTLIN = 0; CTLIN <= LINHAS - 1; CTLIN++)
          TABSAI[CTLIN][I] = TABELA[CTLIN][J];
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

string decMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM = "", CHVNR = "";
  int I, J, LINHAS, COLUNAS, CONT, TOTAL, CTCOL;
  char **TABELA, **TABSAI;
  COLUNAS = CHAVE.length();
  LINHAS = TEXTO.length() / CHAVE.length();
  CHVNR = chaveNumSimples(CHAVE);
  LINHAS = TEXTO.length() / CHAVE.length();
  if (TEXTO.length() % COLUNAS != 0)
    LINHAS++;
  TOTAL = COLUNAS * LINHAS;
  TABELA = new char*[LINHAS];
  TABSAI = new char*[LINHAS];
  for (J = 0; J <= LINHAS - 1; J++)
  {
    TABELA[J] = new char[COLUNAS];
    TABSAI[J] = new char[COLUNAS];
  }
  CONT = 0;
  for (I = 0; I <= LINHAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
    {
      TABELA[I][J] = TEXTO[CONT];
      CONT++;
    }
  for (I = 0; I <= LINHAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
      for (CTCOL = 0; CTCOL <= CHVNR.length() - 1; CTCOL++)
        if (CHVNR[J] == (CTCOL + 1) + 48)
          TABSAI[I][J] = TABELA[I][CTCOL];
  for (I = 0; I <= LINHAS - 1; I++)
    for (J = 0; J <= COLUNAS - 1; J++)
      if (TABSAI[I][J] != '*')
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
