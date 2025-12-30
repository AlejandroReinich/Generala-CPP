#include <iostream>

using namespace std;



void elejirDados(int dados[]){         //INGRESO MANUAL DE DADOS DEL 1 AL 6

    int numeroDeDado=0;
for(int i=0;i<5;i++){
    numeroDeDado++;
    cout <<"INGRESE UN DADO #"<<numeroDeDado<<endl;
    cin >>dados[i];
    if (dados[i]>6||dados[i]<1) {
        i--;
        numeroDeDado--;
        cout<< "por favor ingre numeros del 1 al 6"<<endl;
    }
    }
    system("cls");
    }

void tiradaDados(int dados[]){

for(int i=0; i<5; i++){
    dados[i] = rand() %6+1;
    }
    }


void mostrarDados(int dados[]){

    cout<<"[";
for(int i=0; i<5; i++){
    cout<<dados[i]<< " ";
    }
    cout<<"]"<<endl<<endl;
    }


void volverATirar(int dados[],int &lanzamiento){ //FUNCION PARA CAMBIAR DADOS

    char opcion;
    int cantidadDeDados,dadoNuevo;


do{
    cout <<endl;
    cout << "-QUIERE VOLVER A TIRAR? (s/n): ";
    cin >> opcion;

if (opcion=='s'|| opcion=='S') {

    cout << "-CUANTOS DADOS VA A TIRAR?"<<endl;
    cin >>cantidadDeDados;
    while(cantidadDeDados<1||cantidadDeDados>5){
    cout<<"Por favor ingrese un numero del 1 al 5"<<endl;
    cout << "-CUANTOS DADOS VA A TIRAR?"<<endl;
    cin >>cantidadDeDados;
    }

    for(int x=0;x<cantidadDeDados;x++){
    cout <<"-CUAL DADO VA A TIRAR ?" <<endl;
    cin >>dadoNuevo;
    while(dadoNuevo<1||dadoNuevo>5){
    cout<<"Por favor ingrese un numero del 1 al 5"<<endl;
    cout <<"-CUAL DADO VA A TIRAR ?" <<endl;
    cin >>dadoNuevo;
    }
    dados[dadoNuevo-1]=rand ()%6+1;

    }

    lanzamiento++;
    cout << "------------------------------------------------------------" << endl;
    cout << "LANZAMIENTO # " << lanzamiento << endl;
    cout << "------------------------------------------------------------" << endl<<endl;

    mostrarDados(dados);
    }

    }
while(lanzamiento!=3 && (opcion=='s'||opcion =='S'));


    }

    //DESEMPATE
    int desempate(string vecNombres[]){

    int dado1,dado2;

    do{
        cout << "=========================================" << endl;
        cout << " DESEMPATE SE TIRA UN DADO GANA EL MAYOR" << endl;
        cout << "=========================================" << endl << endl;
        cout <<"TURNO JUGADOR 1"<<endl;
        system("pause");
        dado1= rand()%6+1;
        cout << vecNombres[0];
        cout <<" SU NUMERO ES:"<<dado1<<endl;

        cout <<"TURNO JUGADOR 2"<<endl;
        system("pause");
        dado2= rand()%6+1;
        cout << vecNombres[2];
        cout <<" SU NUMERO ES:"<<dado2<<endl;


        if(dado1==dado2){
        cout<<"empate nuevamente se vuelve a tirar"<<endl;
        }

    }while(dado1==dado2);

    if(dado1>dado2) {return 1;
    }
    else{ return 2;
    }
    }




