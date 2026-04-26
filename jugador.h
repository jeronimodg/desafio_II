#ifndef JUGADOR_H
#define JUGADOR_H
class jugador {
private:
    unsigned short int goles;

public:
    jugador();

    jugador(const jugador& otro);

    void aumentarGoles();

    unsigned short int getGoles();
};
#endif // JUGADOR_H
