#ifndef VECTOR2_CLS_H_INCLUDED
#define VECTOR2_CLS_H_INCLUDED

class Vector2
{
public:
    double x;
    double y;

    Vector2(double init_x = 0, double init_y = 0)
    {
        x = init_x;
        y = init_y;
    }

    void cpos()
    {
        rlutil::locate(x, y);
    }

    void normalize() // Para que normalice esta instancia de Vector2
    {
        double mag = sqrt(x * x + y * y);

        if (mag != 0)
        {
            x /= mag;
            y /= mag;
        }
    }

    Vector2 normalized() const // Para que devuelva una copia normalizada de este Vector2
    {
        Vector2 vec(x, y);
        double mag = sqrt(x * x + y * y);

        if (mag != 0)
        {
            vec.x /= mag;
            vec.y /= mag;
        }

        return vec;
    }

    double distance_to(const Vector2& vec)
    {
        return sqrt(pow(vec.x - x, 2) + pow(vec.y - y, 2));
    }

    /// Sobrecargas

    // Igualar vectores
    Vector2& operator =(const Vector2& new_vector2)
    {
        if (this != &new_vector2)
        {
            x = new_vector2.x;
            y = new_vector2.y;
        }

        return *this;
    }

    // Resta vectores
    Vector2 operator-(const Vector2& new_vector2) const
    {
        return Vector2(x - new_vector2.x, y - new_vector2.y);
    }
    // Resta compuesta vectores
    Vector2 operator-=(const Vector2& new_vector2)
    {
        x -= new_vector2.x;
        y -= new_vector2.y;
        return *this;
    }

    // Suma vectores
    Vector2 operator+(const Vector2& new_vector2) const
    {
        return Vector2(x + new_vector2.x, y + new_vector2.y);
    }
    // Suma compuesta vectores
    Vector2 operator+=(const Vector2& new_vector2)
    {
        x += new_vector2.x;
        y += new_vector2.y;
        return *this;
    }

    // Multiplicar vectores
    Vector2 operator*(const Vector2& new_vector2) const
    {
        return Vector2(x * new_vector2.x, y * new_vector2.y);
    }
    // Multiplicacion compuesta vectores
    Vector2 operator*=(const Vector2& new_vector2)
    {
        x *= new_vector2.x;
        y *= new_vector2.y;
        return *this;
    }

    // Dividir vectores
    Vector2 operator/(const Vector2& new_vector2) const
    {
        return Vector2(x / new_vector2.x, y / new_vector2.y);
    }
    // Division compuesta vectores
    Vector2 operator/=(const Vector2& new_vector2)
    {
        x /= new_vector2.x;
        y /= new_vector2.y;
        return *this;
    }

    // Multiplicar por escalar
    Vector2 operator*(double scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }
    // Multiplicar por escalar a la izquierda
    friend Vector2 operator*(double scalar, const Vector2& new_vector2)
    {
        return new_vector2 * scalar;
    }
    // Multiplicacion compuesta por escalar
    Vector2& operator *=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // Dividir por escalar
    Vector2 operator/(double scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }
    // Dividir por escalar a la izquierda
    friend Vector2 operator/(double scalar, const Vector2& new_vector2)
    {
        return new_vector2 / scalar;
    }
    // Division compuesta por escalar
    Vector2& operator /=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // Comparar
    bool operator==(const Vector2& comp_vector2)
    {
        if (x == comp_vector2.x && y == comp_vector2.y) return true;
        else return false;
    }

    bool operator!=(const Vector2& comp_vector2)
    {
        if (x != comp_vector2.x || y != comp_vector2.y) return true;
        else return false;
    }

    // Mostrar
    friend ostream& operator<<(ostream& out, const Vector2& new_vector2)
    {
        out << "(" << new_vector2.x << ", " << new_vector2.y << ")";
        return out;
    }
};

#endif // VECTOR2_CLS_H_INCLUDED
