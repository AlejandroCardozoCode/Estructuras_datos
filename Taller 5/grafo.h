#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

template< class T >
class Grafo
{
protected:
    std::vector<T> verticesArreglo;
    std::vector<std::vector<float>> matrixAristas;

public:
    
    void iniciarMatrix(int filas, int cols);
    void agrandarFilaCols();
    int obtenerValorDimencionMatrix();
    void insertarVertice(T vertice);
    T buscarVerticePunto(T verticeBuscar);
    int buscarVerticePosicion(T verticeBuscar);
    void insetarArista(T puntoInicio, T puntoFinal, int costo);
    float buscarArista(T puntoInicio, T puntoFinal);
    T buscarVerticePorPosicion(int posicion);
    int obtenerTamanoArregloVectores();
    void imprimirMatrix();
    bool buscarVerticePuntoBooleana(T vertice);

};

#include "grafo.hxx"

#endif // __GRAFO_H__