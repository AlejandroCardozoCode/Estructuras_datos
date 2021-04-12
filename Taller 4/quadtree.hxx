#include "quadtree.h"
#include <queue>
#include <string>
#include <list>
#include <sstream>
template <class T>
Quadtree<T>::Quadtree()
{
  this->raiz = NULL;
}

template <class T>
Quadtree<T>::~Quadtree()
{
  if (this->raiz != NULL)
  {
    delete this->raiz;
    this->raiz = NULL;
  }
}

template <class T>
bool Quadtree<T>::esVacio()
{
  return this->raiz == NULL;
}

template <class T>
T Quadtree<T>::datoRaiz()
{
  return (this->raiz)->obtenerDato();
}

template <class T>
int Quadtree<T>::altura()
{
  if (this->esVacio())
    return -1;
  else
    return (this->raiz)->altura();
}

template <class T>
int Quadtree<T>::tamano()
{
  int tamano = 0;
  if (!this->esVacio())
  {
    std::queue<QuadNodo<T> *> cola;
    cola.push(this->raiz);
    QuadNodo<T> *nodo;
    while (!cola.empty())
    {
      nodo = cola.front();
      cola.pop();
      tamano += 1;
      if (nodo->obtenerHijoIzq() != NULL)
        cola.push(nodo->obtenerHijoIzq());
      if (nodo->obtenerHijoDer() != NULL)
        cola.push(nodo->obtenerHijoDer());
    }
  }
  return tamano;
}
template <class T>
bool Quadtree<T>::insertar1(std::string &lineaInsertar)
{
  std::stringstream varChar;
  varChar << lineaInsertar[0];
  int raizS;
  varChar >> raizS;
  this->raiz = new QuadNodo<int>(raizS);
  lineaInsertar.erase(0,1);
  insertar2(lineaInsertar, raiz);
  return true;
}
template <class T>
bool Quadtree<T>::insertar2(std::string &lineaInsertar, QuadNodo<T>* nodo)
{
  int hijoExtDerVar, hijoExtIzqVar, hijoDerVar, hijoIzqVar;
  std::stringstream varCharhijoExtIzqVar, varCharhijoIzqVar, varCharhijoDerVar, varCharhijoExtDerVar;

  varCharhijoExtIzqVar << lineaInsertar[0];
  varCharhijoIzqVar<< lineaInsertar[1];
  varCharhijoDerVar << lineaInsertar[2];
  varCharhijoExtDerVar << lineaInsertar[3];

  varCharhijoExtIzqVar >> hijoExtIzqVar;
  varCharhijoIzqVar >> hijoIzqVar;
  varCharhijoDerVar >> hijoDerVar;
  varCharhijoExtDerVar >> hijoExtDerVar;

  QuadNodo<int> *nuevohijoExtIzqVar = new QuadNodo<int>(hijoExtIzqVar);
  QuadNodo<int> *nuevohijoIzqVar = new QuadNodo<int>(hijoIzqVar);
  QuadNodo<int> *nuevohijoDerVar = new QuadNodo<int>(hijoDerVar);
  QuadNodo<int> *nuevohijoExtDerVar = new QuadNodo<int>(hijoExtDerVar);

  nodo->fijarHijoExtIzq(nuevohijoExtIzqVar);
  nodo->fijarHijoIzq(nuevohijoIzqVar);
  nodo->fijarHijoDer(nuevohijoDerVar);
  nodo->fijarHijoExtDer(nuevohijoExtDerVar);

  lineaInsertar.erase(0,4);

  if (nodo->obtenerHijoExtIzq()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerHijoExtIzq());
  }

  if (nodo->obtenerHijoIzq()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerHijoIzq());
  }

  if (nodo->obtenerHijoDer()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerHijoDer());
  }

  if (nodo->obtenerhijoExtrDer()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerhijoExtrDer());
  }
  
  return true;
}


template <class T>
bool Quadtree<T>::buscar(T val)
{
  QuadNodo<T> *nodo = this->raiz;
  bool encontrado = false;

  while (nodo != NULL && !encontrado)
  {
    if (val < nodo->obtenerDato())
    {
      nodo = nodo->obtenerHijoIzq();
    }
    else if (val > nodo->obtenerDato())
    {
      nodo = nodo->obtenerHijoDer();
    }
    else
    {
      encontrado = true;
    }
  }

  return encontrado;
}

template <class T>
void Quadtree<T>::preOrden()
{
  if (!this->esVacio())
    (this->raiz)->preOrden();
}

template <class T>
void Quadtree<T>::inOrden()
{
  std::list<T> listaNodos;
  if (!this->esVacio())
    (this->raiz)->inOrden();
  return;
}

template <class T>
void Quadtree<T>::posOrden()
{
  if (!this->esVacio())
    (this->raiz)->posOrden();
}

template <class T>
void Quadtree<T>::nivelOrden()
{
  if (!this->esVacio())
  {
    std::queue<QuadNodo<T> *> cola;
    cola.push(this->raiz);
    QuadNodo<T> *nodo;
    while (!cola.empty())
    {
      nodo = cola.front();
      cola.pop();
      std::cout << nodo->obtenerDato() << " ";
      if (nodo->obtenerHijoIzq() != NULL)
        cola.push(nodo->obtenerHijoIzq());
      if (nodo->obtenerHijoDer() != NULL)
        cola.push(nodo->obtenerHijoDer());
    }
  }
  std::cout << std::endl;
}

template <class T>
void Quadtree<T>::imprimirArbol(QuadNodo<T> *nodo, int espacio)
{
  int c;
  std::string aux;

  if (nodo == NULL)
    return;

  aux = nodo->obtenerDato();
  c = aux.size();
  espacio += 20;
  imprimirArbol(nodo->obtenerHijoDer(), espacio);
  std::cout << std::endl;
  for (int i = 20; i < espacio; i++)
  {

    if (i == espacio - (10 - (c - 1)))
    {

      std::cout << "|";
    }
    if (i > (espacio - (9 - (c - 1))))
    {
      std::cout << "-";
    }
    else
      std::cout << " ";
  }
  if (aux.size() < 0)
    std::cout << ">>" << nodo->obtenerDato() << "|\n";
  else
    std::cout << ">>" << nodo->obtenerDato() << " |\n";
  imprimirArbol(nodo->obtenerHijoIzq(), espacio);
}
template <class T>
QuadNodo<T> *Quadtree<T>::nodoRaiz()
{
  return this->raiz;
}
