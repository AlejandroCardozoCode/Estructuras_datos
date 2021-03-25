#include <iostream>
#include <fstream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"
#include <string>
#include <ctime>
void cargarAVL(std::string archivoL,ArbolBinarioOrd<std::string> &arbolAVL)
{
  std::clock_t init_time = std::clock( );
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
        else if(linea == "E")
          {
            arbolAVL.eliminar(linea1);
          }
      }
      archivo.close();
    }else
    {
      std::cout << "El archivo " << archivoL << " no existe o no puede ser leído." << std::endl;
    }
    std::clock_t end_time = std::clock( );
    double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
    std::cout<< "It took me " << calc_time << " seconds.\n";
    return;
}
void cargarRN(std::string archivoL,ArbolBinarioOrd<std::string> arbolAVL)
{
  
}
  int main(int argc, char *argv[])
  {
    
    ArbolBinarioOrd<std::string> arbolAVL;
    ArbolBinarioOrd<std::string> arbolRN;
    std::string archivo=argv[1];
    cargarAVL(archivo,arbolAVL);
    //cargarRN(archivo,arbolAVL);
    arbolAVL.nivelOrden();
    return 0;
  }