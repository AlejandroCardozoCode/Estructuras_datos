#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <set>
#include <unistd.h>

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

    bool operator<(const Point &other) const
    {
        if (X < other.X || Y == other.Y || Z == other.Z)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const Point &other) const
    {
        if (X == other.X && Y == other.Y && Z == other.Z)
            return true;
        else
        {
            return  false;
        }
    }
};

class Grafo
{
protected:
    std::vector<Point> verticesArreglo;
    std::set<Point> verticesNoDuplicados;
    std::vector<std::vector<float>> matrixAristas;
    std::vector<std::vector<float>> vecinosArreglo;

public:
    void generarArregloVertices();
    void iniciarMatrix(int tamano);
    int obtenerValorDimencionMatrix();
    void insertarVertice(Point vertice);
    int buscarVerticePosicion(Point verticeBuscar);
    void insetarArista(Point puntoInicio, Point puntoFinal, float costo);
    Point buscarVerticePorPosicion(float posicion);
    int obtenerTamanoArregloVectores();
    //void imprimirMatrix();
    //void imprimirVertices();
    //std::vector<std::vector<float>>  obtenerMatrix();
    //std::vector<Point> obtenerVector();

    //implementacion Dijkstra

    std::vector<float> encontrarVecinosVertice(float vertice);
    //void imprimirVecinos(float vertice);
    std::vector<Point> dijkstra(float inicio, float final);
    float buscarPosicionVerticeMenorCosto(std::vector<float> arregloDistancias, std::vector<float> arregloVerticesFuncion);
};

#include "grafo.hxx"

#endif // __GRAFO_H__