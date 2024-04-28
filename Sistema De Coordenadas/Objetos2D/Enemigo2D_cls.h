#ifndef ENEMIGO2D_CLS_H_INCLUDED
#define ENEMIGO2D_CLS_H_INCLUDED

class Enemigo2D : public Objeto2D
{
private:
    float speed;
    Vector2 velocity;
    Vector2 direction;
public:
    Enemigo2D(Vector2 init_pos, int init_color = rlutil::LIGHTRED) : Objeto2D("Enemigo2D", init_pos, true, init_color)
    {
        draw_icon = 'x';
    }

    void mover()
    {
        speed = jugador.get_movimientos() * 0.0005;

        direction = jugador.get_pos() - posicion;
        velocity = direction.normalized() * speed;

        posicion.cpos();
        cout << ' ';

        posicion += velocity;
        draw();
    }

};

#endif // ENEMIGO2D_CLS_H_INCLUDED
