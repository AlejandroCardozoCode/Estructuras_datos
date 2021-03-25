#include "ArbolBinarioOrd.h"
#include <queue>

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd()
{
  this->raiz = NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd()
{
  if (this->raiz != NULL)
  {
    delete this->raiz;
    this->raiz = NULL;
  }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio()
{
  return this->raiz == NULL;
}

template <class T>
T ArbolBinarioOrd<T>::datoRaiz()
{
  return (this->raiz)->obtenerDato();
}

template <class T>
int ArbolBinarioOrd<T>::altura()
{
  if (this->esVacio())
    return -1;
  else
    return (this->raiz)->altura();
}

template <class T>
int ArbolBinarioOrd<T>::tamano()
{
  int tamano = 0;
  if (!this->esVacio())
  {
    std::queue<NodoBinario<T> *> cola;
    cola.push(this->raiz);
    NodoBinario<T> *nodo;
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
bool ArbolBinarioOrd<T>::insertar(T val)
{
  NodoBinario<T> *nodo = this->raiz;
  NodoBinario<T> *padre = this->raiz;
  bool insertado = false;
  bool duplicado = false;

  while (nodo != NULL)
  {
    padre = nodo;
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
      duplicado = true;
      break;
    }
  }

  if (!duplicado)
  {
    NodoBinario<T> *nuevo = new NodoBinario<T>(val);
    if (padre == NULL)
    {
      this->raiz = new NodoBinario<T>(val);
      insertado = true;
      return insertado;
    }

    if (val < padre->obtenerDato())
      padre->fijarHijoIzq(nuevo);
    else
      padre->fijarHijoDer(nuevo);
  }
  insertado = true;
  return insertado;
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val)
{
  NodoBinario<T> *nodo = this->raiz;
  NodoBinario<T> *padre = this->raiz;
  NodoBinario<T> *aux, *auxPadre;
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
bool ArbolBinarioOrd<T>::buscar(T val)
{
  NodoBinario<T> *nodo = this->raiz;
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
void ArbolBinarioOrd<T>::preOrden()
{
  if (!this->esVacio())
    (this->raiz)->preOrden();
}

template <class T>
void ArbolBinarioOrd<T>::inOrden()
{
  if (!this->esVacio())
    (this->raiz)->inOrden();
}

template <class T>
void ArbolBinarioOrd<T>::posOrden()
{
  if (!this->esVacio())
    (this->raiz)->posOrden();
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden()
{
  if (!this->esVacio())
  {
    std::queue<NodoBinario<T> *> cola;
    cola.push(this->raiz);
    NodoBinario<T> *nodo;
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
void ArbolBinarioOrd<T>::imprimirArbol(NodoBinario<T> *nodo, int espacio)
{
  if (nodo == NULL)
    return;
  espacio += 10;
  imprimirArbol(nodo->obtenerHijoDer(), espacio);
  std::cout << std::endl;
  for (int i = 10; i < espacio; i++)
  {
    std::cout << " ";
  }
  std::cout << nodo->obtenerDato() << "\n";
  imprimirArbol(nodo->obtenerHijoIzq(), espacio);
}
template <class T>
NodoBinario<T> *ArbolBinarioOrd<T>::nodoRaiz()
{
  return this->raiz;
}
