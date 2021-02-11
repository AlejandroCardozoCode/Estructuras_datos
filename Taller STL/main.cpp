//programado por Diego Alejandro Carodozo Rojas

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

void vector()
{

    std::vector<int> vectorFinal[25];

    for (int i = 0; i < 25; i++)
    {
        vectorFinal->push_back(1 + rand() % 10);
    }

    std::cout << "Impresion en orden del vector" << std::endl;
    for (std::vector<int>::iterator it = vectorFinal->begin(); it != vectorFinal->end(); ++it)
    {

        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Impresion invertida del vector" << std::endl;
    for (std::vector<int>::iterator it = vectorFinal->end() - 1; it != vectorFinal->begin() - 1; --it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (std::vector<int>::iterator it = vectorFinal->begin(); it != vectorFinal->end(); ++it)
    {
        auto posicion = it - vectorFinal->begin();

        if (posicion == 5 - 1)
        {
            vectorFinal->erase(it);
        }
        if (posicion == (10 - 2))
        {
            vectorFinal->erase(it);
        }
        if (posicion == (18 - 3))
        {
            vectorFinal->insert(it, 1 + rand() % 10);
        }
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    std::cout << "Impresion despues de los cambios en el vector" << std::endl;
    for (std::vector<int>::iterator it = vectorFinal->begin(); it != vectorFinal->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}

void deque()
{
    std::deque<int> dequeFinal[30];
}

int main(int argc, char *argv[])
{

    vector();
}