#include <iostream>
#include <fstream>
#include "quadtree.h"
#include "quadnodo.h"
#include <string>
#include <ctime>
#include <set>
#include <list>
#include <cstdio>
void funcion(QuadNodo<int> *nodo, int cuadroNivel, int posicionX, int posicionY, int **matriz)
{
    QuadNodo<int> *nuevohijoExtIzqVar = nodo->obtenerHijoExtIzq();
    QuadNodo<int> *nuevohijoIzqVar = nodo->obtenerHijoIzq();
    QuadNodo<int> *nuevohijoDerVar = nodo->obtenerHijoDer();
    QuadNodo<int> *nuevohijoExtDerVar = nodo->obtenerhijoExtrDer();
    if (nuevohijoExtIzqVar->obtenerDato() == 2)
    {
        funcion(nuevohijoExtIzqVar, (cuadroNivel / 2), posicionX, posicionY, matriz);
    }
    else
    {
        for (int i = posicionX; i < posicionX + cuadroNivel; i++)
        {
            for (int j = posicionY; j < posicionY + cuadroNivel; j++)
            {
                matriz[i][j] = nuevohijoExtIzqVar->obtenerDato();
            }
        }
    }

    if (nuevohijoIzqVar->obtenerDato() == 2)
    {
        funcion(nuevohijoIzqVar, (cuadroNivel / 2), posicionX, posicionY + (cuadroNivel), matriz);
    }
    else
    {
        for (int i = posicionX; i < posicionX + cuadroNivel; i++)
        {
            for (int j = posicionY + (cuadroNivel); j < posicionY + cuadroNivel * 2; j++)
            {
                matriz[i][j] = nuevohijoIzqVar->obtenerDato();
            }
        }
    }

    if (nuevohijoExtDerVar->obtenerDato() == 2)
    {
        funcion(nuevohijoExtDerVar, (cuadroNivel / 2), posicionX + (cuadroNivel), posicionY, matriz);
    }
    else
    {
        for (int i = posicionX + (cuadroNivel); i < posicionX + cuadroNivel * 2; i++)
        {
            for (int j = posicionY; j < posicionY + cuadroNivel; j++)
            {
                matriz[i][j] = nuevohijoExtDerVar->obtenerDato();
            }
        }
    }

    if (nuevohijoDerVar->obtenerDato() == 2)
    {
        funcion(nuevohijoDerVar, (cuadroNivel / 2), posicionX + (cuadroNivel), posicionY + (cuadroNivel), matriz);
    }
    else
    {
        for (int i = posicionX + (cuadroNivel); i < posicionX + cuadroNivel * 2; i++)
        {
            for (int j = posicionY + (cuadroNivel); j < posicionY + cuadroNivel * 2; j++)
            {
                matriz[i][j] = nuevohijoDerVar->obtenerDato();
            }
        }
    }
}

void escrituraDeArchivo(int **matriz, int ancho, int alto)
{
    std::ofstream archivoNuevo;
    archivoNuevo.open("Imagen_binaria.pbm");
    if (archivoNuevo.is_open())
    {
        archivoNuevo << "P1\n";
        archivoNuevo << ancho << " ";
        archivoNuevo << alto << "\n";
        for (int i = 0; i < ancho; i++)
        {
            for (int j = 0; j < alto; j++)
            {
                archivoNuevo << matriz[i][j];
            }
            archivoNuevo << "\n";
        }

        archivoNuevo.close();
    }
}

int main(int argc, char *argv[])
{
    std::ifstream archivo;
    std::string linea;
    int ancho = 0, tam, alto = 0;
    archivo.open(argv[1]);
    if (archivo.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                archivo >> ancho;
            }
            if (i == 1)
            {
                archivo >> alto;
            }
            if (i == 2)
            {
                archivo >> linea;
            }
        }
        archivo.close();
    }
    Quadtree<int> arbol;
    int **matriz = new int *[ancho];
    for (int i = 0; i < ancho; i++)
    {
        matriz[i] = new int[alto];
    }
    arbol.insertar1(linea);
    funcion(arbol.nodoRaiz(), ancho / 2, 0, 0, matriz);
    escrituraDeArchivo(matriz,ancho,alto);

}
