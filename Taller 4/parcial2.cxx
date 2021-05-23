#include <iostream>
void calificacion();
void puntacion();
using namespace std;

int main()
{
    int id, estudiantes;
    cout << "cuantos estudiantes son: " << endl;
    cin >> estudiantes;
    char arreglo_respuestas[20];
    int id_est[estudiantes];
    int puntos_total[estudiantes];
    char nota_final[estudiantes];
    string respuestas;

    cout << "ingrese las respuestas correcta: " << endl;
    cin >> respuestas;

    for (int i = 0; i < estudiantes; i++)
    {
        cout << "digite el ID del estudiante: " << i << endl;
        cin >> id;
        id_est[i] = id;
    }

    for (int i = 0; i < 20; i++)
    {
        re_examen[i] = respuestas[i];
    }

    for (int i = 0; i < estudiantes; i++)
    {
        calificacion();
    }
    puntacion();
    return 0;
}

void calificacion(int estudiantes,char arreglo_respuestas[], string arreglo_respuestas_correctas, int aux_numero_estudiantes, int puntos_total[])
{
    string respuesta;
    int puntaje_total = 0;
    cout << "ingrese las respuestas en una sola linea:  " << endl;
    cin >> respuesta;
    for (int i = 0; i < 20; i++)
    {
        arreglo_respuestas[i] = respuesta[i];
    }

    for (int i = 0; i < 20; i++)
    {
        if (arreglo_respuestas_correctas[i] == arreglo_respuestas[i])
        {
            puntaje_total = puntaje_total + 2;
        }
        else
        {
            puntaje_total = puntaje_total - 1;
        }
    }
    puntos_total[aux_numero_estudiantes] = puntaje_total;
}

void puntacion(int arreglo_de_puntos[], int estudiantes,)
{
    char nota_final[estudiantes];
    for (int i = 0; i < estudiantes; i++)
    {
        if (arreglo_de_puntos[i] > 40 * 0.9)
        {
            nota_final[i] = 'A';
        }
        if (arreglo_de_puntos[i] < 40 * 0.89 )
        {
            nota_final[i] = 'B';
        }
        if (arreglo_de_puntos[i] < 40 * 0.79 )
        {
            nota_final[i] = 'C';
        }
        if (arreglo_de_puntos[i] < 40 * 0.69 )
        {
            nota_final[i] = 'D';
        }
        if (arreglo_de_puntos[i] <= 0)
        {
            nota_final[i] = 'F';
        }
        if (arreglo_de_puntos[i] < 40 * 0.59)
        {
            nota_final[i] = 'F';
        }
    }
}