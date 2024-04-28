#ifndef IDMANAGER_CLS_H_INCLUDED
#define IDMANAGER_CLS_H_INCLUDED
#endif // IDMANAGER_CLS_H_INCLUDED

class IDManager
{
private:
    Array<ID> IDs;
public:

    int add_id(string type)
    {
        IDs.append(ID(IDs.get_size(), type));

        return IDs.get_size() - 1;
    }

    bool has_id(int id)
    {
        for (int i = 0; i < IDs.get_size(); i++)
        {
            if (IDs[i].get_id() == id) return true;
        }

        return false;
    }

    void mostrar()
    {
        for (int i = 0; i < IDs.get_size(); i++)
        {
            cout << IDs[i].get_id() << " " + IDs[i].get_type() <<endl;
        }
    }
};
