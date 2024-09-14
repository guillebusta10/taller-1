#include "MaterialBibliografico.h"
#include <iostream>
using namespace std;
MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor){
    this->nombre=nombre;
    this->isbn=isbn;
    this->autor=autor;
    this->prestado=false;
    
}

void MaterialBibliografico::mostrarinformacion()
{
    cout << "Nombre: " << nombre << std::endl;
    cout << "ISBN: " << isbn << std::endl;
    cout << "Autor: " << autor << std::endl;
}

bool MaterialBibliografico::estaprestado()
{
    return prestado;
}
void MaterialBibliografico::estaPrestado(bool situacion)
{
    prestado=situacion;
}

string MaterialBibliografico::getNombre(){
    return this->nombre;
}
  
string MaterialBibliografico::getIsbn(){
    return this->isbn;
}
string MaterialBibliografico::getAutor(){
    return this->autor;
}


void MaterialBibliografico::setNombre(string nombre){
    this->nombre=nombre;
}
void MaterialBibliografico::setIsbn(string isbn){
    this->isbn=isbn;
}void MaterialBibliografico::setAutor(string autor){
    this->autor=autor;
}