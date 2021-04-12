#include "quadnodo.h"

template< class T >
QuadNodo<T>::QuadNodo() {
	this->hijoIzq = NULL;
  this->hijoDer = NULL;
}

template< class T >
QuadNodo<T>::QuadNodo(T val) {
	this->hijoIzq = NULL;
  this->hijoDer = NULL;
  this->dato = val;
}

template< class T >
QuadNodo<T>::~QuadNodo() {
	if (this->hijoIzq != NULL) {
    delete this->hijoIzq;
    this->hijoIzq = NULL;
  }
  if (this->hijoDer != NULL) {
    delete this->hijoDer;
    this->hijoDer = NULL;
  }
}

template< class T >
T QuadNodo<T>::obtenerDato() {
	return this->dato;
}

template< class T >
void QuadNodo<T>::fijarDato(T val) {
	this->dato = val;
}

template< class T >
QuadNodo<T>* QuadNodo<T>::obtenerHijoIzq() {
	return this->hijoIzq;
}

template< class T >
QuadNodo<T>* QuadNodo<T>::obtenerHijoDer() {
	return this->hijoDer;
}

template<class T>
QuadNodo<T>* QuadNodo<T>::obtenerHijoExtIzq() 
{
  return this->hijoExtrIzq;
}

template<class T>
QuadNodo<T>* QuadNodo<T>::obtenerhijoExtrDer() 
{
  return this->hijoExtrDer;
}

template< class T >
void QuadNodo<T>::fijarHijoIzq(QuadNodo<T>* izq) {
	this->hijoIzq = izq;
}

template< class T >
void QuadNodo<T>::fijarHijoDer(QuadNodo<T>* der) {
	this->hijoDer = der;
}

template<class T>
void QuadNodo<T>::fijarHijoExtIzq(QuadNodo<T>* extIzq) 
{
  this->hijoExtrIzq = extIzq;
}

template<class T>
void QuadNodo<T>::fijarHijoExtDer(QuadNodo<T>* extDer) 
{
  this->hijoExtrDer = extDer;
}

template< class T >
bool QuadNodo<T>::esHoja() {
  return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template< class T >
int QuadNodo<T>::altura() {
  int valt;

  if (this->esHoja()) {
    valt = 0;
  } else {
    int valt_izq = -1;
    int valt_der = -1;
    if (this->hijoIzq != NULL)
      valt_izq = (this->hijoIzq)->altura();
    if (this->hijoDer != NULL)
      valt_der = (this->hijoDer)->altura();
    if (valt_izq > valt_der)
      valt = valt_izq + 1;
    else
      valt = valt_der + 1;
  }

  return valt;
}

template< class T >
void QuadNodo<T>::inOrden() {
  if (this->hijoIzq != NULL)
    (this->hijoIzq)->inOrden();
  std::cout << this->dato << " ";
  if (this->hijoDer != NULL)
    (this->hijoDer)->inOrden();
}

template< class T >
void QuadNodo<T>::preOrden() {
  std::cout << this->dato << " ";
  if (this->hijoIzq != NULL)
    (this->hijoIzq)->preOrden();
  if (this->hijoDer != NULL)
    (this->hijoDer)->preOrden();
}

template< class T >
void QuadNodo<T>::posOrden() {
  if (this->hijoIzq != NULL)
    (this->hijoIzq)->posOrden();
  if (this->hijoDer != NULL)
    (this->hijoDer)->posOrden();
    
  std::cout << this->dato << " ";
}


