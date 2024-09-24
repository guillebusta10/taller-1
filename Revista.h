#pragma once
#include "MaterialBibliografico.h"  
using namespace std;
class Revista:public MaterialBibliografico{//crea  clase revista
    private://crea atributos
    int numeroEdicion;
    string mesPublicacion;
    public://crear contructor, metodos, gets and sets 
        Revista(string nombre,string isbn,string autor,int numeroEdicion,string mesPublicacion);
        void mostrarinformacion();
        int getNumeroEdicion();
        string getMesPublicacion();

        void setNumeroEdicion(int numeroEdicion);
        void setMesPublicacion(string mesPublicacion); 

};