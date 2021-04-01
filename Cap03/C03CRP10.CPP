// C03CRP10.CPP - COLUNA MYSZKOWSKI

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int maiorValor(string TEXTOVLR)
{
  int I, VLR;
  VLR = TEXTOVLR[0];
  for (I = 0; I <= TEXTOVLR.length() - 1; I++)
   if (TEXTOVLR[I] > VLR)
     VLR = max((char)VLR, TEXTOVLR[I]);
  return VLR - 48;
}

string chaveNumSequenciada(string CHAVE)
{
  string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", CHVTXT = "";
  int I, J, VLR, CTRL;
  char *CHVNR;
  VLR = 1;
  CHVNR = new char[CHAVE.length()];
  for (I = 0; I < ALFABETO.length(); I++)
  {
    CTRL = 0;
    for (J = 0; J < CHAVE.length(); J++)
      if (CHAVE[J] == ALFABETO[I])
      {
        CHVNR[J] = VLR + 48;
        CTRL++;
      }
    if (CTRL != 0)
      VLR++;
  }
  CHVTXT = string(CHVNR);
  delete [] CHVNR;
  return CHVTXT;
}

string ordChave(string CHAVE)
{
  string CHVNR = "";
  int I, J, X;
  CHVNR = chaveNumSequenciada(CHAVE);
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
  int I, J, LINHAS, COLUNAS, CONT, TOTAL;
  char **TABELA;
  COLUNAS = CHAVE.length();
  LINHAS = TEXTO.length() / COLUNAS;
  CHVNR = chaveNumSequenciada(CHAVE);
  if (TEXTO.length() % COLUNAS != 0)
    LINHAS++;
  TOTAL = COLUNAS * LINHAS;
  TABELA = new char*[LINHAS];
  for (I = 0; I <= LINHAS - 1; I++)
    TABELA[I] = new char[COLUNAS];
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
  for (CONT = 1; CONT < (maiorValor(CHVNR) + 1); CONT++)
    for (I = 0; I <= LINHAS - 1; I++)
      for (J = 0; J < CHVNR.length(); J++)
         if (CHVNR[J] == (CONT + 48))
            MENSAGEM += TABELA[I][J];
  for (I = 0; I <= LINHAS - 1; I++)
    delete [] TABELA[I];
  delete [] TABELA;
  return MENSAGEM;
}

string decMensagem(string TEXTO, string CHAVE)
{
  string MENSAGEM = "", CHVNR = "";
  int I, J, LINHAS, COLUNAS, CONT, TOTAL, CTCHV;
  char **TABELA;
  COLUNAS = CHAVE.length();
  LINHAS = TEXTO.length() / COLUNAS;
  CHVNR = chaveNumSequenciada(CHAVE);
  CHAVE = ordChave(CHAVE);
  if (TEXTO.length() % COLUNAS != 0)
    LINHAS++;
  TOTAL = COLUNAS * LINHAS;
  TABELA = new char*[LINHAS];
  for (J = 0; J <= LINHAS - 1; J++)
    TABELA[J] = new char[COLUNAS];
  CONT = 0;
  for (CTCHV = 1; CTCHV < maiorValor(CHVNR) + 1; CTCHV++)
    for (I = 0; I <= LINHAS - 1; I++)
      for (J = 0; J <= COLUNAS - 1; J++)
        if (CHVNR[J] == (CTCHV + 48))
        {
          TABELA[I][J] = TEXTO[CONT];
          CONT++;
        }
  for (I = 0; I <= LINHAS - 1; I++)
    for (CTCHV = 1; CTCHV <= COLUNAS; CTCHV++)
      if (CHVNR[CTCHV] == CHAVE[CTCHV])
      {
        for (J = 0; J <= COLUNAS - 1; J++)
          if (TABELA[I][J] != '*')
            MENSAGEM += TABELA[I][J];
        break;
      }
  for (I = 0; I <= LINHAS - 1; I++)
    delete [] TABELA[I];
  delete [] TABELA;
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
