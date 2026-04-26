#include <iostream>

using namespace std;

#include "torneo.h"

int main() {

    torneo t;

    t.cargar();
    t.generarGrupos();
    t.imprimirGrupos();
    t.jugar();
    t.eliminatorias();
    cout<<endl<<"iteraciones: "<<iteraciones<<"  "<<"memoria consumida: "<<memoriaUsada<<"  Bytes"<<endl;
    return 0;
}
