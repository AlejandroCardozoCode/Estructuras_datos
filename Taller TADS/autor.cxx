#include <iostream>
#include <Album.h>
#include <Cancion.h>
#include <Autor.h>

Autor::Autor(){

    nombreAutor = "";
    std::deque <Album> listaAlbum;
}

std::string Autor::obtenerNombre(){
    return( nombreAutor);
}
void Album::fijarNombre(std::string nombreAutorP){

    this->nombreAlbum = nombreAutorP;
}
void Autor::agregarAlbum (std::string nombreAlbumP){
    std::deque<Album>::iterator itAlbum;
    bool encontrado = false;
    for ( itAlbum = listaAlbum.begin(); itAlbum != listaAlbum.end(); itAlbum++)
    {
        if (itAlbum->obtenerNombre() == nombreAlbumP)
        {
            encontrado = true;
        }
        
    }

    if (!encontrado)
    {
        Album albumNuevo;
        albumNuevo.fijarNombre(nombreAlbumP);
        listaAlbum.push_back(albumNuevo);
    }
    
    return;
};