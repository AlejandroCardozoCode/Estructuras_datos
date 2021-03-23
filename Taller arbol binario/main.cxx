#include <iostream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"

int main() {
  int dato;
  ArbolBinarioOrd<int> nuevo ;
  for (int i = 0; i < 13; i++)
  {
    std::cout << "dato:";
    std::cin >> dato;
    nuevo.insertar(dato);
  }
  nuevo.imprimirArbol();
  nuevo.eliminar(7);
  nuevo.imprimirArbol();

  return 0;
}