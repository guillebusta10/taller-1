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

/*lee el txt de materiales
@param line crea linea a leer
@param biblioteca[] array de punteros de la biblioteca 
@param contadorMaterial contador de los materiales de la biblioteca
return */
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
/*lee archivo usuario
@param line crea linea a leer
@param usuarios[] array de punteros de los punteros 
@param index posicion y contador de cada usuario, y el cual se va ingresando
return
*/
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
/*busca los materiales por nombre del material 
@param biblioteca[] array de punteros de la biblioteca
@param nomBuscado nombre del material el cual se desea buscar
return
*/
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
/*busca los materiales por nombre del autor 
@param biblioteca[] array de punteros de la biblioteca
@param nomBuscado nombre del autor de el material el cual se desea buscar
return
*/
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
/*muestra todos los materiales del array biblioteca
@param biblioteca[] array de punteros de la biblioteca
return
*/
void mostrarmateriales(MaterialBibliografico* biblioteca[]){
    for(int i=0;i<100;i++){
        if(biblioteca[i]!=nullptr){
            biblioteca[i]->mostrarinformacion();

        }else{
            return;
        }
    }

}
/*busca un usuario de el array usuarios
@param usuarios[] array de punteros de los usuarios 
@param idBuscada id del usuario que se desea buscar
@param max maximo y contador de los usuarios 
return un usuario que se desea buscar
*/
Usuario *buscarUsuario(Usuario *usuarios[], string idBuscada, int max){
    for (int i = 0; i < max; ++i) {
        if (usuarios[i] != nullptr && usuarios[i]->getId() == idBuscada) {
            return usuarios[i]; 
        }
    }
    return nullptr;
}
/*elimina un usuario 
@param usuarios[] array de punteros de los usuarios 
@param idEliminar id del usuario que se desea eliminar
@param max maximo y contador de los usuarios 
return
*/
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
    // Nombres de los archivos para los materiales y usuarios
    string filenameMateriales = "materiales.txt";
    string filenameUsuarios = "usuarios.txt";

    // Inicialización de la biblioteca y los usuarios
    MaterialBibliografico *biblioteca[100]={nullptr};
    int max;// Número máximo de usuarios
    max=0;
    Usuario *usuarios[max]={nullptr};
    
    
    
    int contadorMaterial;// Contador de materiales
    contadorMaterial=0;
    int contadorUsuarios;// Contador de usuarios
    contadorUsuarios=0;
    // Carga de materiales desde el archivo
    ifstream fileMateriales(filenameMateriales);
    string line;

    while (getline(fileMateriales, line)) {
        procesarLinea(line, biblioteca, contadorMaterial);
    }
    fileMateriales.close();

    // Carga de usuarios desde el archivo
    ifstream fileUsuarios(filenameUsuarios);
    while (getline(fileUsuarios, line)) {
        procesarUsuario(line, usuarios, contadorUsuarios);
    }
    fileUsuarios.close();

    // Menú principal de opciones para el usuario
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
        cin.ignore();// Limpiar el buffer de entrada
        switch (opcion){
            case 1:{// Agregar Revista
                string nombre;
                cout<<"ingrese nombre: "<<endl;
                getline(cin, nombre);
                string isbn;
                cout<<"ingrese isbn: "<<endl;
                getline(cin, isbn);
                string autor;
                cout<<"ingrese autor: "<<endl;
                getline(cin, autor);
                int numeroEdicion;
                cout<<"ingrese numero de edicion: "<<endl;
                cin>> numeroEdicion;
                string mes;
                cout<<"ingrese mes de publicacion: "<<endl;
                getline(cin, mes);
                // Creación de la nueva revista    
                biblioteca[contadorMaterial++]=new Revista (nombre,isbn,autor,numeroEdicion,mes);
                // Guardar la revista en el archivo
                ofstream archivo("materiales.txt", ios::app);
                if (archivo.is_open()) {
                    archivo << nombre << "," << isbn << "," << autor << "," << numeroEdicion << "," << mes << endl;
                    archivo.close();
                    cout << "Revista agregada exitosamente." << endl;
                } else {
                    cerr << "No se pudo abrir el archivo materiales.txt." << endl;
                }
                break;
                
            }
            case 2:{// agregar libro
                string nombre;
                cout<<"ingrese nombre: "<<endl;
                getline(cin, nombre);
                string isbn;
                cout<<"ingrese isbn: "<<endl;
                getline(cin, isbn);
                string autor;
                cout<<"ingrese autor: "<<endl;
                getline(cin, autor);
                string fecha;
                cout<<"ingrese fecha de publicacion: "<<endl;
                getline(cin, fecha);
                string resumen;
                cout<<"ingrese resumen: "<<endl;
                getline(cin, resumen);
                //Creación del nuevo libro    
                biblioteca[contadorMaterial++]=new Libro(nombre,isbn,autor,fecha,resumen);
                //Guardar el libro en el archivo
                ofstream archivo("materiales.txt", ios::app);
                if (archivo.is_open()) {
                    archivo << nombre << "," << isbn << "," << autor << "," << fecha << "," << resumen << endl;
                    archivo.close();
                    cout << "Libro agregado exitosamente." << endl;
                } else {
                    cerr << "No se pudo abrir el archivo materiales.txt." << endl;
                }
                
                break;    
            }        
            case 3:{// Mostrar Materiales
                mostrarmateriales(biblioteca);            
                
                break;
            }        
            case 4:{ // Busca material por nombre
                cout<<"Ingrese nombre: "<<endl;
                string nombreBuscado;
                getline(cin, nombreBuscado);
                buscarMaterialnombre(biblioteca,nombreBuscado);


                break;
            }    
            case 5:{// Busca material por autor 
                cout<<"Ingrese autor: "<<endl;
                string autorBuscado;
                getline(cin, autorBuscado);
                buscarMaterialautor(biblioteca,autorBuscado);
                break;
            }     
            case 6:{ // Prestar material
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
            case 7:{ // Devolver material
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
            case 8:{//Agregar un usuario 
            
                string nombre;
                cout<<"ingrese nombre: "<<endl;
                getline(cin, nombre);
                string id;
                cout<<"ingrese id: "<<endl;
                getline(cin, id);
                usuarios[max++]=new Usuario(nombre,id);
                //guardarlo en el archivo
                ofstream archivo("usuarios.txt", ios::app);
                if (archivo.is_open()) {
                    archivo << nombre << "," << id << endl;
                    archivo.close();
                    cout << "Usuario agregado exitosamente." << endl;
                } else {
                    cerr << "No se pudo abrir el archivo usuarios.txt." << endl;
                }
                
                break;
            }    
            case 9:{// Busca usuario 
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
            case 10:{ //Elimina usuario 
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
                //actualiza archivo
                ifstream archivo("usuarios.txt");
                ofstream temp("temp_usuarios.txt");
                string linea;
                bool encontrado = false;

                while (getline(archivo, linea)) {
                    if (linea.find(idEliminar) == string::npos) {
                        temp << linea << endl;
                    } else {
                        encontrado = true;
                    }
                }

                archivo.close();
                temp.close();

                if (encontrado) {
                    remove("usuarios.txt");
                    rename("temp_usuarios.txt", "usuarios.txt");
                    cout << "Usuario eliminado exitosamente." << endl;
                } else {
                    remove("temp_usuarios.txt");
                    cout << "Usuario no encontrado." << endl;
                }
                break;
            }
            case 11:{// salir del sistema
                for (int i = 0; i < 100; ++i) {
                    delete biblioteca[i];//libera memoria 
                }
                
                for (int i = 0; i < max; ++i) {
                    delete usuarios[i]; 
                }
                
                continuar=false;//termina ciclo while
                break;
            }
            default:{
               
                break;
            }    
            
        }
        
        
    }    
    return 0;
          

};