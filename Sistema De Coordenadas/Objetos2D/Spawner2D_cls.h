#ifndef SPAWNER2D_CLS_H_INCLUDED
#define SPAWNER2D_CLS_H_INCLUDED

class Spawner2D : public Objeto2D
{
public:
    Spawner2D(Vector2 init_pos) : Objeto2D("Spawner2D", init_pos, true, rlutil::LIGHTMAGENTA)
    {
        draw_icon = char(248);
    }

    Enemigo2D spawn()
    {
        Enemigo2D enemigo(posicion);
        return enemigo;
    }
};

#endif // SPAWNER2D_CLS_H_INCLUDED
