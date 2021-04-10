#ifndef __ARBOLBINARIOORD_H__
#define __ARBOLBINARIOORD_H__

#include "NodoBinario.h"
#include <iostream>
#include <list>
#include <string>

template< class T >
class ArbolBinarioOrd {
  protected:
    NodoBinario<T>* raiz;
  public:
    ArbolBinarioOrd();
    ~ArbolBinarioOrd();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void imprimirArbol(NodoBinario<T>* nodo, int espacio);
    NodoBinario<T>* nodoRaiz();
};

#include "ArbolBinarioOrd.hxx"

#endif