#include "jugador.h"

jugador::jugador() { goles = 0; }

jugador::jugador(const jugador& otro){
    goles = otro.goles;
}

void jugador::aumentarGoles() { goles++; }

unsigned short int jugador::getGoles(){return goles;}
