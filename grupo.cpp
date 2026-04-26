#include "grupo.h"
#include "global.h"
#include <iostream>
using namespace std;
grupo::grupo(){ cantidad = 0; }

grupo::grupo(const grupo& otro){

    cantidad = otro.cantidad;

    for(unsigned short int i=0;i<cantidad;i++){
        iteraciones++;
        equipos[i] = otro.equipos[i];
    }
}

bool grupo::agregarEquipo(equipo* e){
    if(cantidad < 4){
        equipos[cantidad++] = e;
        return true;
    }
    return false;
}

void grupo::imprimir(char letra){

    cout << "\n=== GRUPO " << letra << " ===\n";

    for(unsigned short int i=0;i<cantidad;i++){
        iteraciones++;
        cout << equipos[i]->getPais()
        << " (" << equipos[i]->getConfederacion() << ")"
        << endl;
    }
}

equipo* grupo::getEquipo(unsigned short int i){
    return equipos[i];
}
