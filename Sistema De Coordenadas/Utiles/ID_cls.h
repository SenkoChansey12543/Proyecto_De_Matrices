#ifndef ID_CLS_H_INCLUDED
#define ID_CLS_H_INCLUDED

class ID
{
private:
    int id;
    string type;
public:
    ID(int init_id, string init_type)
    {
        id = init_id;
        type = init_type;
    }
    ID(){}

    // Setters y getters
    void set_id(int new_id){id = new_id;}
    void set_type(string new_type){type = new_type;}

    int get_id(){return id;}
    string get_type(){return type;}

    bool operator==(const ID& otro_id)
    {
        if (otro_id.id == id && otro_id.type == type) return true;

        return false;
    }

};

#endif // ID_CLS_H_INCLUDED
