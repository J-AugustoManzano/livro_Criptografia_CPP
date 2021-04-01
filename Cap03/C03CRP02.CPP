// C03CRP02.CPP

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int modpos(double DIVIDENDO, double DIVISOR)
{
  return (int)(DIVIDENDO - DIVISOR * floor(DIVIDENDO / DIVISOR));
}

int main(void)
{

  int VALOR, MODULO;

  cout << "RESTO POSITIVO" << endl;
  cout << endl;

  cout << "Informe valor ............................: ";
  cin >> VALOR;
  cin.ignore(80, '\n');

  cout << "Informe modulo ...........................: ";
  cin >> MODULO;
  cin.ignore(80, '\n');

  cout << endl;
  cout << "Resultado do resto aritmetico simetrico ..: " << VALOR % MODULO << endl;
  cout << "Resultado do resto aritmetico positivo ...: " << modpos(VALOR, MODULO) << endl;

  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
