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

// recurrente
template <class T>
int ArbolBinarioOrd<T>::altura()
{
  if (this->esVacio())
    return -1;
  else
    return (this->raiz)->altura();
}

// recurrente
template <class T>
int ArbolBinarioOrd<T>::tamano()
{
}

// iterativa
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

// iterativa
template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val)
{

  NodoBinario<T> *nodo = this->raiz;
  NodoBinario<T> *padre = this->raiz;
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
  if (encontrado && nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() == NULL)
  {
    std::cout << "se encontro el dato" << std::endl;
    std::cout << "el valor del padre es: " << padre->obtenerDato() << std::endl;
    if (val < padre->obtenerDato())
    {
      padre->fijarHijoIzq(NULL);
      delete nodo;
    }
    if (val > padre->obtenerDato())
    {
      padre->fijarHijoDer(NULL);
      delete nodo;
    }
  }

  if (encontrado && (nodo->obtenerHijoDer() == NULL ^ nodo->obtenerHijoIzq() == NULL))
  {
    if (nodo->obtenerHijoIzq() == NULL)
    {
      if (val < padre->obtenerDato())
      {
        padre->fijarHijoIzq(nodo->obtenerHijoDer());
        nodo->fijarHijoIzq(NULL);
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
        nodo->fijarHijoDer(NULL);
        delete nodo;
        return true;
      }
    }

    // comparar con dato en nodo para bajar por izquierda o derecha
    // y para saber si val esta en el arbol

    // si val esta en el arbol
    // verificar situacion de eliminacion:
    // 1. nodo hoja, borrarlo
    // 2. nodo con un solo hijo, usar hijo para reemplazar nodo
    // 3. nodo con dos hijos, usar maximo del subarbol izquierdo
    //    para reemplazar nodo
  }
}

// iterativa
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

// recurrente
template <class T>
void ArbolBinarioOrd<T>::preOrden()
{
}

// recurrente
template <class T>
void ArbolBinarioOrd<T>::inOrden()
{
  if (!this->esVacio())
    (this->raiz)->inOrden();
}

// recurrente
template <class T>
void ArbolBinarioOrd<T>::posOrden()
{
}

// iterativa
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
}

template <class T>
void ArbolBinarioOrd<T>::imprimirArbol(std::string inicio, NodoBinario<T> *node, bool derecho)
{
  if (node != NULL)
  {
    std::cout << inicio;
    std::cout << (derecho ? "\\__ " : "\\__ ");
    std::cout << node->obtenerDato() << std::endl;

    imprimirArbol(inicio + (derecho ? "│   " : "    "), node->obtenerHijoDer(), true);
    imprimirArbol(inicio + (derecho ? "│   " : "    "), node->obtenerHijoIzq(), false);
  }
}

template <class T>
void ArbolBinarioOrd<T>::imprimirArbol()
{
  std::cout << "<------------------Impresion del Arbol------------------>" << std::endl;
  NodoBinario<T> *raiz = this->raiz;
  imprimirArbol("", raiz, false);
}