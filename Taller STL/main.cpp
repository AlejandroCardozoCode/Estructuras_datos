//programado por Diego Alejandro Carodozo Rojas para el taller de STL

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <list>

void vector()
{

    std::vector<int> vectorFinal[25];

    for (int i = 0; i < 25; i++)
    {
        vectorFinal->push_back(1 + rand() % 100);
    }

    std::cout << "Impresion en orden del vector" << std::endl;
    for (std::vector<int>::iterator it = vectorFinal->begin(); it != vectorFinal->end(); ++it)
    {

        std::cout << *it << " ";
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Impresion invertida del vector" << std::endl;
    for (std::vector<int>::iterator it = vectorFinal->end() - 1; it != vectorFinal->begin() - 1; --it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vectorFinal->erase(vectorFinal->begin()+4);
    vectorFinal->erase(vectorFinal->begin()+8);
    vectorFinal->insert(vectorFinal->begin() + 15, 1 + rand() % 100);

    std::cout << std::endl;

    std::cout << "Impresion despues de los cambios en el vector" << std::endl;
    for (std::vector<int>::iterator it = vectorFinal->begin(); it != vectorFinal->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}

void deque()
{
    std::deque<int> dequeFinal[30];

    for (int i = 0; i < 15; i++)
    {
        dequeFinal->push_back(1 + rand() % 100);
        dequeFinal->push_front(1 + rand() % 100);
    }

    std::cout << "Impresion en orden del deque" << std::endl;
    for (std::deque<int>::iterator it = dequeFinal->begin(); it != dequeFinal->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Impresion invertida del deque" << std::endl;
    for (std::deque<int>::iterator it = dequeFinal->end() - 1; it != dequeFinal->begin() - 1; --it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    dequeFinal->erase(dequeFinal->begin()+4);
    dequeFinal->erase(dequeFinal->begin()+8);
    dequeFinal->insert(dequeFinal->begin() + 15, 1 + rand() % 100);

    std::cout << std::endl;

    std::cout << "Impresion despues de los cambios en el deque" << std::endl;
    for (std::deque<int>::iterator it = dequeFinal->begin(); it != dequeFinal->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}

void lista()
{
    std::list<int> listaFinal[30];

    for (int i = 0; i < 15; i++)
    {
        listaFinal->push_back(1 + rand() % 100);
        listaFinal->push_front(1 + rand() % 100);
    }

    std::cout << "Impresion en orden del la lista" << std::endl;
    for (std::list<int>::iterator it = listaFinal->begin(); it != listaFinal->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Impresion invertida del la lista" << std::endl;
    for (std::list<int>::reverse_iterator itr = listaFinal->rbegin(); itr != listaFinal->rend(); ++itr)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::list<int>::iterator it = listaFinal->begin();
    std::advance(it,4);
    listaFinal->erase(it);
    it = listaFinal->begin();
    std::advance(it,8);
    listaFinal->erase(it);
    it = listaFinal->begin();
    std::advance(it,15);
    listaFinal->insert(it,1 + rand() % 100 );

    std::cout << std::endl;

    std::cout << "Impresion despues de los cambios en la lista" << std::endl;
    for (std::list<int>::iterator it = listaFinal->begin(); it != listaFinal->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;

    
}

int main(int argc, char *argv[])
{

    vector();
    deque();
    lista();
}