////////NodoTablero///////////
/*
el tad del nodo se define de la siguiente manera, es este esta la variable que contiene la letra del jugador que
giene el siguinete movimiento en la mesa, esta la mesa la cual tiene todas las posiciones de las fichas y un vectyor el cual almacena 
todos los posibles hijos que pueda tener esa mesa
*/
class nodoMesa
{
protected:
  char jugador;
  char mesa[8][8];
  std::vector<nodoMesa> hijos;

public:
  nodoMesa<char> buscar(char mesa[8][8], nodoMesa *nodo);
  int alturaMenor(char turnoJugador);
  bool esHoja();
};
/////////ArbolTableros/////////
/*
el tad del arbol tiene una variable de tipo nodoMesa la cual tiene el nodo de la raiz desde el cual 
se puede acceder a el resto de los datos en el arbol
*/
class arbolMesa
{
protected:
  nodoMesa<char> *raiz;
public:
  bool mismaMesa(char mesaParam[8][8], char mesaNodo[8][8]);
  nodoMesa<char> nodoRaiz();
  int movimientosMinimosGanar(char mesa[8][8]);
  int hojasTotales(nodoMesa *nodo);
  int jugadasTotales(nodoMesa *nodo);
  int promedioCaminos();
};

///////////////////////// Ejercicio 1 /////////////////////////////////
/*
en este codigo se recibe la mesa que se quiere buscar por parametros
despues de eso lo que se hase es empezar desde la raiz del arbol y asi
ir recorriedno todos los nodos en busca de el nodo que tenga la misma mesa
con la funcion de buscar(), la funcion buscar() busca por todos los nodos y va
comparando cada uno de los datos de las matrices hasta que se encunetre la que se
paso por parametro originalmente. despues de eso lo que se hace es calcular la altura
de el nodo encontrado, en la funcion alturaMenor(), lo que se hace es recorresr todos los posibles 
caminos hasta que se legue a una de las hojas y el jugador tenga la posibilidad de hacer el ultimo movimiento
despues de eso se retorna ese valor y asi es como se encuentra el valor del camino mas corto para que el jugador
dado pueda ganar la partida
*/

int movimientosMinimosGanar(char mesa[8][8])
{
  nodoMesa<char> *nuevoNodo = this->nodoRaiz();
  int altura;

  nuevoNodo = buscar(mesa, nuevoNodo);
  altura = nuevoNodo->alturaMenor(nuevoNodo.obtenerJugador());

  return altura;
}

nodoMesa<char> nodoRaiz()
{
  return this->raiz;
}

int alturaMenor(char turnoJugador)
{
  int altura = -1, alturaAux = 0;
  if (this->esHoja())
  {
    altura = 0;
  }
  else
  {
    std::vector<nodoMesa> hijosNodo = this->obtenerHijos();

    for (size_t i = 0; i < hijosNodo.size(); i++)
    {
      if ((hijosNodo != NULL) && (hijosNodo[i].obtenerJugador == turnoJugador))
      {
        alturaAux = hijosNodo[i]->alturaMenor();
      }
      else if (alturaAux < altura)
      {
        altura = alturaAux++;
      }
      else if (alturaAux > altura)
      {
        altura = altura++;
      }
    }
  }
  return altura;
}

bool mismaMesa(char mesaParam[8][8], char mesaNodo[8][8])
{
  bool esIgual = true;
  for (int i = 0; i < 8; i++)
  {
    for (int i = 0; i < 8; i++)
    {
      if (mesaNodo[i][j] != mesaParam[i][j])
      {
        esIgual = false;
      }
    }
  }
  return esIgual;
}

nodoMesa<char> buscar(char mesa[8][8], nodoMesa *nodo)
{
  nodoMesa<char> *nuevoNodo = nodo;
  bool encontrado = false;
  char mesaActual[8][8] = nuevoNodo->obtenerMesa();
  std::vector<nodoMesa> hijosNodo = nuevoNodo->obtenerHijos();

  while (nuevoNodo != NULL && !encontrado)
  {
    if (mismaMesa(mesa, mesaActual))
    {
      encontrado = true;
    }
    else
    {
      for (int i = 0; i < hijosNodo.size(); i++)
      {
        nuevoNodo = buscar(mesa, hijosNodo[i]);
      }
    }
  }

  return nuevoNodo;
}

bool esHoja()
{
  bool esHoja = false;
  if (this->obtenerHijos().size() == 0)
  {
    esHoja = true;
  }

  return esHoja;
}
/////////////////////////// Ejercicio 2 //////////////////////////////////////////////

/*
en esta parte lo que se hace es en la funcion de promedioCaminos() buscar desde el nodo raiz
todos los posibles caminos por medio de al funcion jugadas() la cual es una variacion de la funcion 
de altura, despues se buscan cuantas hojas tiene el arbol en total por medio de la funcion de HojasTotales()
la cual tambien es una variacion de la funcion de altura(), finalmete para calcular el promedio la funcion divide
la cantidad total de jugadas que se pueden hacer por la cantidad total de hojas que puede tener el arbol y retorna ese valor 
*/

int hojasTotales(nodoMesa<char> *nodo)
{
  int hojas;
  if (nodo->esHoja())
  {
    hojas = hojas++;
  }
  std::vector<nodoMesa> hijosNodo = nodo->obtenerHijos();
  for (size_t i = 0; i < hijosNodo.size(); i++)
  {
    hojas = hojasTotales(hijosNodo[i]);
  }
  return hojas;
}


int jugadasTotales(nodoMesa<char> *nodo)
{
  int jugadas;
  if (nodo->esHoja())
  {
    jugadas = 0;
  }
  else
  {
    std::vector<nodoMesa> hijosNodo = nodo->obtenerHijos();

    for (size_t i = 0; i < hijosNodo.size(); i++)
    {
      jugadas = hijosNodo[i]->jugadasTotales(nodo);
      jugadas = jugadas++;
    }
  }
  return jugadas;
}

int promedioCaminos()
{
  nodoMesa<char> * nuevoNodo = this->nodoRaiz();
  int jugadas = jugadasTotales(nuevoNodo);
  int cantidadHojas = hojasTotales(nuevoNodo);
  int promedio = jugadas / cantidadHojas;

  return promedio;
}
