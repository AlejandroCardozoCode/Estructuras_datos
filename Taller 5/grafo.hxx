#include "grafo.h"

void Grafo::iniciarMatrix(int tamano)
{
    matrixAristas.resize(tamano);
    for (int i = 0; i < tamano; ++i)
    {
        matrixAristas[i].resize(tamano);
        for (int j = 0; j < matrixAristas[i].size(); j++)
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
    verticesNoDuplicados.insert(vertice);
}

void Grafo::generarArregloVertices()
{
    verticesArreglo.resize(verticesNoDuplicados.size());
    vecinosArreglo.resize(verticesNoDuplicados.size());
    std::copy(verticesNoDuplicados.begin(), verticesNoDuplicados.end(), verticesArreglo.begin());
    std::reverse(verticesArreglo.begin(), verticesArreglo.end());
}

int Grafo::buscarVerticePosicion(Point verticeBuscar)
{
    /*
    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (verticesArreglo[i].X == verticeBuscar.X && verticesArreglo[i].Y == verticeBuscar.Y && verticesArreglo[i].Z == verticeBuscar.Z)
        {
            return i;
        }
    }
    return -1;

    */
    ///

    std::vector<Point>::iterator it = std::find(verticesArreglo.begin(), verticesArreglo.end(), verticeBuscar);
    if (it != verticesArreglo.end())
    {
        int index = std::distance(verticesArreglo.begin(), it);
        return index;
    }
    else
    {
        return -1;
    }
}

void Grafo::insetarArista(Point puntoInicio, Point puntoFinal, float costo)
{
    int posicionVerticeInicio, posicionVerticeFinal;
    posicionVerticeInicio = buscarVerticePosicion(puntoInicio);
    if (posicionVerticeInicio == -1)
    {
        return;
    }
    posicionVerticeFinal = buscarVerticePosicion(puntoFinal);
    if (posicionVerticeFinal == -1)
    {
        return;
    }

    if (matrixAristas[posicionVerticeInicio][posicionVerticeFinal] == 0)
    {
        matrixAristas[posicionVerticeInicio][posicionVerticeFinal] = costo;
        matrixAristas[posicionVerticeFinal][posicionVerticeInicio] = costo;
        vecinosArreglo[posicionVerticeInicio].push_back(posicionVerticeFinal);
    }
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



std::vector<Point> Grafo::dijkstra(float inicio, float final)
{
    std::vector<float> arregloDistancias;        //dis
    std::vector<float> arregloPredecesores;      //pre
    std::vector<float> arregloVerticesVisitados; //S
    std::vector<float> arregloVerticesFuncion;   //Q
    std::vector<float> vecinosActual;
    std::vector<Point> camino;
    bool caminoEncontrado = false;
    float posicionMenorCosto, posicionPuntoInicial, posicionPuntoFinal;
    Point verticeMenorDistancia;
    posicionPuntoInicial = inicio;
    posicionPuntoFinal = final;

    //vuscar posicion final y inicial mostrarlas en pantalla y parar conun sleeping
    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        arregloVerticesFuncion.push_back(i);
        if (i == posicionPuntoInicial)
        {
            arregloDistancias.push_back(0);
            arregloPredecesores.push_back(0);
        }
        else
        {
            arregloDistancias.push_back(INFINITY);
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
    int nodoActual = 0;
    /*
    for (int i = 0; i < arregloVerticesFuncion.size(); i++)
    {
        vecinosActual = encontrarVecinosVertice(arregloVerticesFuncion[i]);
        std::cout << "el vertice " << i << " tiene " << vecinosActual.size() << " hijos " << std::endl;
        for (int j = 0; j < vecinosActual.size(); j++)
        {
            //std::cout << "el hijo " << i << " tiene el valor " << vecinosActual[j]  << std::endl;
        }
    }*/

    while (!arregloVerticesFuncion.empty())
    {
        /*
        std::cout << "----------------------------------" << std::endl;
        std::cout << "el valor menor es de: " << arregloVerticesFuncion[posicionMenorCosto] << std::endl;
        */
        posicionMenorCosto = buscarPosicionVerticeMenorCosto(arregloDistancias, arregloVerticesFuncion);
        if (posicionMenorCosto != -1)
        {
            arregloVerticesVisitados.push_back(arregloVerticesFuncion[posicionMenorCosto]);
            nodoActual = arregloVerticesFuncion[posicionMenorCosto];
            //obtener vecinos del que esta en
            //std::cout << "se van a buscar lo hijos del nodo " << nodoActual << std::endl;
            vecinosActual = encontrarVecinosVertice(nodoActual);
            //vecinosActual = vecinosArreglo[nodoActual];
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
                if (arregloDistancias[vecinosActual[i]] > (matrixAristas[nodoActual][vecinosActual[i]] + arregloDistancias[nodoActual]))
                {
                    arregloDistancias[vecinosActual[i]] = (matrixAristas[nodoActual][vecinosActual[i]] + arregloDistancias[nodoActual]);
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
        else
        {
            arregloVerticesFuncion.clear();
        }
        //std::cout << "borrando en la posicion " << posicionMenorCosto << " el tamano del arreglo es " << arregloVerticesFuncion.size() << std::endl;
        
    }

    if (arregloDistancias[posicionPuntoFinal] == INFINITY)
    {
        std::cout << "No existe un camino para llegar desde el nodo inicial al nodo final " << std::endl;
        return camino;
    }
    Point aux;
    camino.push_back(buscarVerticePorPosicion(final));
    std::cout << "El costo total es de: " << arregloDistancias[posicionPuntoFinal] << std::endl;
    while (!caminoEncontrado)
    {
        for (int i = 0; i < arregloDistancias.size(); i++)
        {
            //std::cout << "entro aquiiiiii " << i << arregloDistancias.size() <<std::endl;
            if (i == posicionPuntoFinal)
            {
                aux = buscarVerticePorPosicion(arregloPredecesores[i]);
                if (arregloPredecesores[i] == posicionPuntoInicial)
                {
                    camino.push_back(aux);
                    caminoEncontrado = true;
                }
                else
                {
                    camino.push_back(aux);
                    posicionPuntoFinal = arregloPredecesores[i];
                }
            }
        }
    }
    std::reverse(camino.begin(), camino.end());
    std::cout << camino.size() << std::endl;
    return camino;
}


float Grafo::buscarPosicionVerticeMenorCosto(std::vector<float> arregloDistancias, std::vector<float> arregloVerticesFuncion)
{
    float posicionMenor = -1, valorMenor = INFINITY; // si da -1 es por que en q no hay ninguno con distancia menor a infinito

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