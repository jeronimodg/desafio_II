#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "jugador.h"

using namespace std;

#include <string>
#include "jugador.h"

using namespace std;

class equipo {
private:
    string pais;
    char conf;
    unsigned short int ranking;

    unsigned short int puntos, gf, gc;

    jugador jugadores[26];

public:
    equipo();

    equipo(const equipo& otro);

    void setDatos(string p, char c, unsigned short int r);

    string getPais();
    char getConfederacion();
    unsigned short int getRanking();

    jugador& getJugador(unsigned short int i);

    void actualizar(unsigned short int g1, unsigned short int g2);

    unsigned short int getPuntos();
    unsigned short int getGF();
    unsigned short int getGC();

    unsigned short int getGolesJugador(unsigned short int i);
};

#endif
