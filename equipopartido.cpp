#include "equipopartido.h"
#include <cstdlib>

equipopartido::equipopartido(equipo& e){
    for(unsigned short int i=0;i<11;i++){
        iteraciones++;
        titulares[i] = &e.getJugador(rand()%26);
    }
}

void equipopartido::simular(){

    goles = rand()%4;
    cantGoles = 0;

    for(unsigned short int i=0;i<goles;i++){
        iteraciones++;

        unsigned short int r = rand()%11;

        goleadores[cantGoles++] = r + 1;

        titulares[r]->aumentarGoles();
    }
}

unsigned short int equipopartido::getGoles(){
    return goles;
}

unsigned short int equipopartido::getCantGoles(){
    return cantGoles;
}

unsigned short int equipopartido::getGoleador(unsigned short int i){
    return goleadores[i];
}
