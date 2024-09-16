#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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
void procesarLinea(string& line, MaterialBibliografico* biblioteca[], int& contadorMaterial) {
    istringstream iss(line);
    string campo;
    vector<string> campos;

    while (getline(iss, campo, ',')) {
        campos.push_back(campo);
    }

    if (campos.size() == 5) {
        string nombre = campos[0];
        string isbn = campos[1];
        string autor = campos[2];
        string cuartoCampo = campos[3];
        string quintoCampo = campos[4];

        int numeroEdicion;
        try {
            numeroEdicion = std::stoi(cuartoCampo);
            biblioteca[contadorMaterial++] = new Revista(nombre, isbn, autor, numeroEdicion, quintoCampo);
            
        } catch (const std::invalid_argument&) {
            biblioteca[contadorMaterial++] = new Libro(nombre, isbn, autor, cuartoCampo, quintoCampo);
            
        }
    } else {
        std::cerr << "Línea con formato desconocido: " << line << std::endl;
    }
}
void procesarUsuario(string& line, Usuario* usuarios[], int& index) {
    istringstream iss(line);
    string campo;
    vector<string> campos;

    while (getline(iss, campo, ',')) {
        campos.push_back(campo);
    }

    if (campos.size() == 2) {
        string nombre = campos[0];
        string id = campos[1];
        usuarios[index++] = new Usuario(nombre, id);
        
    } else {
        std::cerr << "Línea con formato desconocido en archivo de usuarios: " << line << std::endl;
    }
}
void buscarMaterialnombre(MaterialBibliografico*biblioteca[],string nomBuscado ){
    bool encontrado=false;
    
    for(int i=0; i<100;i++){
        if(biblioteca[i]!=nullptr && biblioteca[i]->getNombre() == nomBuscado){
            biblioteca[i]->mostrarinformacion();
            encontrado=true;
            return;
        }
    }
    if(!encontrado){
        cout<<" no se ha encontrado: "<<nomBuscado<<endl;
        return;
    }
};
void buscarMaterialautor(MaterialBibliografico*biblioteca[],string autorBuscado ){
    bool encontrado=false;
    
    for(int i=0; i<100;i++){
        if(biblioteca[i]!=nullptr && biblioteca[i]->getAutor() == autorBuscado){
            biblioteca[i]->mostrarinformacion();
            encontrado=true;
            return;
        }
    }
    if(!encontrado){
        cout<<" no se ha encontrado: "<<autorBuscado<<endl;
        return;

    }
};


void mostrarmateriales(MaterialBibliografico* biblioteca[]){
    for(int i=0;i<100;i++){
        if(biblioteca[i]!=nullptr){
            biblioteca[i]->mostrarinformacion();

        }else{
            return;
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
    string filenameMateriales = "materiales.txt";
    string filenameUsuarios = "usuarios.txt";

    MaterialBibliografico *biblioteca[100]={nullptr};
    int max;
    max=0;
    Usuario *usuarios[max]={nullptr};
    
    ifstream fileMateriales(filenameMateriales);

    
    int contadorMaterial;
    contadorMaterial=0;
    int contadorUsuarios;
    contadorUsuarios=0;
    
    std::string line;

    while (getline(fileMateriales, line)) {
        procesarLinea(line, biblioteca, contadorMaterial);
    }
    fileMateriales.close();

    ifstream fileUsuarios(filenameUsuarios);
    while (getline(fileUsuarios, line)) {
        procesarUsuario(line, usuarios, contadorUsuarios);
    }
    fileUsuarios.close();


    bool continuar;
    continuar =true;
    while(continuar==true){
        int opcion;
        cout<<"-----------------------------"<<endl;
        cout<<"MENU USUARIO"<<endl;
        cout<<"Ingrese opcion: "<<endl;
        cout<<"1.- AGREGAR LIBRO "<<endl;
        cout<<"2.- AGREGAR REVISTA "<<endl;
        cout<<"3.- MOSTRAR MATERIALES"<<endl;
        cout<<"4.- BUSCAR POR NOMBRE"<<endl;
        cout<<"5.- BUSCAR POR AUTOR"<<endl;
        cout<<"6.- PRESTAR MATERIAL"<<endl;
        cout<<"7.- DEVOLVER MATERIAL"<<endl;
        cout<<"8.- AGREGAR USUARIO "<<endl;
        cout<<"9.- BUSCAR USUARIO "<<endl;
        cout<<"10.- ELIMINAR USUARIO "<<endl;
        cout<<"11.- SALIR "<<endl;
        cout<<"----------------------------"<<endl;
        
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
                biblioteca[contadorMaterial++]=new Revista (nombre,isbn,autor,numeroEdicion,mes);
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
                biblioteca[contadorMaterial++]=new Libro(nombre,isbn,autor,fecha,resumen);
                break;    
            }        
            case 3:{
                mostrarmateriales(biblioteca);            
                
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
                        cout<<"material con isbn: "<<isbnN<<" no encontrado"<<endl;
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
                        cout<<"material con isbn: "<<isbnD<<" no encontrado"<<endl;
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
            case 11:{
                continuar=false;
                break;
            }
            default:{
               
                break;
            }    
            
        }
        
        
    }    
    return 0;
          

};