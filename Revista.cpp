#include "Revista.h"
#include <iostream>
using namespace std;

Revista::Revista(string nombre,string isbn,string autor,int numeroEdicion, string mesPublicacion):MaterialBibliografico(nombre,isbn,autor){
    this->numeroEdicion=numeroEdicion;
    this->mesPublicacion=mesPublicacion;
}

int Revista::getNumeroEdicion(){
    return numeroEdicion;
}
string Revista::getMesPublicacion(){
    return mesPublicacion;
}
void Revista::setNumeroEdicion(int numeroEdicion){
    this->numeroEdicion=numeroEdicion;
}
void Revista::setMesPublicacion(string mesPublicacion){
    this->mesPublicacion=mesPublicacion;
}
void Revista::mostrarinformacion(){ //muestra la informacion de cada revista
    MaterialBibliografico::mostrarinformacion(); 
    std::cout << "Numero de Edicion: " << numeroEdicion << std::endl;
    std::cout << "Mes: " << mesPublicacion << std::endl;
}