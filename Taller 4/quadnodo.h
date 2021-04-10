#ifndef __QUADNODO_H__
#define __QUADNODO_H__

#include <iostream>
#include <string>
#include <list>

template< class T >
class QuadNodo {
  protected:
    T dato;
    QuadNodo<T>* hijoIzq;
    QuadNodo<T>* hijoDer;
    QuadNodo<T>* hijoExtrIzq;
    QuadNodo<T>* hijoExtrDer;
  public:
    QuadNodo();
    QuadNodo(T val);
    ~QuadNodo();
    T obtenerDato();
    void fijarDato(T val);
    QuadNodo<T>* obtenerHijoIzq();
    QuadNodo<T>* obtenerHijoDer();
    QuadNodo<T>* obtenerHijoExtIzq();
    QuadNodo<T>* obtenerhijoExtrDer();
    void fijarHijoIzq(QuadNodo<T>* izq);
    void fijarHijoDer(QuadNodo<T>* der);
    void fijarHijoExtIzq(QuadNodo<T>* extIzq);
    void fijarHijoExtDer(QuadNodo<T>* extDer);
    bool esHoja();
    int altura();
    void inOrden();
    void preOrden();
    void posOrden();
};


#include "quadnodo.hxx"

#endif // __QUADNODO_H__