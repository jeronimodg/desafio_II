#ifndef JUGADOR_H
#define JUGADOR_H
class jugador {
private:
    unsigned short int goles;

public:
    jugador();

    jugador(const jugador& otro);

    void aumentarGoles();
};
#endif // JUGADOR_H
