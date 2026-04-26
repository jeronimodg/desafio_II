#ifndef GRUPO_H
#define GRUPO_H
#include "equipo.h"
class grupo {
private:
    equipo* equipos[4];
    unsigned short int cantidad;

public:
    grupo();

    bool agregarEquipo(equipo* e);
    equipo* getEquipo(unsigned short int i);

    void imprimir(char letra);
};
#endif // GRUPO_H
