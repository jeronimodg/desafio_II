#ifndef PARTIDO_H
#define PARTIDO_H
#include "equipopartido.h"

class partido {
private:
    equipo& e1;
    equipo& e2;

    equipopartido ep1;
    equipopartido ep2;

    unsigned short int g1, g2;

public:
    partido(equipo& a, equipo& b);

    partido(const partido& otro);

    void simular();
    void imprimir();

    unsigned short int getG1();
    unsigned short int getG2();
};
#endif // PARTIDO_H
