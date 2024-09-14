#pragma once
#include "MaterialBibliografico.h"  
using namespace std;
class Revista:public MaterialBibliografico{
    private:
    int numeroEdicion;
    string mesPublicacion;
    public:
        Revista(string nombre,string isbn,string autor,int numeroEdicion,string mesPublicacion);
        void mostrarinformacion();
        int getNumeroEdicion();
        string getMesPublicacion();

        void setNumeroEdicion(int numeroEdicion);
        void setMesPublicacion(string mesPublicacion); 

};