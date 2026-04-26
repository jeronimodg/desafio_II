#include "fixture.h"
#include "global.h"
#include <iostream>
using namespace std;

void fixture::generar(grupo grupos[12]) {

    unsigned short int k = 0;

    for(unsigned short int g=0; g<12; g++) {
        iteraciones++;

        equipo* e1 = grupos[g].getEquipo(0);
        equipo* e2 = grupos[g].getEquipo(1);
        equipo* e3 = grupos[g].getEquipo(2);
        equipo* e4 = grupos[g].getEquipo(3);

        partidos[k++] = new partido(*e1,*e2);
        partidos[k++] = new partido(*e1,*e3);
        partidos[k++] = new partido(*e1,*e4);
        partidos[k++] = new partido(*e2,*e3);
        partidos[k++] = new partido(*e2,*e4);
        partidos[k++] = new partido(*e3,*e4);

        memoriaUsada+= sizeof(partido)*6;
    }
}

void fixture::simular(){

    unsigned short int dia = 20;
    unsigned short int mes = 6;

    unsigned short int hora = 0;
    unsigned short int minuto = 0;

    unsigned short int partidosDia = 0;

    for(unsigned short int i=0;i<72;i++){
        iteraciones++;

        cout<<endl;
        cout << "[";

        if(dia < 10) cout << "0";
        cout << dia << "/";

        if(mes < 10) cout << "0";
        cout << mes << " ";

        if(hora < 10) cout << "0";
        cout << hora << ":";

        if(minuto < 10) cout << "0";
        cout << minuto << "] ";
        cout<<endl;

        partidos[i]->simular();
        partidos[i]->imprimir();

        unsigned short int duracion = 90;

        if(partidos[i]->getG1() == partidos[i]->getG2())
            duracion += 30;

        minuto += duracion;

        while(minuto >= 60){
            minuto -= 60;
            hora++;
        }

        partidosDia++;

        if(partidosDia == 4){
            partidosDia = 0;
            hora = 0;
            minuto = 0;
            if(dia==30){
                dia=0;
                mes++;
            }
            dia++;
        }
    }
}
