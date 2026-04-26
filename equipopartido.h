#ifndef EQUIPOPARTIDO_H
#define EQUIPOPARTIDO_H
#include "equipo.h"
#include "global.h"

class equipopartido {
private:
    jugador* titulares[11];
    unsigned short int goles;

    unsigned short int goleadores[20];
    unsigned short int cantGoles;

public:
    equipopartido(equipo& e);

    equipopartido(const equipopartido& otro);

    void simular();
    unsigned short int getGoles();

    unsigned short int getCantGoles();
    unsigned short int getGoleador(unsigned short int i);
};
#endif // EQUIPOPARTIDO_H
