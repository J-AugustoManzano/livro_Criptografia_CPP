#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int **criaMat(int LINHA, int COLUNA)
{
  int **MATRIZ, LIN;
  MATRIZ = new int*[LINHA];
  for (LIN = 0; LIN <= LINHA - 1; ++LIN)
    MATRIZ[LIN] = new int[COLUNA];
  return(MATRIZ);
}

int **multMat(int L_MAT_A, int L_MAT_B, int C_MAT_A, int C_MAT_B, int **MA, int **MB, int **MC)
{
  int LIN_A, COL_B, LIN_B;
  for (LIN_A = 0; LIN_A <= L_MAT_A - 1; ++LIN_A)
    for (COL_B = 0; COL_B <= C_MAT_B - 1; ++COL_B)
    {
      MC[LIN_A][COL_B] = 0;
      for (LIN_B = 0; LIN_B <= L_MAT_B - 1; LIN_B++)
        MC[LIN_A][COL_B] += MA[LIN_A][LIN_B] * MB[LIN_B][COL_B];
    }
  return(MC);
}

void mostraMat(int LINHA, int COLUNA, int **MATRIZ)
{
  int LIN, COL;
  for (LIN = 0; LIN <= LINHA - 1; ++LIN)
  {
    for(COL = 0; COL <= COLUNA - 1; ++COL)
      cout << setw(5) << MATRIZ[LIN][COL] << " ";
    cout << endl;
  }
}

int **limpaMat(int LINHA, int **MATRIZ)
{
  int LIN;
  for (LIN = 0; LIN <= LINHA - 1; ++LIN)
    delete [] MATRIZ[LIN];
  delete [] MATRIZ;
  return(NULL);
}

int main(void)
{
  int **MAT_A, **MAT_B, **MAT_C;
  int LIN, COL, L_MAT_A, L_MAT_B, C_MAT_A, C_MAT_B;

  cout << "MULTIPLICACAO DE MATRIZES" << endl;
  cout << endl;

  cout << "Entre quantidade de linhas  da Matriz [A] ..: "; cin >> L_MAT_A;
  cout << "Entre quantidade de colunas da Matriz [A] ..: "; cin >> C_MAT_A;
  cout << "Entre quantidade de linhas  da Matriz [B] ..: "; cin >> L_MAT_B;
  cout << "Entre quantidade de colunas da Matriz [B] ..: "; cin >> C_MAT_B;

  if (C_MAT_A != L_MAT_B)
  {
    cout << endl;
    cout << "Coluna da Matriz [A] difere da Linha da Matriz [B]." << endl;
    cout << "Multiplicacao nao possivel." << endl;
  }
  else
    if ((L_MAT_A >= 1 and C_MAT_A >= 1) and (L_MAT_B >= 1 and C_MAT_B >= 1))
    {

      MAT_A = criaMat(L_MAT_A, C_MAT_A);
      MAT_B = criaMat(L_MAT_B, C_MAT_B);
      MAT_C = criaMat(L_MAT_A, C_MAT_B);

      if (MAT_A == NULL or MAT_B == NULL or MAT_C == NULL)
      {
        cout << "Memoria esgotada.";
        exit(1);
      }

      cout << endl;
      cout << "Entrada Matriz [A]" << endl;
      for (LIN = 0; LIN <= L_MAT_A - 1; ++LIN)
        for(COL = 0; COL <= C_MAT_A - 1; ++COL)
        {
          cout << "[" << LIN + 1 << "," << COL + 1 << "] = ";
          cin >> MAT_A[LIN][COL];
        }

      cout << endl;
      cout << "Entrada Matriz [B]" << endl;
      for (LIN = 0; LIN <= L_MAT_A - 1; ++LIN)
        for(COL = 0; COL <= C_MAT_A - 1; ++COL)
        {
          cout << "[" << LIN + 1 << "," << COL + 1 << "] = ";
          cin >> MAT_B[LIN][COL];
        }

      MAT_C = multMat(L_MAT_A, L_MAT_B, C_MAT_A, C_MAT_B, MAT_A, MAT_B, MAT_C);

      cout << endl;
      cout << "Multiplicacao [A] * [B]" << endl;
      mostraMat(L_MAT_A, C_MAT_B, MAT_C);

      MAT_A = limpaMat(L_MAT_A, MAT_A);
      MAT_B = limpaMat(L_MAT_B, MAT_B);
      MAT_C = limpaMat(L_MAT_A, MAT_C);

    }
    else
    {
      cout << endl;
      cout << "Linhas e/ou Colunas menores que 1." << endl;
    }

  cin.ignore(80, '\n');
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
