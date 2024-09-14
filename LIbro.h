#pragma once
#include "MaterialBibliografico.h"
using namespace std;
class Libro:public MaterialBibliografico{
    private:
    string fechaPublicacion, resumen;
    public:
        Libro(string nombre,string isbn,string autor,string fechaPublicacion, string resumen);
        void mostrarinformacion();
        
        string getFechaPublicacion();
        string getResumen();
        void setFechaPublicacion(string fechaPublicacion);
        void setResumen(string resumen); 


};