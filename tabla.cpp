#include "tabla.h"
#include "global.h"
#include <iostream>

using namespace std;

tabla::tabla(){}

tabla::tabla(const tabla& otro){
    for(unsigned short int i=0;i<4;i++){
        iteraciones++;
        equipos[i] = otro.equipos[i];
    }
}

void tabla::cargar(grupo& g){
    for(unsigned short int i=0;i<4;i++){
        iteraciones++;
        equipos[i] = g.getEquipo(i);
    }
}

void tabla::ordenar(){

    for(unsigned short int i=0;i<3;i++){
        iteraciones++;
        for(unsigned short int j=0;j<3-i;j++){
            iteraciones++;

            equipo* a = equipos[j];
            equipo* b = equipos[j+1];

            bool cambiar = false;

            if(a->getPuntos() < b->getPuntos())
                cambiar = true;

            else if(a->getPuntos() == b->getPuntos()){

                short int diffA = a->getGF() - a->getGC();
                short int diffB = b->getGF() - b->getGC();

                if(diffA < diffB)
                    cambiar = true;

                else if(diffA == diffB){
                    if(a->getGF() < b->getGF())
                        cambiar = true;
                }
            }

            if(cambiar){
                equipo* t = equipos[j];
                equipos[j] = equipos[j+1];
                equipos[j+1] = t;
            }
        }
    }
}

void tabla::imprimir(char letra){

    cout << "\n=== GRUPO " << letra << " ===\n";
    cout << "Equipo\tPts\tGF\tGC\n";

    for(unsigned short int i=0;i<4;i++){
        iteraciones++;

        cout << equipos[i]->getPais() << "\t"
             << equipos[i]->getPuntos() << "\t"
             << equipos[i]->getGF() << "\t"
             << equipos[i]->getGC() << endl;
    }
}

equipo* tabla::get(unsigned short int i){
    return equipos[i];
}
