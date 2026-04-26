#include "torneo.h"
#include "global.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include <fstream>
#include <sstream>
torneo::torneo(){}

torneo::torneo(const torneo& otro){

    for(unsigned short int i=0;i<48;i++)
        equipos[i] = otro.equipos[i];

    for(unsigned short int i=0;i<12;i++)
        grupos[i] = otro.grupos[i];
}

void torneo::cargar() {

    ifstream file("selecciones_clasificadas_mundial.csv");

    string linea;

    unsigned short int i = 0;

    getline(file, linea);
    getline(file, linea);

    while(getline(file, linea) && i < 48) {
        iteraciones++;

        stringstream ss(linea);

        string temp;
        string pais;
        char conf;
        unsigned short int ranking;

        getline(ss, temp, ';');
        getline(ss, pais, ';');

        getline(ss, temp, ';');
        getline(ss, temp, ';');

        getline(ss, temp, ';');
        conf = temp[0];

        getline(ss, temp, ';');
        getline(ss, temp, ';');

        getline(ss, temp, ';');
        ranking = stoi(temp);

        equipos[i].setDatos(pais, conf, ranking);

        i++;
    }

    file.close();
}

void torneo::generarGrupos() {

    for(unsigned short int i=0;i<47;i++){
        iteraciones++;
        for(unsigned short int j=0;j<47-i;j++){
            iteraciones++;
            if(equipos[j].getRanking() > equipos[j+1].getRanking()){
                equipo temp = equipos[j];
                equipos[j] = equipos[j+1];
                equipos[j+1] = temp;
            }
        }
    }

    equipo* bombos[4][12];

    for(unsigned short int i=0;i<4;i++){
        iteraciones++;
        for(unsigned short int j=0;j<12;j++){
            iteraciones++;
            bombos[i][j] = &equipos[i*12 + j];
        }
    }

    for(unsigned short int g=0; g<12; g++){
        iteraciones++;
        grupos[g] = grupo();
    }

    for(unsigned short int b=0; b<4; b++){
        iteraciones++;

        bool usados[12] = {false};

        for(unsigned short int g=0; g<12; g++){
            iteraciones++;

            unsigned short int r;

            do{
                iteraciones++;
                r = rand()%12;
            }while(usados[r]);

            grupos[g].agregarEquipo(bombos[b][r]);
            usados[r] = true;
        }
    }
}

void torneo::jugar() {

    fixture f;
    f.generar(grupos);
    f.simular();
}
void torneo::imprimirGrupos(){

    cout << "\n=== GRUPOS ===\n";

    for(unsigned short int i=0;i<12;i++){
        iteraciones++;
        grupos[i].imprimir('A' + i);
    }
}
void torneo::eliminatorias(){

    tabla tablas[12];

    equipo* primeros[12];
    equipo* segundos[12];
    equipo* terceros[12];

    for(unsigned short int i=0;i<12;i++){
        iteraciones++;

        tablas[i].cargar(grupos[i]);
        tablas[i].ordenar();
        tablas[i].imprimir('A'+i);

        primeros[i] = tablas[i].get(0);
        segundos[i] = tablas[i].get(1);
        terceros[i] = tablas[i].get(2);
    }

    for(unsigned short int i=0;i<11;i++){
        iteraciones++;
        for(unsigned short int j=0;j<11-i;j++){
            iteraciones++;

            equipo* a = terceros[j];
            equipo* b = terceros[j+1];

            bool cambiar = false;

            if(a->getPuntos() < b->getPuntos())
                cambiar = true;

            else if(a->getPuntos() == b->getPuntos()){

                short int diffA = a->getGF() - a->getGC();
                short int diffB = b->getGF() - b->getGC();

                if(diffA < diffB)
                    cambiar = true;
            }

            if(cambiar){
                equipo* t = terceros[j];
                terceros[j] = terceros[j+1];
                terceros[j+1] = t;
            }
        }
    }

    cout << "\n=== CLASIFICADOS ===\n";

    for(unsigned short int i=0;i<12;i++){
        iteraciones++;
        cout << "1° " << primeros[i]->getPais() << endl;
    }

    for(unsigned short int i=0;i<12;i++){
        iteraciones++;
        cout << "2° " << segundos[i]->getPais() << endl;
    }

    for(unsigned short int i=0;i<8;i++){
        iteraciones++;
        cout << "3° " << terceros[i]->getPais() << endl;
    }

    equipo* ronda[32];
    unsigned short int k = 0;

    for(unsigned short int i=0;i<12;i++) {
        iteraciones++;
        ronda[k++] = primeros[i];
    }
    for(unsigned short int i=0;i<12;i++) {
        iteraciones++;
        ronda[k++] = segundos[i];
    }
    for(unsigned short int i=0;i<8;i++)  {
        iteraciones++;
        ronda[k++] = terceros[i];
    }
    cout << "\n=== ELIMINATORIAS ===\n";

    unsigned short int n = 32;

    unsigned short int dia = 10;
    unsigned short int mes = 7;

    unsigned short int hora = 0;
    unsigned short int minuto = 0;

    unsigned short int partidosDia = 0;
    while(n > 1){

        cout << "\n--- Ronda de " << n << " ---\n";

        equipo* sig[32];
        unsigned short int j=0;

        for(unsigned short int i=0;i<n;i+=2){
            iteraciones++;

            cout << "[";

            if(dia < 10) cout << "0";
            cout << dia << "/";

            if(mes < 10) cout << "0";
            cout << mes << " ";

            if(hora < 10) cout << "0";
            cout << hora << ":";

            if(minuto < 10) cout << "0";
            cout << minuto << "] ";

            partido p(*ronda[i], *ronda[i+1]);
            cout<<endl;
            p.simular();
            p.imprimir();

            cout<<endl;
            unsigned short int duracion = 90;

            if(p.getG1() == p.getG2())
                duracion += 30;

            minuto += duracion;

            while(minuto >= 60){
                iteraciones++;
                minuto -= 60;
                hora++;
            }

            partidosDia++;

            if(partidosDia == 4){
                partidosDia = 0;
                hora = 0;
                minuto = 0;
                dia++;
            }

            if(p.getG1() >= p.getG2())
                sig[j++] = ronda[i];
            else
                sig[j++] = ronda[i+1];
        }

        for(unsigned short int i=0;i<j;i++){
            iteraciones++;
            ronda[i] = sig[i];
        }

        n = j;
    }

    cout << "\nCAMPEON: " << ronda[0]->getPais() << endl;
}

torneo::~torneo(){}
