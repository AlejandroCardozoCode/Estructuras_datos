//arreglo de pendas 

Prenda arregloPrendas[cantidadPrendas];

//arreglo de los datos del insumo

DatosInsumos arregloInsumosTotales[cantidadInsumosTotales];

//estructura de prenda

struct Prenda
{
    string nombre;
    int valor;
    int cantidadInsumos;
    float arregloInsumos[cantidadInsumos];
};

//estructura de los datos del insumo

struct DatosInsumos
{
    int codigo;
    string nombre;
    string unidadMedida;
    int valorUnidad;
}

//estructura de la prenda mas costosa de fabricar

struct PrendaMasCostosa
{
    string nombre;
    int costo;
}



PrendaMasCostosa encontrarPrendaMasCostosaFabricar(Prenda arregloPrendas[], DatosInsumos arregloInsumosTotales[])
{
    string nombrePrendaAux, nombrePrendaActual, valorFinal;
    int totalInsumosMayor = 0, totalInsumosActual = 0, cantidadInsumo = 0, codigoInsumo = 0;
    PrendaMasCostosa prenda;

    for (int i = 0; i < cantidadPrendas; i++)
    {
        nombrePrendaActual = arregloPrendas[i].nombre;

        for (int j = 0; j < cantidadInsumo; j = j+2)
        {   
            codigoInsumo = arregloPrendas[i].arregloInsumos[j];
            cantidadInsumo = arregloPrendas[i].arregloInsumos[j+1];

            for (int k = 0; k < cantidadInsumosTotales; k++)
            {
                if (arregloInsumosTotales[k].codigo == codigoInsumo)
                {
                    totalInsumosActual = totalInsumosActual + (cantidadInsumo * arregloInsumosTotales[k].valorUnidad);
                }
                
            }
        }

        if(totalInsumosActual > totalInsumosMayor)
        {
            totalInsumosMayor = totalInsumosActual;
            nombrePrendaAux = nombrePrendaActual;
        }

        totalInsumosActual = 0;
    }

    prenda.nombre = nombrePrendaAux;
    prenda.costo = totalInsumosMayor;

    return prenda;
}