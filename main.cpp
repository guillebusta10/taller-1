#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


/*void leerarchivo(string Archivo,MaterialBibliografico* biblioteca[],int cont){
    ifstream archivo(Archivo);
    string linea;
    while(getline(archivo,linea)&&cont<100){
        stringstream s(linea);
        string nombre,isbn,autor,fechapublicacion,resumenMes;
        int numeroEdicion;

        getline(s,nombre,",");
        getline(s,isbn,",");
        getline(s,autor,",");

        if(getline(s,fechapublicacion)){
            getline(s,resumenMes,",");
            biblioteca[cont++]=new Libro(nombre,isbn,autor,fechapublicacion,resumenMes);


            
        }else{
            s.clear();
            s.seekg(0,ios::beg);
            getline(s,nombre,",");
            getline(s,isbn,",");
            getline(s,autor,",");
            getline(s,numeroEdicion,",");
            getline(s,resumenMes,",");

            biblioteca[cont++]=new Revista(nombre,isbn,autor,numeroEdicion,resumenMes);

        }


    }
    archivo.close();
};*/

void buscarMaterialnombre(MaterialBibliografico*biblioteca[],string nomBuscado ){
    bool encontrado=false;
    
    for(int i=0; i<100;i++){
        if(biblioteca[i]!=nullptr && biblioteca[i]->getNombre() == nomBuscado){
            biblioteca[i]->mostrarinformacion();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<<" no se ha encontrado: "<<nomBuscado<<endl;

    }
};
void buscarMaterialautor(MaterialBibliografico*biblioteca[],string autorBuscado ){
    bool encontrado=false;
    
    for(int i=0; i<100;i++){
        if(biblioteca[i]!=nullptr && biblioteca[i]->getAutor() == autorBuscado){
            biblioteca[i]->mostrarinformacion();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<<" no se ha encontrado: "<<autorBuscado<<endl;

    }
};

//void agregarmaterial(MaterialBibliografico *biblioteca[],int cont){


void mostrarMaterial(MaterialBibliografico*biblioteca[]){
    for(int i=0;i<100;i++){
        if(biblioteca[i]!=nullptr){
            biblioteca[i]->mostrarinformacion();
        }
    }
}



Usuario *buscarUsuario(Usuario *usuarios[], string idBuscada, int max){
    for (int i = 0; i < max; ++i) {
        if (usuarios[i] != nullptr && usuarios[i]->getId() == idBuscada) {
            return usuarios[i]; 
        }
    }
    return nullptr;
}

/*void agregarUsuario(Usuario**usuarios,int max){
    string nombre;
    cout<<"ingrese nombre: "<<endl;
    cin >> nombre;
    string id;
    cout<<"ingrese id: "<<endl;
    cin>> id;
    usuarios[max++]=new Usuario(nombre,id);
    cout<<"usuario agregado"<<endl;
}*/

void eliminarUsuario(Usuario*usuarios[],int max, string idEliminar){
    for(int i=0;i<max;i++){
        if(usuarios[i]->getId()==idEliminar){
            for(int j=i;j<max-1;j++){
                usuarios[j]=usuarios[j+1];

            }
            --max;
            cout<<"se elimino el usuario"<<endl;

        }
    }
    
} 
int main(){
    MaterialBibliografico *biblioteca[100];
    int max;
    max=0;
    
    Usuario *usuarios[max];
    
    int cont;
    cont=0;
  
    /*leerarchivo("",biblioteca,cont);*/

    while(true){
        int opcion;
        cout<<"MENU USUARIO"<<endl;
        cout<<"Ingrese opcion: "<<endl;
        cout<<"1.- AGREGAR MATERIAL (Libro) "<<endl;
        cout<<"2.- AGREGAR MAYERIAL (Revista) "<<endl;
        cout<<"3.- MOSTRAR MATERIALES"<<endl;
        cout<<"4.- BUSCAR POR NOMBRE"<<endl;
        cout<<"5.- BUSCAR POR AUTOR"<<endl;
        cout<<"6.- PRESTAR MATERIAL"<<endl;
        cout<<"7.- DEVOLVER MATERIAL"<<endl;
        cout<<"8.- AGREGAR USUARIO "<<endl;
        cout<<"9.- BUSCAR USUARIO "<<endl;
        cout<<"10.- ELIMINAR USUARIO "<<endl;
        
        cin>>opcion;
        cin.ignore();
        switch (opcion){
            case 1:{
                string nombre;
                cout<<"ingrese nombre: "<<endl;
                cin >> nombre;
                string isbn;
                cout<<"ingrese isbn: "<<endl;
                cin>> isbn;
                string autor;
                cout<<"ingrese autor: "<<endl;
                cin>> autor;
                int numeroEdicion;
                cout<<"ingrese numero de edicion: "<<endl;
                cin>> numeroEdicion;
                string mes;
                cout<<"ingrese mes de publicacion: "<<endl;
                cin >> mes;    
                biblioteca[cont++]=new Revista (nombre,isbn,autor,numeroEdicion,mes);
                break;
                
            }
            case 2:{
                string nombre;
                cout<<"ingrese nombre: "<<endl;
                cin >> nombre;
                string isbn;
                cout<<"ingrese isbn: "<<endl;
                cin>> isbn;
                string autor;
                cout<<"ingrese autor: "<<endl;
                cin>> autor;
                string fecha;
                cout<<"ingrese fecha de publicacion: "<<endl;
                cin>> fecha;
                string resumen;
                cout<<"ingrese resumen: "<<endl;
                cin >> resumen;    
                biblioteca[cont++]=new Libro(nombre,isbn,autor,fecha,resumen);
                break;    
            }        
            case 3:{
                mostrarMaterial(biblioteca);
                
                break;
            }        
            case 4:{
                cout<<"Ingrese nombre: "<<endl;
                string nombreBuscado;
                cin>> nombreBuscado;
                buscarMaterialnombre(biblioteca,nombreBuscado);


                break;
            }    
            case 5:{
                cout<<"Ingrese autor: "<<endl;
                string autorBuscado;
                cin>> autorBuscado;
                buscarMaterialautor(biblioteca,autorBuscado);
                break;
            }     
            case 6:{
                string idNueva;
                cout<<"ingrese id: "<<endl;
                cin>>idNueva;
                Usuario*usuario= buscarUsuario(usuarios,idNueva,max);
                if(usuario){
                    bool MaterialE=false;
                    string isbnN;
                    cout<<"ingrese isbn: "<<endl;
                    cin>>isbnN;
                    for(int i=0;i<100;i++){
                        if(biblioteca[i]!=nullptr && biblioteca[i]->getIsbn()==isbnN){
                            if(usuario->prestarMaterial(biblioteca[i])){
                                
                                cout<<"material prestado exitosamente"<<endl;

                            }else{
                                cout<<"el material ya esta prestado"<<endl;

                            }
                            MaterialE=true;
                            break;
                        }


                    }
                    if(!MaterialE){
                        cout<<"material con isbn: "<<isbnN<<"no encontrado"<<endl;
                    }
                }else{
                    cout<<"usuario no encontrado"<<endl;
                }
                break;
            }
            case 7:{
                string IdN;
                cout<<"ingrese id: "<<endl;
                cin>>IdN;
                Usuario*usua= buscarUsuario(usuarios,IdN,max);
                if(usua){ 
                    bool MaterialD=false;
                    string isbnD;
                    cout<<"ingrese isbn: "<<endl;
                    cin>>isbnD;  
                    for(int i=0;i<100;i++){
                        if(biblioteca[i]!=nullptr && biblioteca[i]->getIsbn()==isbnD){
                            if(usua->devolverMaterial(biblioteca[i])){
                                cout<<"material prestado exitosamente"<<endl;

                            }else{
                                cout<<"el material ya esta prestado"<<endl;
                            }
                            MaterialD=true;
                            break;
                        }


                    }
                    if(!MaterialD){
                        cout<<"material con isbn: "<<isbnD<<"no encontrado"<<endl;
                    }
                }else{
                    cout<<"Usuario no encontrado"<<endl;

                }
                break;
            }    
            case 8:{
            
                string nombre;
                cout<<"ingrese nombre: "<<endl;
                cin >> nombre;
                string id;
                cout<<"ingrese id: "<<endl;
                cin>> id;
                usuarios[max++]=new Usuario(nombre,id);
                cout<<"usuario agregado"<<endl;
                break;
            }    
            case 9:{
                string idN;
                cout<<"ingrese id: "<<endl;
                cin>>idN;
                Usuario *Ubuscado=buscarUsuario(usuarios,idN,max);
                if(Ubuscado==nullptr){
                    cout<<"el usuario no existe en el sistema"<<endl;

                }else{
                    Ubuscado->mostrarMaterialesPrestados();
                
                }
                break;
            }    
            case 10:{
                string idEliminar;
                cout<<"ingrese id de usuario que desea eliminar: "<<endl;
                cin>>idEliminar;
                ///eliminarUsuario(usuarios,max,idEliminar);
                for(int i=0;i<max;i++){
                if(usuarios[i]->getId()==idEliminar){
                    for(int j=i;j<max-1;j++){
                        usuarios[j]=usuarios[j+1];

                    }
                    --max;
                    cout<<"se elimino el usuario"<<endl;

                }
            }
                break;
            }
            default:
               
                break;
            
        }
        
        
    }    
    return 0;
          

};