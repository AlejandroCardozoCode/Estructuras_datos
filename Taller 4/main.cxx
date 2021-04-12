#include <iostream>
#include <fstream>
#include "quadtree.h"
#include "quadnodo.h"
#include <string>
#include <ctime>
#include <set>
#include <list>

std::string reordenarCadena (std::string cadena)
{
    int posicionDos = 0;
    std::string nuevoS = "", aux;
    while (cadena.size() > 1)
    {
        for (int i = 0; i <= cadena.size(); i++)
        {
            if ((cadena[i] == '2') && (cadena.size()- (i+1) >= 4))
            {
                posicionDos = i;
            }
        }

        aux = cadena.substr(posicionDos + 1, 4);
        nuevoS =  aux + nuevoS;
        cadena.erase(posicionDos + 1, 4);
    }
    nuevoS =  "2" + nuevoS;

    return nuevoS;
}

int main(int argc, char *argv[])
{
    Quadtree<int> arbol;
    std::string v = "202002100012102001001";
    std::string cadena;
    

    /*202210021100010200010
    

                     2
    0             2            2               1
                0021           1020
                1000            0010*/
    
    cadena = reordenarCadena(v);
    arbol.insertar1(cadena);
    arbol.imprimirArbol(arbol.nodoRaiz(), 1);
    return 0;
}
