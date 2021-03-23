#include <iostream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"

int main() {
  int dato;
  std::cout << "dato:";
  std::cin >> dato; 
  NodoBinario<int> nodof;
  nodof.fijarDato(dato);
  ArbolBinarioOrd<int> nuevo ;
  nuevo.insertar(dato);
  std::cout << bool(nuevo.esVacio()) << std::endl;
  return 0;
}