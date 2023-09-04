#include <iostream>
#include <conio.h>
using namespace std;

 struct Nodo{
    int dato;
    Nodo*siguiente;
    Nodo*ultimo;
};

//funciones
void InsertarEnlaLista(Nodo*&lista,int);
void ActualizarEnlaLista(Nodo*&lista,int,int);
void Mostrarlista(Nodo*);

    int main(){
        Nodo*lista=NULL;
        Nodo*copialista=NULL;
        int dato,opcion,posicion;


    do{
    std::cout << "MENU" << std::endl;
    std::cout <<"1.INGRESAR DATOS A LA LISTA " << std::endl;
    std::cout <<"2. ACTUALIZAR DATOS DE LA LISTA" << std::endl;
    std::cout <<"3. VER LISTA" << std::endl;
    std::cout <<"4. SALIR" << std::endl;
    cin>>opcion;
    
    switch(opcion){
        case 1:
        std::cout << "Digite un numero" << std::endl;
        cin>>dato;
        InsertarEnlaLista(copialista,dato);
        return;
        
        case 2: 
        int nuevodato;
        std::cout << "Digite el numero" << std::endl;
        cin>>dato;
        std::cout << "Digite el numero por el que lo va a remplazar" << std::endl;
        cin>>nuevodato;
        ActualizarEnlaLista(copialista,dato);
        
        case 3:
        Mostrarlista(copialista);
        
        case 4:
        break;
        
        default{
            std::cout << "Opcion no valida" << std::endl;
        }
    }while(opcion!=4);
    
    return 0;

};

void InsertarEnlaLista(Nodo*&lista,int x){
    Nodo*nodonuevo=new Nodo();
    Nodo*ultimo=lista;
    nodonuevo->dato=x;
    
    if(lista==NULL){
        nodonuevo->siguiente=nodonuevo;
        nodonuevo=lista;
    }else{
        nodonuevo->ultimo=lista;
        while(ultimo->siguiente !=lista){
            ultimo=ultimo->siguiente;
        }
        nodonuevo->siguiente=lista;
        lista=nodonuevo;
        ultimo->siguiente=lista;
    }
    std::cout <<"Se ha insertado el numero "<<x<<" ha la lista"<< std::endl;
   
}

void ActualizarEnlaLista(Nodo*&lista, int x,int nuevodato){
    Nodo*actual=lista;
    bool encontrado=false;
    
    while(actual!=NULL){
        if(actual->dato==x){
            actual->dato=nuevodato;//se actualiza en nuevo dato
            std::cout <<"se a actualizado el dato"<<x<<" y se ha insertado el nuevo dato"<<nuevodato<<" en la lista"<< std::endl;
            encontrado=true;
            return;
        }
        actual=actual->siguiente;
    }
    while(!encontrado){
        std::cout << "el numero no fue actualizado" << std::endl;
    }
}

void Mostrarlista(Nodo*lista){
    Nodo*actual=lista;
    std::cout <<"Lista: " << endl;
    while(actual !=NULL){
        std::cout <<actual->dato<<" ";
        actual=actual->siguiente;
    }
    cout<<endl;
}
