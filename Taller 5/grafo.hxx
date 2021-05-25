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

Point Grafo::buscarVerticePorPosicion(float posicion)
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

std::vector<float> Grafo::encontrarVecinosVertice(float vertice)
{
    std::vector<float> vecinos;
    for (int i = 0; i < obtenerValorDimencionMatrix(); i++)
    {
        if (matrixAristas[i][vertice] != 0)
        {
            vecinos.push_back(i);
        }
    }
    return vecinos;
}

void Grafo::imprimirVecinos(float vertice)
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

std::vector<Point> Grafo::dijkstra(Point inicio, Point final)
{
    std::vector<float> arregloDistancias; //dis
    std::vector<float> arregloPredecesores;//pre
    std::vector<float> arregloVerticesVisitados;//S
    std::vector<float> arregloVerticesFuncion;//Q
    std::vector<float> vecinosActual;
    std::vector<Point> camino;
    bool caminoEncontrado = false;
    float posicionMenorCosto, posicionPuntoInicial, posicionPuntoFinal;
    Point verticeMenorDistancia;
    posicionPuntoInicial = buscarVerticePosicion(inicio);
    posicionPuntoFinal = buscarVerticePosicion(final);

    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (i == posicionPuntoInicial)
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
        arregloVerticesFuncion.push_back(i);
    }

    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (i == posicionPuntoInicial)
        {
            arregloPredecesores.push_back(0);
        }
        else
        {
            arregloPredecesores.push_back(INFINITY);
        }
    }
/*
    std::cout << "Distancias: ";
        for (int i = 0; i < arregloDistancias.size(); i++)
        {
            std::cout << arregloDistancias[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Pre: ";
        for (int i = 0; i < arregloPredecesores.size(); i++)
        {
            std::cout << arregloPredecesores[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "S: ";
        for (int i = 0; i < arregloVerticesVisitados.size(); i++)
        {
            std::cout << arregloVerticesVisitados[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Q: ";
        for (int i = 0; i < arregloVerticesFuncion.size(); i++)
        {
            std::cout << arregloVerticesFuncion[i] << " ";
        }
        std::cout << std::endl;
    */

    while (!arregloVerticesFuncion.empty())
    {
        //std::cout << "----------------------------------" << std::endl;
        posicionMenorCosto = buscarPosicionVerticeMenorCosto(arregloDistancias, arregloVerticesFuncion);

        arregloVerticesVisitados.push_back(arregloVerticesFuncion[posicionMenorCosto]);

        //obtener vecinos del que esta en s
        vecinosActual = encontrarVecinosVertice(arregloVerticesFuncion[posicionMenorCosto]);
        // ver si se puede mejorar el costo de distancia para cada vecion

        for (int i = 0; i < vecinosActual.size(); i++)
        {
            /*
            std::cout <<"Vertice " << arregloVerticesFuncion[posicionMenorCosto] 
            << ""  " El costo hasta el vecino " << vecinosActual[i] 
            << " es " << ( matrixAristas[arregloVerticesFuncion[posicionMenorCosto] ][vecinosActual[i]] + arregloDistancias[posicionMenorCosto] ) 
            << " suma de  costo de la matriz en posicion x: " << arregloVerticesFuncion[posicionMenorCosto]  << " y Y: " << vecinosActual[i] 
            << " es de: " << matrixAristas[posicionMenorCosto][vecinosActual[i]] 
            << " y acumulado en el arreglo " << arregloDistancias[arregloVerticesFuncion[posicionMenorCosto]] << std::endl;
*/
            if(arregloDistancias[vecinosActual[i]] > ( matrixAristas[arregloVerticesFuncion[posicionMenorCosto] ][vecinosActual[i]] + arregloDistancias[arregloVerticesFuncion[posicionMenorCosto]] ))
            {
                arregloDistancias[vecinosActual[i]] = ( matrixAristas[arregloVerticesFuncion[posicionMenorCosto] ][vecinosActual[i]] + arregloDistancias[arregloVerticesFuncion[posicionMenorCosto]] );
                arregloPredecesores[vecinosActual[i]] = arregloVerticesFuncion[posicionMenorCosto];
            }
        }

        arregloVerticesFuncion.erase(arregloVerticesFuncion.begin() + posicionMenorCosto);
/*
        std::cout << "Distancias: ";
        for (int i = 0; i < arregloDistancias.size(); i++)
        {
            std::cout << arregloDistancias[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Pre: ";
        for (int i = 0; i < arregloPredecesores.size(); i++)
        {
            std::cout << arregloPredecesores[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "S: ";
        for (int i = 0; i < arregloVerticesVisitados.size(); i++)
        {
            std::cout << arregloVerticesVisitados[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Q: ";
        for (int i = 0; i < arregloVerticesFuncion.size(); i++)
        {
            std::cout << arregloVerticesFuncion[i] << " ";
        }
        std::cout << std::endl;
        */
        
        // si mejora agregar en el vector de predecesores         
    }
    camino.push_back(buscarVerticePorPosicion(posicionPuntoFinal));
    std::cout << "El costo total es de: " << arregloDistancias[posicionPuntoFinal] << std::endl;
    
    while(!caminoEncontrado)
    {
        for (int i = 0; i < arregloDistancias.size(); i++)
        {
            if(i == posicionPuntoFinal)
            {
                if(arregloPredecesores[i] == posicionPuntoInicial)
                {
                    camino.push_back(buscarVerticePorPosicion(arregloPredecesores[i]));
                    caminoEncontrado = true;
                }
                else
                {
                    camino.push_back(buscarVerticePorPosicion(arregloPredecesores[i]));
                    posicionPuntoFinal = arregloPredecesores[i];
                }
            }
        }
    }
    std::reverse(camino.begin(), camino.end());
    return camino;
}

float Grafo::buscarPosicionVerticeMenorCosto(std::vector<float> arregloDistancias, std::vector<float> arregloVerticesFuncion)
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
