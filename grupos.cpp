/*#include "equipo.h"
#include "grupo.h"
void generarGrupos(equipo* equipos, grupo* grupos) {

    // ordenar por ranking
    for(int i=0;i<47;i++) {
        for(int j=0;j<47-i;j++) {
            if(equipos[j].getRanking() > equipos[j+1].getRanking()) {
                equipo temp = equipos[j];
                equipos[j] = equipos[j+1];
                equipos[j+1] = temp;
            }
        }
    }

    equipo* bombos[4][12];

    for(int i=0;i<4;i++)
        for(int j=0;j<12;j++)
            bombos[i][j] = &equipos[i*12 + j];

    bool completo = false;

    while(!completo) {

        completo = true;

        // reset grupos
        for(int i=0;i<12;i++) {
            grupos[i] = grupo();
            grupos[i].setLetra('A'+i);
        }

        for(int b=0;b<4;b++) {

            bool usados[12] = {false};

            for(int g=0; g<12; g++) {

                bool asignado = false;

                for(int intento=0; intento<50 && !asignado; intento++) {

                    int r = rand()%12;

                    if(usados[r]) continue;

                    if(grupos[g].agregarEquipo(bombos[b][r])) {
                        usados[r] = true;
                        asignado = true;
                    }
                }

                if(!asignado) {
                    completo = false;
                    break;
                }
            }

            if(!completo) break;
        }
    }
}*/

