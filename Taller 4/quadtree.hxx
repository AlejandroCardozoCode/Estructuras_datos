#include "quadtree.h"
#include <queue>
#include <string>
#include <list>

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
bool Quadtree<T>::insertar(std::string lineaInsertar)
{
  
}



template <class T>
bool Quadtree<T>::eliminar(T val)
{
  QuadNodo<T> *nodo = this->raiz;
  QuadNodo<T> *padre = this->raiz;
  QuadNodo<T> *aux, *auxPadre;
  bool encontrado = false;
  while (nodo != NULL)
  {
    if (val < nodo->obtenerDato())
    {
      padre = nodo;
      nodo = nodo->obtenerHijoIzq();
    }
    else if (val > nodo->obtenerDato())
    {
      padre = nodo;
      nodo = nodo->obtenerHijoDer();
    }
    else
    {
      encontrado = true;
      break;
    }
  }

  if (!encontrado)
  {
    return false;
  }

  if (encontrado && nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() == NULL)
  {
    if (val < padre->obtenerDato())
    {
      padre->fijarHijoIzq(NULL);
      delete nodo;
      return true;
    }
    if (val > padre->obtenerDato())
    {
      padre->fijarHijoDer(NULL);
      delete nodo;
      return true;
    }
  }

  if (encontrado && (nodo->obtenerHijoDer() == NULL ^ nodo->obtenerHijoIzq() == NULL))
  {
    if (nodo->obtenerHijoIzq() == NULL)
    {
      if (val < padre->obtenerDato())
      {
        padre->fijarHijoIzq(nodo->obtenerHijoDer());
        nodo->fijarHijoDer(NULL);
        delete nodo;
        return true;
      }
      if (val > padre->obtenerDato())
      {
        padre->fijarHijoDer(nodo->obtenerHijoDer());
        nodo->fijarHijoDer(NULL);
        delete nodo;
        return true;
      }
    }

    if (nodo->obtenerHijoDer() == NULL)
    {
      if (val < padre->obtenerDato())
      {
        padre->fijarHijoIzq(nodo->obtenerHijoIzq());
        nodo->fijarHijoIzq(NULL);
        delete nodo;
        return true;
      }
      if (val > padre->obtenerDato())
      {
        padre->fijarHijoDer(nodo->obtenerHijoIzq());
        nodo->fijarHijoIzq(NULL);
        delete nodo;
        return true;
      }
    }
  }
  if (encontrado && nodo->obtenerHijoDer() != NULL && nodo->obtenerHijoIzq() != NULL)
  {
    aux = nodo->obtenerHijoIzq();
    if (nodo->obtenerHijoIzq()->obtenerHijoDer() == NULL)
    {
      while (true)
      {
        auxPadre = aux;
        if (aux->obtenerHijoDer() == NULL || aux->esHoja())
        {
          break;
        }

        aux = aux->obtenerHijoDer();
      }
    }
    else
    {
      while (true)
      {
        if (aux->obtenerHijoDer() == NULL || aux->esHoja())
        {
          break;
        }
        auxPadre = aux;
        aux = aux->obtenerHijoDer();
      }
    }
    nodo->fijarDato(aux->obtenerDato());
    if (nodo->obtenerDato() == auxPadre->obtenerDato())
    {
      nodo->fijarHijoIzq(aux->obtenerHijoIzq());
      aux->fijarHijoIzq(NULL);
      aux->fijarHijoDer(NULL);
      delete aux;
      return true;
    }
    else
    {
      auxPadre->fijarHijoDer(NULL);
      aux->fijarHijoIzq(NULL);
      aux->fijarHijoDer(NULL);
      delete aux;
      return true;
    }
  }
  return false;
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
