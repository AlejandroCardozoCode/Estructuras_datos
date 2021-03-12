#include <iostream>
#include <deque>
#include <Cancion.h>

class Album {
    protected:
    std::string nombreAlbum;
    unsigned int anio;
    std::deque <Cancion> listaCanciones;

    public:
    std::string obtenerNombre();
    void fijarNombre(std::string nombreAlbumP);
    unsigned int obtenerAnio();
    void fijarAño(unsigned int anioP);
    void agregarCancion (std::string nombreCancionP, std::string nombreGeneroP);
    
};