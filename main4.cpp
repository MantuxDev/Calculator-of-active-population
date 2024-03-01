//Di N città si conoscono il numero di abitanti
//e il numero di quelli attivi. Calcola per 
//ciascuna città l'indice di attività (attivi/abitanti x100)
//e stampa il nome della città con l'indice più basso e di quella
//con l'indice più alto.

#include<iostream>
#include<cstdlib> //libreria che include system("cls")
#include<iomanip>//libreria che include setprecision

using namespace std;

const int e=100; //dimensione massima del vettore

//prototipi
int menu();
void inserisci( string citta[], int &N);
void abitanti( string citta[], int N, int &j, int &k, float &max, float &min);


int main(){

    string citta[e];
    int scelta,N=0;
    int j,k;
    float max,min;

    do{
        
        scelta=menu();

        switch(scelta){
            
            case 1:{
                inserisci(citta,N);
                break;
            }

            case 2:{
                abitanti(citta,N,j,k,max,min);
                break;
            }

            case 3:{
                cout<<"La citta' con l'indice di attivita' piu' alto e' "<<citta[j]<<" con un indice di attivita' di "<<setprecision(3)<<max<<"%"<<endl;
                cout<<endl;
                cout<<"La citta' con l'indice di attivita' piu' basso e' "<<citta[k]<<" con un indice di attivita' di "<<setprecision(3)<<min<<"%"<<endl;
                cout<<endl;

                cout<<"Premi un tasto per continuare... ";
                cin.ignore();
                cin.get();

                system("cls");
                break;
            }

            case 0:{
                cout<<"Arrivederci"<<endl;
                break;
            }

            default:{
                cout<<"Scelta non valida"<<endl;
                break;
            }
        }

    }while(scelta!=0);


    system("pause");
    return 0;
}

int menu(){

    int scelta;
    
    cout<<"\t -----Menu-----"<<endl;
    cout<<"1) Inserisci le citta'"<<endl;
    cout<<"2) Inserisci il numero di abitanti per citta'"<<endl;
    cout<<"3) Calcola l'indice di attivita'"<<endl;
    cout<<"0) Esci"<<endl;

    cout<<endl;

    cout<<"Inserisci la tua scelta: ";
    cin>>scelta;

    cout<<endl;


    return scelta;

}

void inserisci( string citta[], int &N){

    bool y;

    do{

        y=true; 

        cout<<"Inserisci il numero di citta: ";
        cin>>N;

        if(N>e){
            cout<<"Numero di citta non puo' essere maggiore di "<<e<<endl;
            y=false;
        }

        if(N<0){
            cout<<"Numero di citta non puo' essere minore di 0"<<endl;
            y=false;
        }

    }while(y==false);

    for(int i=0; i<N; i++){
        cout<<"Inserisci il nome della citta' "<<i+1<<": ";
        cin>>citta[i];
    }

    cout<<"Premi un tasto per continuare... ";
    cin.ignore();
    cin.get();

    system("cls");

}

void abitanti( string citta[], int N, int &j, int &k, float &max, float &min){

    double indice;

    int cittadiniOFF,cittadiniON;

    for(int i=0; i<N; i++){

        do{
            cout<<"Inserisci il numero di abitanti a "<<citta[i]<<": ";
            cin>>cittadiniOFF;

            if(cittadiniOFF<0){
                cout<<"Il numero di abitanti non puo' essere minore di 0"<<endl;
            }

        }while(cittadiniOFF<0);

        do{
            cout<<"Inserisci il numero di abitanti attivi a "<<citta[i]<<": ";
            cin>>cittadiniON;

            if(cittadiniON<0){
                cout<<"Il numero di abitanti non puo' essere minore di 0"<<endl;
            }

            else if(cittadiniON>cittadiniOFF){
                cout<<"Il numero di abitanti non puo' essere maggiore di "<<cittadiniOFF<<endl;
            }

            cout<<endl;

        }while(cittadiniON<0 || cittadiniON>cittadiniOFF);

        indice=(float)cittadiniON*100/cittadiniOFF;

        if(i==0){ 
            max=indice;
            min=indice;
            j=i;
            k=i;
        }

        if(indice>max){
            max=indice;
            j=i;
        }

        if(indice<min){
            min=indice;
            k=i;
        }

        cout<<endl;

    }//fine for

    cout<<"Premi un tasto per continuare... ";
    cin.ignore();
    cin.get();

    system("cls");

}
