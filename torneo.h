
#ifndef TORNEO_H
#define TORNEO_H

#include "equipo.h"
#include "grupo.h"
#include "tabla.h"
#include "fixture.h"

class torneo {
private:
    equipo equipos[48];
    grupo grupos[12];

public:
    torneo();

    void cargar();
    void generarGrupos();
    void jugar();
    void eliminatorias();
    void imprimirGrupos();

    ~torneo();
};

#endif

