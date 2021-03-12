#include <iostream>
#include <Album.h>
#include <Cancion.h>

Album::Album(){

    nombreAlbum = "";
    anio = 0;
    std::deque <Cancion> listaCanciones;
}

std::string Album::obtenerNombre(){
    return( nombreAlbum);
}
void Album::fijarNombre(std::string nombreAlbumP){

    this->nombreAlbum = nombreAlbumP;
}
unsigned int Album::obtenerAnio(){

    return(anio);

}
void Album::fijarAño(unsigned int  anioP){

    this->anio = anioP;
}

void Album::agregarCancion (std::string nombreCancionP, std::string nombreGeneroP){
    std::deque<Cancion>::iterator itCancion;
    bool encontrado = false;
    for ( itCancion = listaCanciones.begin(); itCancion != listaCanciones.end(); itCancion++)
    {
        if (itCancion->obtenerNombre() == nombreCancionP)
        {
            encontrado = true;
        }
        
    }

    if (!encontrado)
    {
        Cancion cancionNuevo;
        cancionNuevo.fijarNombre(nombreCancionP);
        cancionNuevo.fijarGenero(nombreGeneroP);
        listaCanciones.push_back(cancionNuevo);
    }
    
    return;
};