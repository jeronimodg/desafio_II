#ifndef TABLA_H
#define TABLA_H
#include "grupo.h"

class tabla {
private:
    equipo* equipos[4];

public:
    void cargar(grupo& g);
    void ordenar();
    void imprimir(char letra);
    equipo* get(unsigned short int i);
};
#endif // TABLA_H
