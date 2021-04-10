#include "ArbolRN.h"

void borrarDatoArbolRN(std::string valor, std::set<std::string>& set) 
{
    std::set<std::string>::iterator it ;
    it = set.find(valor);
    if(it != set.end())
        set.erase(it);

    return;
}


void imprimirArbolRN(std::set<std::string>& set) 
{
    for (auto& x: set)
    {
        std::cout << x << " ";
    }
}
