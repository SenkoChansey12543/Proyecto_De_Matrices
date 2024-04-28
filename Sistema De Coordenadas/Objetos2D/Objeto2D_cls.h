#ifndef OBJETO2D_H_INCLUDED
#define OBJETO2D_H_INCLUDED

class Objeto2D
{
protected:
    string type;
    char draw_icon;
    bool drawable;
    int draw_color;
    int ID;
    Vector2 posicion;
public:
    Objeto2D (string init_type = "Objeto2D", Vector2 init_pos = Vector2(0,0), bool init_drawable = false, int color = rlutil::WHITE)
    {
        posicion = init_pos;
        drawable = init_drawable;
        draw_color = color;
        type = init_type;
        id_man.add_id(type);
    }
    Objeto2D()
    {
        posicion = Vector2(0,0);
        drawable = true;
        type = "Objeto2D";
        id_man.add_id(type);
    }

    void set_pos(Vector2 new_pos) {posicion = new_pos;}
    Vector2 get_pos(){return posicion;}
    string get_type(){return type;}

    int get_id(){return ID;}

    void set_draw_icon(char icon){draw_icon = icon;}

    void draw()
    {
        if (!drawable) return;
        rlutil::setColor(draw_color);
        posicion.cpos();
        cout << draw_icon;
        rlutil::setColor(rlutil::WHITE);
    }
};

#endif // OBJETO2D_H_INCLUDED
