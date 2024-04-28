#ifndef JUGADOR2D_CLS_H_INCLUDED
#define JUGADOR2D_CLS_H_INCLUDED

class Jugador2D : public Objeto2D
{
private:
    int movimientos;
public:
    Jugador2D(char init_draw_icon, int init_color = rlutil::WHITE, string init_type = "Jugador2D", Vector2 _posicion = Vector2(0,0)) : Objeto2D(init_type, _posicion, /*drawable=*/true, init_color)
    {
        draw_icon = init_draw_icon;
        movimientos = 0;
    }
    void moverse()
    {
        Vector2(1,1).cpos();
        cout << "Movimientos: " << movimientos;

        switch (read_arrows())
        {
            case 0:
                movimientos++;
                posicion.cpos();
                cout << ' ';
                posicion.y -= 1;
                draw();
            break;
            case 1:
                movimientos++;
                posicion.cpos();
                cout << ' ';
                posicion.x -= 1;
                draw();
            break;
            case 2:
                movimientos++;
                posicion.cpos();
                cout << ' ';
                posicion.x += 1;
                draw();
            break;
            case 3:
                movimientos++;
                posicion.cpos();
                cout << ' ';
                posicion.y += 1;
                draw();
            break;
        }
    }

    int get_movimientos(){return movimientos;}
};

#endif // JUGADOR2D_CLS_H_INCLUDED
