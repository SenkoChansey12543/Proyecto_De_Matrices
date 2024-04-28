#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>

using namespace std;

#include "Utiles/rlutil.h"

#include "Utiles/Arrays_cls.h"
#include "Utiles/ID_cls.h"
#include "Utiles/IDManager_cls.h"

IDManager id_man; // id_man está declarado como variable global ya que todos los objetos usan el mismo IDManager, no se usa ningún otro IDManager además de este.

#include "Utiles/Global_Funcs.h"

#include "Utiles/Vector2_cls.h"

#include "Objetos2D/Objeto2D_cls.h"
#include "Objetos2D/Rectangulo_cls.h"
#include "Objetos2D/Jugador2D_cls.h"
Jugador2D jugador('O', rlutil::YELLOW);
#include "Objetos2D/Enemigo2D_cls.h"
#include "Objetos2D/Spawner2D_cls.h"
#include "Objetos2D/Cell2D_cls.h"
#include "Objetos2D/Mapa2D_cls.h"


int main()

{
    cout << boolalpha;
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::anykey();

    Mapa2D mapa(120, 30, Vector2(70, 30));
    jugador.set_pos(mapa.get_pos());
    mapa.add_object(jugador);

    while (!mapa.player_damaged())
    {
        mapa.process();
    }

    return 0;
}
