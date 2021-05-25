#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>


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

class Grafo
{
protected:
    std::vector<Point> verticesArreglo;
    std::vector<std::vector<float>> matrixAristas;

public:
    
    void iniciarMatrix(int filas, int cols);
    void agrandarFilaCols();
    int obtenerValorDimencionMatrix();
    void insertarVertice(Point vertice);
    Point buscarVerticePunto(Point verticeBuscar);
    int buscarVerticePosicion(Point verticeBuscar);
    void insetarArista(Point puntoInicio, Point puntoFinal, int costo);
    float buscarArista(Point puntoInicio, Point puntoFinal);
    Point buscarVerticePorPosicion(float posicion);
    int obtenerTamanoArregloVectores();
    void imprimirMatrix();
    bool buscarVerticePuntoBooleana(Point vertice);
    std::vector<Point> obtenerVector();

    //implementacion Dijkstra

    std::vector<float> encontrarVecinosVertice(float vertice);
    void imprimirVecinos(float vertice);
    Point obtenerVerticeOrigen();
    std::vector<Point> dijkstra(Point inicio, Point final);
    float buscarPosicionVerticeMenorCosto(std::vector<float> arregloDistancias, std::vector<float> arregloVerticesFuncion);

};

#include "grafo.hxx"

#endif // __GRAFO_H__