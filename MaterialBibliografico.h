#pragma once
#include <iostream>
#include <string>
using namespace std;
class MaterialBibliografico{ //crea  clase materialbibliografico
    protected://crear atributos
        string nombre,isbn,autor;
        bool prestado;
    public://crear contructor, metodos, gets and sets 
        MaterialBibliografico(string,string,string);
        virtual void mostrarinformacion();
        bool estaprestado();
        void estaPrestado(bool);
        string getNombre();
        string getIsbn();
        string getAutor();

        void setNombre(string);
        void setIsbn(string);
        void setAutor(string);
};
