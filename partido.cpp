#include "partido.h"
#include "global.h"
#include <iostream>
using namespace std;

partido::partido(equipo& a, equipo& b)
    : e1(a), e2(b), ep1(a), ep2(b) {}

void partido::simular() {
    ep1.simular();
    ep2.simular();

    g1 = ep1.getGoles();
    g2 = ep2.getGoles();

    e1.actualizar(g1,g2);
    e2.actualizar(g2,g1);
}

void partido::imprimir(){

    cout << e1.getPais() << " "
         << g1 << " - " << g2 << " "
         << e2.getPais();

    cout << " | EEUU";

    if(g1 == g2){
        cout << " | Prorroga";
    }

    cout << endl;

    cout << "Goles " << e1.getPais() << ": ";
    for(unsigned short int i=0;i<ep1.getCantGoles();i++){
        iteraciones++;
        cout << ep1.getGoleador(i) << " ";
    }
    cout << endl;

    cout << "Goles " << e2.getPais() << ": ";
    for(unsigned short int i=0;i<ep2.getCantGoles();i++){
        iteraciones++;
        cout << ep2.getGoleador(i) << " ";
    }
    cout << endl;
}

unsigned short int partido::getG1(){ return g1; }
unsigned short int partido::getG2(){ return g2; }
