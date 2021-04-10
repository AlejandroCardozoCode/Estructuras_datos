#include <iostream>
#include <fstream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"
#include "ArbolRN.h"
#include <string>
#include <ctime>
#include <set>
#include <list>
void cargarAVL(std::string archivoL, ArbolBinarioOrd<std::string> &arbolAVL)
{
  std::clock_t init_time = std::clock();
  std::ifstream archivo;
  std::string linea, linea1;
  archivo.open(archivoL);
  if (archivo.is_open())
  {

    while (!archivo.eof())
    {
      archivo >> linea;
      archivo >> linea1;

      if (linea == "A")
      {
        arbolAVL.insertar(linea1);
      }
      else if (linea == "E")
      {
        arbolAVL.eliminar(linea1);
      }
    }
    archivo.close();
  }
  else
  {
    std::cout << "El archivo " << archivoL << " no existe o no puede ser leído." << std::endl;
  }
  std::clock_t end_time = std::clock();
  double calc_time = (end_time - init_time) / double(CLOCKS_PER_SEC);
  std::cout << "El tiempo del arbol avl fue de:  " << calc_time << " seconds.\n";
  return;
}
void cargarRN(std::string archivoL, std::set<std::string> &rojoNegro)
{
  std::clock_t init_time = std::clock();
  std::ifstream archivo;
  std::string linea, linea1;
  archivo.open(archivoL);
  if (archivo.is_open())
  {
    while (!archivo.eof())
    {
      archivo >> linea;
      archivo >> linea1;
      if (linea == "A")
      {
        rojoNegro.insert(linea1);
      }
      else if (linea == "E")
      {
        borrarDatoArbolRN(linea1, rojoNegro);
      }
    }
    archivo.close();
  }
  else
  {
    std::cout << "El archivo " << archivoL << " no existe o no puede ser leído." << std::endl;
  }
  std::clock_t end_time = std::clock();
  double calc_time = (end_time - init_time) / double(CLOCKS_PER_SEC);
  std::cout << "El tiempo del rojo negro fue de:  " << calc_time << " seconds.\n";
  return;
}
int main(int argc, char *argv[])
{
  ArbolBinarioOrd<std::string> arbolAVL;
  std::set<std::string> rojoNegro;
  std::string archivo = argv[1];
  cargarAVL(archivo, arbolAVL);
  cargarRN(archivo, rojoNegro);
  std::cout << std::endl;
  std::cout << "impresion arbol AVL" << std::endl;
  arbolAVL.inOrden();
  std::cout << std::endl;
  std::cout << "impresion arbol RN" << std::endl;
  imprimirArbolRN(rojoNegro);
  std::cout << std::endl;
  return 0;
}