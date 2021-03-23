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
  std::cout << "el valor de la raiz es: " << nuevo.datoRaiz() << std::endl;
  nuevo.imprimirArbol();
  nuevo.eliminar(15);
  nuevo.imprimirArbol();

  return 0;
}