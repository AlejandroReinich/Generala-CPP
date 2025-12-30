#include <iostream>

using namespace std;


void contarDados(int dados[],int vecCant[]){

for(int i=0; i<6; i++){   //INICIALIZA EN 0 EL VECTOR PARA CONTAR APARICIONES
       vecCant[i] = 0;
}
for (int i = 0; i < 5; i++){
        vecCant[dados[i]-1]++;       //CUENTA APARICIONES
}
}

bool poker(int vecCant[]) {
    for (int i =0; i <6; i++){ //EVALUA SI HAY 4 IGUALES
        if (vecCant[i] == 4){
        return true;}
        }
        return false;
}

bool full(int vecCant[]) {
    bool tresIguales = false ,dosIguales = false;
    for (int i = 0; i <6; i++) {
        if (vecCant[i] == 3 ){tresIguales = true;} //EVALUA SI HAY 2 Y 3 IGUALES
        if (vecCant[i] == 2) {dosIguales = true;
        }
        }
        return tresIguales && dosIguales;
}

bool generala(int vecCant[]) {
    for (int i = 0; i <6; i++){ //EVALUA SI HAY 5 IGUALES
        if (vecCant[i] == 5){
        return true;}
        }
        return false;
}

bool escalera(int dados[]){

    int posmin, aux;
    for(int i=0;i<5-1;i++){
        posmin=i;
        for(int x=i+1;x<5;x++){
            if(dados[x]<dados[posmin]) posmin=x;     //ORDENAR VECTOR DE MENOR A MAYOR
            }
    aux=dados[i];
    dados[i]=dados[posmin];
    dados[posmin]=aux;
    }
      if(dados[0]==1&&dados[1]==2&&dados[2]==3&&dados[3]==4&&dados[4]==5){
        return true;
           }else if (dados[0]==2&&dados[1]==3&&dados[2]==4&&dados[3]==5&&dados[4]==6){
        return true;                                                                    //COMPROBAR ESCALERA en secuencia
        }
        return false;
}

int evaluarJugada(int dados[],int vecCant[],int& generalaServida,int lanzamiento,int &puntajeTotal) {  //EVALUA JUGADA Y SUMA PUNTOS

    int numDado;
    int acum=0;

    if (generala(vecCant)==true && lanzamiento==1){ puntajeTotal+=450;generalaServida=1; cout <<"SACASTE GENERALA SERVIDA!!!!"<<endl;  //generala servida
    }else if (generala(vecCant)==true)   { puntajeTotal+=50; cout << "Sacaste Generala sumas 50 puntos!" << endl;
    }else if (poker(vecCant)==true){ puntajeTotal+=40; cout << "Sacaste Poker sumas 40 puntos!" << endl;
    }else if (full(vecCant)==true) { puntajeTotal+=30;  cout << "Sacaste Full sumas 30 puntos!" << endl;
    }else if (escalera(dados)==true) { puntajeTotal+=25;  cout << "Sacaste Escalera sumas 25 puntos!" << endl;
    }else {cout << "NO HAY COMBINACIONES"<<endl<< endl;
    cout << "Ingrese el numero de dado que desea sumar: "<<endl;
    cin>> numDado;
    for(int i=0; i<5; i++){         //acumular numero seleccionado
    if(dados[i] == numDado){
     acum+=numDado;
     }

    }
    cout << "Sacaste juego de "<<numDado<<" sumas "<<acum<<endl;
    puntajeTotal+=acum;

    }
    cout<<"----------------"<<endl;
    cout<<"TERMINO LA RONDA"<<endl;
    system("pause");
    system("cls");

return puntajeTotal;
}





