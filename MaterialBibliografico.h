#pragma once
#include <iostream>
#include <string>
using namespace std;
class MaterialBibliografico{
    protected:
        string nombre,isbn,autor;
        bool prestado;
    public:
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
