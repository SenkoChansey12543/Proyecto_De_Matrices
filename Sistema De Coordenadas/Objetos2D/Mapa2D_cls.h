#ifndef MAPA2D_CLS_H_INCLUDED
#define MAPA2D_CLS_H_INCLUDED

class Mapa2D : public Rectangulo
{
private:
    Array<Objeto2D*> objetos_dentro;
    Array<Enemigo2D*> enemigos_dentro;
    Array<Spawner2D*> spawners_dentro;
    Array<Cell2D*> celdas;
    Array<bool> objetos_dinamicos;
public:
    Mapa2D(double init_base, double init_altura, Vector2 init_pos, int init_color = rlutil::LIGHTCYAN) : Rectangulo(init_base, init_altura, init_pos, init_color, "Mapa2D")
    {
        draw_borders();
        create_spawners();
        setup_cells();
    }

    void create_spawners()
    {
        Rectangulo spawner_rec(base - 15, altura - 10, posicion);
        Array<Vector2> points = spawner_rec.get_border_points();

        for (int i = 0; i < points.get_size(); i++)
        {
            if (i < 10) add_object(Spawner2D(points[i]));
            else if (n_rand(10) == 5)
            {
                add_object(Spawner2D(points[i]));
            }
        }
    }

    void setup_cells()
    {
        Array<Vector2> points = get_points();
        for (int i = 0; i < points.get_size(); i++)
            celdas.append(new Cell2D(points[i]));
    }

    int get_objects_amount(){return objetos_dentro.get_size();}

    void keep_objects_inside()
    {
        for (int i = 0; i < objetos_dentro.get_size(); i++)
        {
            if (objetos_dentro[i] != nullptr)
            {
                if (!is_inside((*objetos_dentro[i]).get_pos()))
                {
                    Vector2 obj_pos = (*objetos_dentro[i]).get_pos();
                    obj_pos.cpos();
                    cout << ' ';

                    for (int j = 0; j < 4; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            obj_pos.x += 2;
                            break;
                        case 1:
                            obj_pos.x -= 2;
                            break;
                        case 2:
                            obj_pos.y += 2;
                            break;
                        case 3:
                            obj_pos.y -= 2;
                            break;
                        }

                        if (is_inside(obj_pos)) break;

                        obj_pos = (*objetos_dentro[i]).get_pos();
                    }

                    (*objetos_dentro[i]).set_pos(obj_pos);
                    (*objetos_dentro[i]).draw();
                    draw_borders();
                }
            }
        }
    }

    void add_object(Objeto2D& objeto)
    {
        if (is_inside(objeto.get_pos()))
        {
            objetos_dentro.append(&objeto);
            objetos_dinamicos.append(false);
        }
    }
    void add_object(Objeto2D&& objeto)
    {
        if (is_inside(objeto.get_pos()))
        {
            objetos_dentro.append(new Objeto2D(objeto));
            objetos_dinamicos.append(true);
        }
    }

    void add_object(Enemigo2D& enemigo)
    {
        if (is_inside(enemigo.get_pos()))
        {
            objetos_dentro.append(&enemigo);
            enemigos_dentro.append(&enemigo);
            objetos_dinamicos.append(false);
        }
    }
    void add_object(Enemigo2D&& enemigo)
    {
        if (is_inside(enemigo.get_pos()))
        {
            Enemigo2D* enemigo_instance = new Enemigo2D(enemigo);

            objetos_dentro.append(enemigo_instance);
            enemigos_dentro.append(enemigo_instance);
            objetos_dinamicos.append(true);
        }
    }

    void add_object(Spawner2D& spawner)
    {
        if (is_inside(spawner.get_pos()))
        {
            objetos_dentro.append(&spawner);
            spawners_dentro.append(&spawner);
            objetos_dinamicos.append(false);
        }
    }
    void add_object(Spawner2D&& spawner)
    {
        if (is_inside(spawner.get_pos()))
        {
            Spawner2D* spawner_instance = new Spawner2D(spawner);

            objetos_dentro.append(spawner_instance);
            spawners_dentro.append(spawner_instance);
            objetos_dinamicos.append(true);
        }
    }

    void draw_spawners()
    {
        for (int i = 0; i < spawners_dentro.get_size(); i++)
        {
            if (spawners_dentro[i] != nullptr) (*spawners_dentro[i]).draw();
        }
    }

    void move_enemies()
    {
        for (int i = 0; i < enemigos_dentro.get_size(); i++)
        {
            if (enemigos_dentro[i] != nullptr)
            (*enemigos_dentro[i]).mover();
        }
    }

    void try_to_spawn()
    {
        for (int i = 0; i < spawners_dentro.get_size(); i++)
        {
            if (n_rand(500) == 50)
                add_object((*spawners_dentro[i]).spawn());
        }
    }

    void manage_cells()
    {
        for (int i = 0; i < celdas.get_size(); i++)
        {
            for (int j = 0; j < objetos_dentro.get_size(); j++)
            {
                if ((*celdas[i]).get_pos() == (*objetos_dentro[j]).get_pos())
                    (*celdas[i]).add_object(*objetos_dentro[j]);
            }
            (*celdas[i]).remove_outside_objects();
        }
    }

    void process()
    {
        jugador.moverse();
        draw_spawners();
        try_to_spawn();
        keep_objects_inside();
        move_enemies();
        manage_cells();
    }

    bool player_damaged()
    {
        for (int i = 0; i < celdas.get_size(); i++)
        {

            if ((*celdas[i]).has_object(jugador) && (*celdas[i]).get_object_amount() >= 2)
                return true;
        }
        return false;
    }

    ~Mapa2D()
    {
        for (int i = 0; i < objetos_dentro.get_size(); i++)
        {
            if (objetos_dinamicos[i])
            {
                delete[] objetos_dentro[i];
            }
        }
    }
};

#endif // MAPA2D_CLS_H_INCLUDED
