#include <iostream>
#include <ctime>
#include "opcionesMenu.h"
#include "combinaciones.h"
using namespace std;

int main()
{
    int opcion;
    int puntajeMax=0;
    string vecNombres[4],vecGanador[2]; //guarda nombres y apellidos y ganadores
    srand(time(0));

    do {
        system("cls");
        cout<<"|==========MENU PRINCIPAL==========|"<< endl;
        cout<<"|------------GENERALA--------------|"<< endl;
        cout<<"|    1.JUEGO DE UN JUGADOR         |"<< endl;
        cout<<"|    2.JUEGO MULTIJUGADOR          |"<<endl;
        cout<<"|    3.PUNTUACION MAS ALTA         |"<< endl;
        cout<<"|    4.CREDITOS                    |"<< endl;
        cout<<"|    5.SALIR                       |"<< endl;
        cout<<"|__________________________________|"<< endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            unJugador(puntajeMax,vecNombres,vecGanador);
            break;

        case 2:
            multijugador(puntajeMax,vecNombres,vecGanador);
            break;

        case 3:
            puntuacion(puntajeMax,vecGanador);
            break;

        case 4:
            creditos();
            break;

        case 5:
            system("cls");
            cout<<"GRACIAS POR JUGAR"<<endl;

            break;

        default:
            cout<<"Opcion invalida."<< endl;
            break;
        }
        system("pause");
    }

        while(opcion !=5);
        return 0;
}
