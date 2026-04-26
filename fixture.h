#ifndef FIXTURE_H
#define FIXTURE_H
#include "partido.h"
#include "grupo.h"
class fixture {
private:
    partido* partidos[72];

public:
    void generar(grupo grupos[12]);
    void simular();

    ~fixture();
};
#endif // FIXTURE_H
