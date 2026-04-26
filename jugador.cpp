#include "jugador.h"

jugador::jugador() { goles = 0; }

jugador::jugador(const jugador& otro){
    goles = otro.goles;
}

void jugador::aumentarGoles() { goles++; }
