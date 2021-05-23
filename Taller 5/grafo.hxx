#include "grafo.h"

template<class T>
void Grafo<T>::iniciarMatrix(int filas, int cols) 
{
    matrixAristas.resize(filas);
    for (int i = 0; i < filas; ++i)
    {
        matrixAristas[i].resize(cols);
    }
}



template<class T>
void Grafo<T>::agrandarFilaCols() 
{
    int nuevoValor = obtenerValorDimencionMatrix() + 1;

    matrixAristas.resize(nuevoValor);
    for (int i = 0; i < nuevoValor; ++i)
    {
        matrixAristas[i].resize(nuevoValor);
    }

    for (int i = obtenerValorDimencionMatrix()-1; i < obtenerValorDimencionMatrix(); i++)
    {
        for (int j = 0; j < obtenerValorDimencionMatrix(); j++)
        {
            matrixAristas[i][j] = 0;
        }
    }

    for (int i = 0; i < obtenerValorDimencionMatrix(); i++)
    {
        for (int j = obtenerValorDimencionMatrix()-1; j < obtenerValorDimencionMatrix(); j++)
        {
            matrixAristas[i][j] = 0;
        }
    }
}


template<class T>
int Grafo<T>::obtenerValorDimencionMatrix() 
{
    return matrixAristas.size();
}


template<class T>
void Grafo<T>::insertarVertice(T vertice) 
{
    if (!buscarVerticePuntoBooleana(vertice))
    {
        verticesArreglo.push_back(vertice);
        agrandarFilaCols();
    }
}


template<class T>
T Grafo<T>::buscarVerticePunto(T verticeBuscar) 
{
    typename std::vector<T>::iterator it;
    it = find(verticesArreglo.begin(), verticesArreglo.end(), verticeBuscar);
    if (it != verticesArreglo.end())
        return *it;
}


template<class T>
bool Grafo<T>::buscarVerticePuntoBooleana(T vertice) 
{
    typename std::vector<T>::iterator it;
    it = find(verticesArreglo.begin(), verticesArreglo.end(), vertice);
    if (it != verticesArreglo.end())
        return true;
    else
    {
        return false;
    }
}


template<class T>
int Grafo<T>::buscarVerticePosicion(T verticeBuscar) 
{
    typename std::vector<T>::iterator it;
    it = find(verticesArreglo.begin(), verticesArreglo.end(), verticeBuscar);
    int distancia = std::distance(verticesArreglo.begin(), it);
    if (it != verticesArreglo.end())
        return distancia;
    else
        return -1;
}



template<class T>
void Grafo<T>::insetarArista(T puntoInicio, T puntoFinal, int costo) 
{
    int posicionVerticeInicio, posicionVerticeFinal;
    posicionVerticeInicio = buscarVerticePosicion(puntoInicio);
    posicionVerticeFinal = buscarVerticePosicion(puntoFinal);

    if(posicionVerticeFinal != -1 && posicionVerticeInicio != -1 )
    {
        if (matrixAristas[posicionVerticeInicio][posicionVerticeFinal] == 0)
        {
            matrixAristas[posicionVerticeInicio][posicionVerticeFinal] = costo;
        }
    }
}


template<class T>
float Grafo<T>::buscarArista(T puntoInicio, T puntoFinal) 
{
    int posicionVerticeInicio, posicionVerticeFinal;
    posicionVerticeInicio = buscarVerticePosicion(puntoInicio);
    posicionVerticeFinal = buscarVerticePosicion(puntoFinal);

    if(posicionVerticeFinal != -1 && posicionVerticeInicio != -1 )
    {
        return matrixAristas[posicionVerticeInicio][posicionVerticeFinal];
    }
}



template<class T>
T Grafo<T>::buscarVerticePorPosicion(int posicion) 
{
    typename std::vector<T>::iterator it = verticesArreglo.begin() + posicion;
    T aux = *it;
    return aux;
}


template<class T>
int Grafo<T>::obtenerTamanoArregloVectores() 
{
    return verticesArreglo.size();
}


template<class T>
void Grafo<T>::imprimirMatrix() 
{
    for (int i = 0; i < obtenerValorDimencionMatrix(); i++)
    {
        for (int j = 0; j < obtenerValorDimencionMatrix(); j++)
        {
            std::cout << matrixAristas[i][j];
        }
        std::cout << std::endl;
    }
}



