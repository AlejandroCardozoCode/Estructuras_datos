#include <iostream>
#include <iomanip>
#include <fstream>
#include<stdio.h>
#include<string.h>
#include <Autor.h>
#include <Cancion.h>
#include <Album.h>


int main()
{
    Autor autorM;
    Cancion cancionM;
    Album albumM;
    int sum = 0;
    int x;
    std::ifstream archivo;

    archivo.open("example1.txt");
    if (!archivo)
    {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    // delcaracion de variables que se van a leer del archivo
    std::string lineaActual;
    char currentChar = ' ';
    int contadorPalabra = 0;
    std::string nombreCancion = "";
    std::string nombreAutor = "";
    std::string genero = "";
    std::string album = "";
    std::string anioStrign = "";
    int anio = 0;
    std::string aux = "";
    // se accede a la primera linea del alrchivo para que no interrumpa en la lectura de las otras lineas
    std::getline(archivo, lineaActual);
    // se accede a las lineas que contienen informacion a guardar
    while (std::getline(archivo, lineaActual))
    {
        for(int i = 0; i < lineaActual.size(); ++i) {

            if (lineaActual[i] == '|')
            {
                contadorPalabra++;
            }
            
            else if (lineaActual[i] != '|' && contadorPalabra == 0)
            {
                nombreCancion = nombreCancion + lineaActual[i];
            }

            else if (lineaActual[i] != '|' && contadorPalabra == 1)
            {
                nombreAutor = nombreAutor + lineaActual[i];
            }

            else if (lineaActual[i] != '|' && contadorPalabra == 2)
            {
                genero = genero + lineaActual[i];
            }

            else if (lineaActual[i] != '|' && contadorPalabra == 3)
            {
                album = album + lineaActual[i];
            }

            else if (lineaActual[i] != '|' && contadorPalabra == 4)
            {
                anioStrign = anioStrign + lineaActual[i];
            }
            
        }

        std::cout<<nombreCancion<<nombreAutor<<album<<genero<<anioStrign<<std::endl;
        

        // se reinician las variables
        nombreCancion = "";
        nombreAutor = "";
        genero = "";
        album = "";
        anioStrign = "";
        contadorPalabra = 0;
        
    }

    return 0;
}