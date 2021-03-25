#include <iostream>
#include <fstream>
#include <set>

void borrarDatoArbolRN(std::string valor, std::set<std::string>& set)
{
    std::set<std::string>::iterator it ;
    it = set.find(valor);
    if(it != set.end())
        set.erase(it);
    else
        std::cout << "Alerta el valor " << valor <<" que se intenta eliminar no existe en el arbol RN" << std::endl;
    return;
}

void imprimirArbolRN(std::set<std::string>& set)
{
    for (auto& x: set)
    {
        std::cout << x << std::endl;
    }
}

int main(int argc, char *argv[])
{
    /*
    std::fstream archivo;
    archivo.open(argv[1]);
    if (!archivo)
        std::cout << "Alerta no se puedo abrir el archivo" << std::endl;
    
    archivo.close();*/
    std::string dato ;
    std::set<std::string> rojoNegro;
    
    for (int i = 0; i < 10; i++)
    {
       std::cout << "ingrese un dato por favor: " << std::endl;
       std::cin >> dato;
       rojoNegro.insert(dato);
    }

    imprimirArbolRN(rojoNegro);
    borrarDatoArbolRN("293439", rojoNegro );
    std::cout << "--------------------------------" << std::endl;
    imprimirArbolRN(rojoNegro);

}