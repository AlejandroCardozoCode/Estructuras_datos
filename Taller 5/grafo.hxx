#include "grafo.h"

void Grafo::iniciarMatrix(int filas, int cols)
{
    matrixAristas.resize(filas);
    for (int i = 0; i < filas; ++i)
    {
        matrixAristas[i].resize(cols);
    }
}

void Grafo::agrandarFilaCols()
{
    int nuevoValor = obtenerValorDimencionMatrix() + 1;

    matrixAristas.resize(nuevoValor);
    for (int i = 0; i < nuevoValor; ++i)
    {
        matrixAristas[i].resize(nuevoValor);
    }

    for (int i = obtenerValorDimencionMatrix() - 1; i < obtenerValorDimencionMatrix(); i++)
    {
        for (int j = 0; j < obtenerValorDimencionMatrix(); j++)
        {
            matrixAristas[i][j] = 0;
        }
    }

    for (int i = 0; i < obtenerValorDimencionMatrix(); i++)
    {
        for (int j = obtenerValorDimencionMatrix() - 1; j < obtenerValorDimencionMatrix(); j++)
        {
            matrixAristas[i][j] = 0;
        }
    }
}

int Grafo::obtenerValorDimencionMatrix()
{
    return matrixAristas.size();
}

void Grafo::insertarVertice(Point vertice)
{
    if (!buscarVerticePuntoBooleana(vertice))
    {
        verticesArreglo.push_back(vertice);
        agrandarFilaCols();
    }
}

Point Grafo::buscarVerticePunto(Point verticeBuscar)
{
    Point aux;
    aux.X = -1;
    aux.Y = -1;
    aux.Z = -1;

    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (verticesArreglo[i].X == verticeBuscar.X && verticesArreglo[i].Y == verticeBuscar.Y && verticesArreglo[i].Z == verticeBuscar.Z)
        {
            return verticesArreglo[i];
        }
    }
    return aux;
}

bool Grafo::buscarVerticePuntoBooleana(Point vertice)
{
    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (verticesArreglo[i].X == vertice.X && verticesArreglo[i].Y == vertice.Y && verticesArreglo[i].Z == vertice.Z)
        {
            return true;
        }
    }
    return false;
}

int Grafo::buscarVerticePosicion(Point verticeBuscar)
{
    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (verticesArreglo[i].X == verticeBuscar.X && verticesArreglo[i].Y == verticeBuscar.Y && verticesArreglo[i].Z == verticeBuscar.Z)
        {
            return i;
        }
    }
    return -1;
}

void Grafo::insetarArista(Point puntoInicio, Point puntoFinal, int costo)
{
    int posicionVerticeInicio, posicionVerticeFinal;
    posicionVerticeInicio = buscarVerticePosicion(puntoInicio);
    posicionVerticeFinal = buscarVerticePosicion(puntoFinal);

    if (posicionVerticeFinal != -1 && posicionVerticeInicio != -1)
    {
        if (matrixAristas[posicionVerticeInicio][posicionVerticeFinal] == 0)
        {
            matrixAristas[posicionVerticeInicio][posicionVerticeFinal] = costo;
        }
    }
}

float Grafo::buscarArista(Point puntoInicio, Point puntoFinal)
{
    int posicionVerticeInicio, posicionVerticeFinal;
    float valor;
    posicionVerticeInicio = buscarVerticePosicion(puntoInicio);
    posicionVerticeFinal = buscarVerticePosicion(puntoFinal);

    if (posicionVerticeFinal != -1 && posicionVerticeInicio != -1)
    {
        valor = matrixAristas[posicionVerticeInicio][posicionVerticeFinal];
    }
    return valor;
}

Point Grafo::buscarVerticePorPosicion(int posicion)
{
    typename std::vector<Point>::iterator it = verticesArreglo.begin() + posicion;
    Point aux = *it;
    return aux;
}

int Grafo::obtenerTamanoArregloVectores()
{
    return verticesArreglo.size();
}

void Grafo::imprimirMatrix()
{
    for (int i = 0; i < obtenerValorDimencionMatrix(); i++)
    {
        for (int j = 0; j < obtenerValorDimencionMatrix(); j++)
        {
            std::cout << "|" << matrixAristas[i][j] << "|";
        }
        std::cout << std::endl;
    }
}

std::vector<Point> Grafo::obtenerVector()
{
    return verticesArreglo;
}

std::vector<float> Grafo::encontrarVecinosVertice(Point vertice)
{
    std::vector<float> vecinos;
    int posicionVetice = buscarVerticePosicion(vertice);
    for (int i = 0; i < obtenerValorDimencionMatrix(); i++)
    {
        if (matrixAristas[i][posicionVetice] != 0)
        {
            vecinos.push_back(i);
        }
    }
    return vecinos;
}

void Grafo::imprimirVecinos(Point vertice)
{
    std::vector<float> vecinos = encontrarVecinosVertice(vertice);
    for (int i = 0; i < vecinos.size(); i++)
    {
        std::cout << vecinos[i] << std::endl;
    }
}

Point Grafo::obtenerVerticeOrigen()
{
    return verticesArreglo[0];
}

float Grafo::dijkstra(Point inicio, Point final)
{
    std::vector<float> arregloDistancias;
    std::vector<float> arregloPredecesores;
    std::vector<float> arregloVerticesVisitados;
    std::vector<float> arregloVerticesFuncion;
    int posicionMenorCosto;
    Point verticeMenorDistancia;
    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (i == 0)
        {
            arregloDistancias.push_back(0);
        }
        else
        {
            arregloDistancias.push_back(INFINITY);
        }
    }

    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (i == 0)
        {
            arregloDistancias.push_back(0);
        }
        else
        {
            arregloDistancias.push_back(INFINITY);
        }
    }

    while (!arregloVerticesFuncion.empty())
    {
        
        posicionMenorCosto = buscarPosicionVerticeMenorCosto(arregloDistancias, arregloVerticesFuncion);

        arregloVerticesVisitados.push_back(arregloVerticesFuncion[posicionMenorCosto]);
        arregloVerticesFuncion.erase(arregloVerticesFuncion.begin() + posicionMenorCosto);
        
    }
    return 1;
}

int Grafo::buscarPosicionVerticeMenorCosto(std::vector<float> arregloDistancias, std::vector<float> arregloVerticesFuncion)
{
    float posicionMenor = -1, valorMenor = INFINITY;

    for (int j = 0; j < arregloVerticesFuncion.size(); j++)
    { 
        if (arregloDistancias[arregloVerticesFuncion[j]] < valorMenor)
        {
            posicionMenor = j;
            valorMenor = arregloDistancias[arregloVerticesFuncion[j]];
        }
    }

    return posicionMenor;
}
