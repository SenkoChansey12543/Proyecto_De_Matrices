#ifndef CELL2D_CLS_H_INCLUDED
#define CELL2D_CLS_H_INCLUDED

class Cell2D : public Objeto2D // Esta clase representa una celda de un tileset en una posicion
// ESTA CLASE TODAVIA NO ESTA TERMINADA, NO FUNCIONA CORRECTAMENTE.
{
private:
    Array<Objeto2D*> objetos_dentro;
public:
    Cell2D(Vector2 init_pos) : Objeto2D("Cell2D", init_pos){}

    void add_object(Objeto2D& objeto)
    {
        if (objeto.get_pos() == posicion)
            objetos_dentro.append(&objeto);
    }

    void remove_object(Objeto2D& objeto)
    {
        for (int i = 0; i < objetos_dentro.get_size(); i++)
        {
            if ((*objetos_dentro[i]).get_id() == objeto.get_id())
                objetos_dentro.erase_pos(i);
        }
    }

    void remove_all_objects()
    {
        objetos_dentro._resize(0);
    }

    void remove_outside_objects()
    {
        int i = 0;
        int limit = 0;
        while (i < objetos_dentro.get_size())
        {
            if ((*objetos_dentro[i]).get_pos() != posicion)
                objetos_dentro.erase_pos(i);
            else i++;

            if (limit > 100) break;
            limit++;
        }
    }

    bool has_object(Objeto2D& objeto)
    {
        for (int i = 0; i < objetos_dentro.get_size(); i++)
        {
            if ((*objetos_dentro[i]).get_id() == objeto.get_id())
                return true;
        }

        return false;
    }

    int get_object_amount(){return objetos_dentro.get_size();}
};

#endif // CELL2D_CLS_H_INCLUDED
