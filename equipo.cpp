#include "equipo.h"
#include "global.h"
equipo::equipo(){
    puntos = gf = gc = 0;
}
equipo::equipo(const equipo& otro){

    pais = otro.pais;
    conf = otro.conf;
    ranking = otro.ranking;

    puntos = otro.puntos;
    gf = otro.gf;
    gc = otro.gc;

    for(unsigned short int i=0;i<26;i++){
        iteraciones++;
        jugadores[i] = otro.jugadores[i];
    }
}


void equipo::setDatos(string p, char c, unsigned short int r){
    pais = p;
    conf = c;
    ranking = r;
}

string equipo::getPais(){ return pais; }
char equipo::getConfederacion(){ return conf; }
unsigned short int equipo::getRanking(){ return ranking; }

jugador& equipo::getJugador(unsigned short int i){ return jugadores[i]; }

void equipo::actualizar(unsigned short int g1, unsigned short int g2){
    gf += g1;
    gc += g2;

    if(g1 > g2) puntos += 3;
    else if(g1 == g2) puntos += 1;
}

unsigned short int equipo::getPuntos(){ return puntos; }
unsigned short int equipo::getGF(){ return gf; }
unsigned short int equipo::getGC(){ return gc; }
