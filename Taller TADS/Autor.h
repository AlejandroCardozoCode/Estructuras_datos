
#include <iostream>
#include <deque>
#include <Album.h>

class Autor {
    protected:
    std::string nombreAutor;
    std::deque <Album> listaAlbum;

    public:
    std::string obtenerNombre();
    void fijarNombre(std::string nombreAutor);
    void agregarAlbum (std::string nombreAlbum);
    
};