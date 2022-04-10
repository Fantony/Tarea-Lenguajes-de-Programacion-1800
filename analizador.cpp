#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

void mensajeBienvenida();
string obtenerPalabra(string instruccion);
string leerArchivo(string archivoLectura);

//ifstream archivo("documento.txt");

int main(int argc[], char *argv[]){
	
	string tablaSimbolos[500] = {"Mientras","Programa","Fn","Principal","Segun","Caso","Para","Repeticion","Definir","Leer","Mostrar","Si","Sino","Entonces","Entero","Cadena","Decimal"};
	string nombreArchivoEntrada;
	string nombreArchivoSalida;
	string contenido;
	enum TEstado {qe, qa, q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13};
	
	TEstado Estado;
	
	int simbolo,i,longitud,numeroLinea;
	Estado = q0;
	
	mensajeBienvenida();
	cout<<"Argumentos: ";
	getline(cin,nombreArchivoEntrada);
	contenido = leerArchivo(nombreArchivoEntrada);
	
	
	i = numeroLinea = 0;
	longitud = contenido.size();
	while (longitud > i and Estado != qe ){
		simbolo = contenido[i];
		if (simbolo == '\n'){
			numeroLinea++;
		}
		switch (Estado){
			case q0:
				if (simbolo >= 'A' && simbolo <= 'Z'){
					Estado = q1;
				} else {
					cout<<"Error en la l�nea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q1:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q1;
				if (simbolo == ' ')
					Estado = q2;
				break;
			case q2:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q3:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q4:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q5:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q6:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q7:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q8:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q9:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q10:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q11:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q12:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			case q13:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q1;
				break;
			
		}
	}
	
	if(Estado == qa){
		cout<<"Programa en estado de aceptaci�n"<<endl;
		int j;
		int tamanoArreglo = sizeof tablaSimbolos / sizeof tablaSimbolos[0];
		for( j=0 ; j < tamanoArreglo; j++){
			if(contenido.compare(tablaSimbolos[j]) == 0 ) {
				cout<<"Es Una Palabra Reservada del Lenguaje"<<contenido;
				break;
			}
		}
	} else {
		cout<<"Programa no es aceptado"<<contenido;
	}


//	int indice = 0;
//	while(indice < cadenaLinea.size()){
//		if(cadenaLinea[indice] == '\n'){
//			cout<<"Felicidades";
//		} else if (cadenaLinea[indice] == ' ') {
//			cout<<"\tEspaciado";
//			
//		}
//		 else {
//			cout<<cadenaLinea[indice]<<endl;
//		}
//		indice++;
//	}

    system("pause");
    return 0;
}


string leerArchivo(std::string archivoLectura){
    string textoLeido;
    string Linea;
    
    ifstream archivo;
    archivo.open(archivoLectura.c_str());
    
    //Verificar si el archivo existe o no existe dentro del directorio, si no podria no funcionar el programa
    
    while (getline(archivo, Linea)) {
		textoLeido += Linea;
		textoLeido += "\n";
	}
	
	return textoLeido;
}

string obtenerPalabra(string instruccion){
}

void mensajeBienvenida(){
	cout<<"Analizador Lexico"<<endl;
	cout<<"------------------"<<endl;
    cout<<"Bienvenido al Analizador Lexico, ingrese el nombre del archivo de lectura, opcionalmente puede ingresar"<<endl;
    cout<<"un segundo argumento (el nombre que desea darle al archivo de salida)"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;

}
