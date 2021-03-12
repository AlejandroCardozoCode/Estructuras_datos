
#include <iostream>

class Cancion {
    protected:
    std::string nombreCancion;
    std::string genero;

    public:
    std::string obtenerNombre();
    void fijarNombre(std::string nombreCancionP);
    std::string obtenerGenero();
    void fijarGenero(std::string nombreGeneroP);
    
};