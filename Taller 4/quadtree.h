#ifndef __QUADTREE_H__
#define __QUADTREE_H__


#include "quadnodo.h"
#include <iostream>
#include <list>
#include <string>

template< class T >
class Quadtree {
  protected:
    QuadNodo<T>* raiz;
  public:
    Quadtree();
    ~Quadtree();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool insertar1(std::string &linesInsertar);
    bool insertar2(std::string &linesInsertar, QuadNodo<T>* nodo);
    bool buscar(T val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void imprimirArbol(QuadNodo<T>* nodo, int espacio);
    QuadNodo<T>* nodoRaiz();
};

#include "quadtree.hxx"

#endif // __QUADTREE_H__