#include <iostream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"
#include <string>

int main()
{
  int nodos;
  int dato;
  ArbolBinarioOrd<int> nuevo;
  
  std::cout <<"ingrese el numero de nodos que quiere meter en el arbol: ";
  std::cin >> nodos;
  for (int i = 0; i < int(nodos); i++)
  {
    std::cout << "dato:";
    std::cin >> dato;
    nuevo.insertar(dato);
  }
  NodoBinario<int> *raiz = nuevo.nodoRaiz();
  system("clear");
  std::cout << "el dato de la raiz es: " << raiz->obtenerDato() ;
  std::cout << "el hijo der : " << raiz->obtenerHijoDer()->obtenerDato();
  std::cout << "el hijo izq : " << raiz->obtenerHijoIzq()->obtenerDato() << std::endl;
  nuevo.imprimirArbolNueva(raiz, 1);
  //nuevo.eliminar(7);
  //nuevo.imprimirArbol();
  /*
  std::cout << "inorden: "<< std::endl;
  nuevo.inOrden();
  std::cout <<std::endl;
  std::cout << "preorden: "<< std::endl;
  nuevo.preOrden();
  std::cout <<std::endl;
  std::cout << "Posorden: "<< std::endl;
  nuevo.posOrden();
  std::cout <<std::endl;
  std::cout << "nivel orden: "<< std::endl;
  nuevo.nivelOrden();
  std::cout <<std::endl;
  std::cout << "tamano: "<< std::endl;
  std::cout << nuevo.tamano() << std::endl;
  */
  return 0;
}