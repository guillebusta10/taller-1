#pragma once
#include "MaterialBibliografico.h"
using namespace std;
class Usuario{ //crea clase usuario
    private: // crea atributos
        string nombre, id;
        MaterialBibliografico* materialesPrestados[5];
    public: // crea constructor, metodos, gets and sets
        Usuario(string nombre, string id);
        bool prestarMaterial(MaterialBibliografico*material);
        bool devolverMaterial(MaterialBibliografico*material);
        void mostrarMaterialesPrestados();
       

        string getNombre();
        string getId();
        void setNombre(string nombre);
        void setId(string id);





};