#include "Libro.h"
#include <iostream>
using namespace std;
Libro::Libro(string nombre,string isbn,string autor,string fechaPublicacion, string resumen):MaterialBibliografico(nombre,isbn,autor){
    this->fechaPublicacion=fechaPublicacion;
    this->resumen=resumen;


}


string Libro::getFechaPublicacion(){
    return fechaPublicacion;
}
string Libro::getResumen(){
    return resumen;
}

void Libro::setFechaPublicacion(string fechaPublicacion){
    this->fechaPublicacion=fechaPublicacion;
}
void Libro::setResumen(string resumen){
    this->resumen=resumen;
}
void Libro::mostrarinformacion(){ //muestra la informacion de cada revista
    MaterialBibliografico::mostrarinformacion(); 
    std::cout << "Fecha: " << fechaPublicacion << std::endl;
    std::cout << "Resumen: " << resumen << std::endl;
}