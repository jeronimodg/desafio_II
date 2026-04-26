#include <iostream>

using namespace std;

#include "torneo.h"

int main() {
    srand(time(0));

    torneo t;

    t.cargar();
    t.generarGrupos();
    t.imprimirGrupos();
    t.jugar();
    t.eliminatorias();
    cout<<endl<<"iteraciones: "<<iteraciones<<"  "<<"memoria consumida: "<<memoriaUsada<<"  Bytes"<<endl;
    return 0;
}
