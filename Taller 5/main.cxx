#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "grafo.h"


struct Point
{
    float X, Y, Z;
    float distanceTo(const Point &b) const
    {
        float x = X - b.X;
        float y = Y - b.Y;
        float z = Z - b.Z;
        return (std::sqrt((x * x) + (y * y) + (z * z)));
    }
};

int main(int argc, char *argv[])
{
    Grafo<int> grafo;
    grafo.insertarVertice(2);
    grafo.insertarVertice(5);
    grafo.insertarVertice(1);
    grafo.insertarVertice(7);
    grafo.insetarArista(2,1,7);
    std::cout << grafo.obtenerTamanoArregloVectores() << std::endl;
    grafo.imprimirMatrix();

    /*
    Grafo<Point> grafo;

    std::ifstream archivo;
    archivo.open(argv[1]);

    if (archivo.is_open())
    {
        long cantidadVertices;
        archivo >> cantidadVertices;
        for (long pId = 0; pId < cantidadVertices; pId++)
        {
            Point pnt;
            archivo >> pnt.X >> pnt.Y >> pnt.Z;

            // TODO 3: g.AddVertex( pnt );
            grafo.insertarVertice(pnt);
        } // rof

        //grafo.imprimirMatrix();
    }
    */
}