#ifndef GLOBAL_FUNCS_H_INCLUDED
#define GLOBAL_FUNCS_H_INCLUDED

#include <conio.h>
#include <cstdlib>
#include <ctime>

#include "Vector2_cls.h"

bool es_par(int num) {return num % 2 == 0;}

int read_arrows()
{
    char key = getch();

    if (key == -32)
    {
        char arrow = getch();
        switch(arrow)
        {
            case 72: // Arriba = 0
                return 0;
                break;
            case 75: // Izquierda = 1
                return 1;
                break;
            case 77: // Derecha = 2
                return 2;
                break;
            case 80: // Abajo = 3
                return 3;
                break;
        }
    }

    return 4;
}

Vector2 get_nearest_point(Vector2 ini_pos, Array<Vector2> posiciones)
{
    Vector2 nearest_point(0,0);

    for (int i = 0; i < posiciones.get_size(); i++)
    {
        if (i == 0) nearest_point = posiciones[i];
        else if (ini_pos.distance_to(posiciones[i]) < ini_pos.distance_to(nearest_point))
        {
            nearest_point = posiciones[i];
        }
    }

    return nearest_point;
}

int n_rand(int max_num)
{
    static bool asignada = false;

    if (!asignada)
    {
        srand(time(NULL));
        asignada = true;
    }

    // Si no se suma 1 al max_num, no incluye el numero maximo en posible resultados
    return (rand() % max_num+1);
}

bool b_rand()
{
    static bool asignada = false;

    if (!asignada)
    {
        srand(time(NULL));
        asignada = true;
    }

    return rand() % 2;
}

#endif // GLOBAL_FUNCS_H_INCLUDED
