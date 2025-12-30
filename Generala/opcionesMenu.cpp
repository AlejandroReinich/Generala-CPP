#include <iostream>
#include "jugadaDeDados.h"
#include "combinaciones.h"
#include "opcionesMenu.h"
using namespace std;

void unJugador(int &puntajeMax,string vecNombres[],string vecGanador[]){

    system("cls");

    int modo;
    int ronda=0;
    int generalaServida=0;
    int dados[5],vecCant[6];
    int puntajeTotal=0,lanzamiento;

    cout << "Ingrese nombre del jugador: ";
    cin >> vecNombres[0];
    cout << "Ingrese su apellido: ";
    cin >> vecNombres[1];
    cout <<"Elija el modo de juego"<<endl;
    cout <<"1):MODO MANUAL"<<endl;
    cout <<"2):MODO ALEATORIO "<<endl;
    cin >>modo;
    while(modo!=1&&modo!=2){
    cout <<"Opcion invalida"<<endl;
    cin >>modo;
    }
    system("cls");
do{
    ronda++;
    lanzamiento=1;
    cout <<"--------------------------------------------------"<<endl<<endl;
    cout <<"                 RONDA #"<<ronda<<endl<<endl<<endl;
    cout <<"                 NOMBRE:"<<vecNombres[0]<<endl<<endl<<endl;               //intervalo
    cout <<"                 PUNTAJE:"<<puntajeTotal<<endl<<endl;
    cout <<"--------------------------------------------------"<<endl;
    system("pause");
    system("cls");
    if (modo==1){
    elejirDados(dados);
    }
    else if(modo==2){
    tiradaDados(dados);
    }
    cout<<endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "TURNO DE " << vecNombres[0] << " | RONDA # " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "LANZAMIENTO # " << lanzamiento << endl;
    cout << "------------------------------------------------------------" << endl<<endl;

    mostrarDados(dados);
    volverATirar(dados,lanzamiento);
    contarDados(dados,vecCant);                   //CONTAR NUMEROS PARA DEFINIR JUGADAS
    evaluarJugada(dados,vecCant,generalaServida,lanzamiento,puntajeTotal);

    }while(ronda <10&& generalaServida==0);



    cout <<"--------------------------------------------------"<<endl;
    cout <<"                    FINALIZO EL JUEGO"<<endl<<endl<<endl<<endl;
    cout <<"                 NOMBRE:"<<vecNombres[0]<<" "<<vecNombres[1]<<endl<<endl<<endl;
    cout <<"                 RONDA # "<<ronda<<endl<<endl;                                   //fin del juego
    cout <<"                 PUNTAJE TOTAL:"<<puntajeTotal<<endl<<endl;
    cout <<"--------------------------------------------------"<<endl;

    if(puntajeTotal>puntajeMax) {
        puntajeMax=puntajeTotal;
        vecGanador[0]=vecNombres[0];
        vecGanador[1]=vecNombres[1];
        }
    }


   void multijugador(int &puntajeMax,string vecNombres[],string vecGanador[]){

    system("cls");
    int ronda=0;
    int generalaServidaj1=0,generalaServidaj2=0;
    int dados[5],vecCant[6];
    int puntajeJ1=0,puntajeJ2=0,lanzamiento;
    int puntajeMayor=0;
    string vecGanadorMulti[2];

    cout << "Ingrese nombre del jugador 1:"<<endl;
    cin >> vecNombres[0];
    cout << "ingrese su apellido: "<<endl;
    cin >> vecNombres[1];
    cout <<"ingrese nombre del jugador 2:"<<endl;
    cin >> vecNombres[2];
    cout << "ingrese su apellido: "<<endl;
    cin >> vecNombres[3];
do{
    ronda++;
    lanzamiento=1;
                       //TURNO JUGADOR 1
    cout <<"--------------------------------------------------"<<endl<<endl;
    cout <<"                 RONDA #"<<ronda<<endl<<endl<<endl;
    cout <<"                 PROXIMO TURNO: "<<vecNombres[0]<<endl<<endl<<endl;
    cout <<"                 PUNTAJE:"<<vecNombres[0]<<" "<<puntajeJ1<<endl<<endl;               //intervalo
    cout <<"                 PUNTAJE:"<<vecNombres[2]<<" "<<puntajeJ2<<endl<<endl;
    cout <<"--------------------------------------------------"<<endl;
    system("pause");
    system("cls");

    tiradaDados(dados);

    cout<<endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "TURNO DE " << vecNombres[0] << " | RONDA # " << ronda << " | PUNTAJE TOTAL: " << puntajeJ1 << " PUNTOS" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "LANZAMIENTO # " << lanzamiento << endl;
    cout << "------------------------------------------------------------" << endl<<endl;

    mostrarDados(dados);
    volverATirar(dados,lanzamiento);
    contarDados(dados,vecCant);                   //CONTAR NUMEROS PARA DEFINIR JUGADAS
    evaluarJugada(dados,vecCant,generalaServidaj1,lanzamiento,puntajeJ1);

          //TURNO JUGADOR 2
    cout <<"--------------------------------------------------"<<endl<<endl;
    cout <<"                 RONDA #"<<ronda<<endl<<endl<<endl;
    cout <<"                 PROXIMO TURNO: "<<vecNombres[2]<<endl<<endl<<endl;               //intervalo
    cout <<"                 PUNTAJE:"<<vecNombres[0]<<" "<<puntajeJ1<<endl<<endl;
    cout <<"                 PUNTAJE:"<<vecNombres[2]<<" "<<puntajeJ2<<endl<<endl;
    cout <<"--------------------------------------------------"<<endl;
    system("pause");
    system("cls");
    lanzamiento=1;
    tiradaDados(dados);

    cout<<endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "TURNO DE " << vecNombres[2] << " | RONDA # " << ronda << " | PUNTAJE TOTAL: " << puntajeJ2 << " PUNTOS" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "LANZAMIENTO # " << lanzamiento << endl;
    cout << "------------------------------------------------------------" << endl<<endl;

    mostrarDados(dados);
    volverATirar(dados,lanzamiento);
    contarDados(dados,vecCant);                   //CONTAR NUMEROS PARA DEFINIR JUGADAS
    evaluarJugada(dados,vecCant,generalaServidaj2,lanzamiento,puntajeJ2);

    }while(ronda <10 && generalaServidaj1==0 && generalaServidaj2==0);

    if(puntajeJ1>puntajeJ2){
    puntajeMayor=puntajeJ1;
    vecGanadorMulti[0]=vecNombres[0];
    vecGanadorMulti[1]=vecNombres[1];
    }
    else if(puntajeJ2>puntajeJ1){        //se comparan puntajes y convertir en funcion
    puntajeMayor=puntajeJ2;
    vecGanadorMulti[0]=vecNombres[2];
    vecGanadorMulti[1]=vecNombres[3];
    }
    else {


    int ganador=desempate(vecNombres);
    if(ganador==1){
    puntajeMayor=puntajeJ1;
    vecGanadorMulti[0]=vecNombres[0];
    vecGanadorMulti[1]=vecNombres[1];
    }else{
    puntajeMayor=puntajeJ2;
    vecGanadorMulti[0]=vecNombres[2];
    vecGanadorMulti[1]=vecNombres[3];
    }                                        // tirar numero rnd y ver cual es mayor
    }

    cout <<"--------------------------------------------------"<<endl;
    cout <<"                    FINALIZO EL JUEGO"<<endl<<endl<<endl<<endl;
    cout <<"                     EL GANADOR ES"<<endl<<endl;
    cout <<"                 NOMBRE:"<<vecGanadorMulti[0]<<" "<<vecGanadorMulti[1]<<endl<<endl<<endl;               //fin del juego
    cout <<"                 PUNTAJE TOTAL:"<<puntajeMayor<<endl<<endl;
    cout <<"--------------------------------------------------"<<endl;


    if(puntajeMayor>puntajeMax) {
        puntajeMax=puntajeMayor;
        vecGanador[0]=vecGanadorMulti[0];
        vecGanador[1]=vecGanadorMulti[1];
        }
    }




    void puntuacion (int puntajeMax,string vecGanador[]){

    if (puntajeMax==0){
        system("cls");
        cout<<"===============PUNTAJE==================="<<endl<<endl;
        cout<<"TODAVIA NO HAY PUNTAJES"<<endl;
    }
    else{
    system("cls");
    cout<<"===============PUNTAJE==================="<<endl<<endl;
    cout<<"EL PUNTAJE MAS ALTO ES DE: "<<vecGanador[0]<<" "<<vecGanador[1]<<endl;
    cout<<"CON: "<<puntajeMax<<"  PUNTOS!!"<<endl;
    }
    }

    void creditos(){
            system("cls");
            cout<<"                          Materia:Programacion"<< endl;
            cout<<"                                 Grupo:6"<< endl;
            cout<<"                               Integrantes:"<<endl;
            cout<<endl<<"                      Emanuel Romero Legajo:34198 "<<endl;
            cout<<endl<<"                      Diego Celan Legajo:34145 "<< endl;
            cout<<endl<<"                      Alejandro Reinich Legajo:33067 "<< endl;
            cout<<endl<<"                      Selena Belizan Legajo:33146 " <<endl;
            cout<<endl;
}

