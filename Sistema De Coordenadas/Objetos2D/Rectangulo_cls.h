#ifndef RECTANGULO_CLS_H_INCLUDED
#define RECTANGULO_CLS_H_INCLUDED

class Rectangulo : public Objeto2D
{
protected:
    double base;
    double altura;

    Vector2 top_left_corner;
    Vector2 down_right_corner;

    int border_color;

public:
    Rectangulo (double init_base, double init_altura, Vector2 init_pos = Vector2(0,0), int color = rlutil::LIGHTCYAN, string init_type = "Rectangulo") : Objeto2D(init_type, init_pos, true, color)
    {
        base = init_base;
        altura = init_altura;

        // Esquinas
        top_left_corner = Vector2(posicion.x - (base / 2), posicion.y - (altura / 2));
        down_right_corner = Vector2(posicion.x + (base / 2), posicion.y + (altura / 2));
        border_color = color;
    }

    bool is_inside(Vector2 pos)
    {
        Vector2 fix_offset(0,0);

        if (!es_par(down_right_corner.x)) fix_offset.x = 1;
        if (es_par(down_right_corner.y)) fix_offset.y = 1;

        // A la derecha de top_left_corner e izquierda de down_right_corner
        if (pos.x > top_left_corner.x && pos.x < down_right_corner.x-fix_offset.x)
            // Abajo de top_left_corner y arriba de down_right_corner
            if (pos.y > top_left_corner.y && pos.y < down_right_corner.y-fix_offset.y)
                return true;;

        return false;
    }

    Array<Vector2> get_points()
    {
        Array<Vector2> points;
        for (int x = top_left_corner.x; x <= down_right_corner.x; x++)
        {
            for (int y = top_left_corner.y; y <= down_right_corner.y; y++)
            {
                points.append(Vector2(x,y));
            }
        }

        return points;
    }

    Array<Vector2> get_border_points()
    {
        Array<Vector2> points;

        for (int i = 0; i <= down_right_corner.y - top_left_corner.y; i++)
        {
            points.append(Vector2(top_left_corner.x, top_left_corner.y + i));
            points.append(Vector2(down_right_corner.x, top_left_corner.y + i));
        }
        for (int i = 0; i <= down_right_corner.x - top_left_corner.x; i++)
        {
            points.append(Vector2(top_left_corner.x + i, top_left_corner.y));
            points.append(Vector2(top_left_corner.x + i, down_right_corner.y));
        }

        return points;
    }

    void draw_borders()
    {
        if (!(top_left_corner.x > 0 && top_left_corner.y > 0)) return;

        rlutil::setColor(border_color);

        for (int i = 0; i <= down_right_corner.y - top_left_corner.y; i++)
        {
            Vector2(top_left_corner.x, top_left_corner.y + i).cpos();
            cout << char(219);
            Vector2(down_right_corner.x, top_left_corner.y + i).cpos();
            cout << char(219);
        }

        for (int i = 0; i <= down_right_corner.x - top_left_corner.x; i++)
        {
            Vector2(top_left_corner.x + i, top_left_corner.y).cpos();
            cout << char(220);
            Vector2(top_left_corner.x + i, down_right_corner.y).cpos();
            cout << char(223);
        }

        rlutil::setColor(rlutil::WHITE);
    }

    friend ostream& operator<< (ostream& out, const Rectangulo& rectangulo)
    {
        out << "W: " << rectangulo.base << ", H: " << rectangulo.altura << endl <<
        "Pos: " << rectangulo.posicion << endl <<
        "TLC: " << rectangulo.top_left_corner << ", DRC: " << rectangulo.down_right_corner;

        return out;
    }
};

#endif // RECTANGULO_CLS_H_INCLUDED
