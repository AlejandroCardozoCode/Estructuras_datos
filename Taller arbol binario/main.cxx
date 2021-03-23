#include <iostream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"

int main() {
  int dato;
  ArbolBinarioOrd<int> nuevo ;
  for (int i = 0; i < 12; i++)
  {
    std::cout << "dato:";
    std::cin >> dato;
    nuevo.insertar(dato);
  }
  std::cout << "el valor de la raiz es: " << nuevo.datoRaiz() << std::endl;
  nuevo.imprimirArbol();
  return 0;
}