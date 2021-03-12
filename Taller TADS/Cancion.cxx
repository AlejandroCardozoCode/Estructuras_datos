#include <iostream>
#include <Cancion.h>

Cancion::Cancion(){

    nombreCancion = "";
    genero = "";
}

std::string Cancion::obtenerNombre(){
    return( nombreCancion);
}
void Cancion::fijarNombre(std::string nombreCancionP){

    this->nombreCancion = nombreCancionP;
}
std::string Cancion::obtenerGenero(){

    return(genero);

}
void Cancion::fijarGenero(std::string nombreGeneroP){

    this->genero = nombreGeneroP;
}