#include "Usuario.h"
#include <iostream>
using namespace std;
Usuario::Usuario(string nombre,string id){
    this->nombre=nombre;
    this->id=id;
    for(int i=0; i<5;i++){
        materialesPrestados[i]=nullptr;

    }

}
bool Usuario::prestarMaterial(MaterialBibliografico*material){ // metodo para prestar material
    for(int i=0;i<5;i++){
        if(materialesPrestados[i]==nullptr){
            if(!material->estaprestado()){
                materialesPrestados[i]=material;
                material->estaPrestado(true);
                return true;

            }
            return false;
        }
    }
    return false;
}

bool Usuario::devolverMaterial(MaterialBibliografico*material){ //metodo para devolver material
    for(int i=0;i<5;i++){
        if(materialesPrestados[i]==material){
            materialesPrestados[i]=nullptr;
            material->estaPrestado(false);
            return true;


        }
    }
    return false;

}
void Usuario::mostrarMaterialesPrestados(){ //mostrar materiales prestados de cada usuario 
    cout<<"Materiales prestados de "<<nombre<<" :"<<endl;
    for(int i=0;i<5;i++){
        if(materialesPrestados[i] !=nullptr){
            cout<<materialesPrestados[i]->getNombre()<<endl;
        }else{
            cout<<"LISTA VACIA"<<endl;
            return;
        }
    }    
}
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getId(){
    return id;
}
void Usuario::setNombre(string nombre)
{
    this->nombre=nombre;
}
void Usuario::setId(string id){
    this->id=id;
}
