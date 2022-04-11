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
	enum TEstado {qe, qa, q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28, q29, q30, q31, q32, q33, q34, q35, q36, q37, q38, q39, q40, q41, q42, q43, q44, q45, q46, q47, q48, q49, q50, q51, q51, q53, q54, q55, q56, q57, q58, q59, q60, q61, q62, q63, q64, q65, q66, q67, q68, q69, q70};
	
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
				if (simbolo >= 'A' && simbolo <= 'Z'){
					Estado = q3;
				} else if (simbolo == ' '){
					Estado = q2;
				}
				break;
			case q3:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q3;
				if (simbolo == ' ')
					Estado = q4;
				break;
			case q4:
				if (simbolo == '{')
					Estado = q5;
				if (simbolo == ' ')
					Estado = q4;
				break;
			case q5:
				if (simbolo == ' ')
					Estado = q5;
				if (simbolo == '\n')
					Estado = q6;
				break;
			case q6:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q6;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q7;
				break;
			case q7:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q7;
				if (simbolo == ' ')
					Estado = q8;
				break;
			case q8:
				if (simbolo == ' ')
					Estado = q8;
				if (simbolo == '_')
					Estado = q9;
				if (simbolo == '-')
					Estado = q31;
				break;
			case q9:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q10;
				break;
			case q10:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q10;
				if (simbolo == ' ')
					Estado = q11;
				break;
			case q11:
				if (simbolo == ' ')
					Estado = q11;
				if (simbolo == '(')
					Estado = q12;
				break;
			case q12:
				if (simbolo == ' ')
					Estado = q12;
				if (simbolo == ')')
					Estado = q13;
				break;
			case q13:
				if (simbolo == ' ')
					Estado = q13;
				if (simbolo == '{')
					Estado = q14;
				break;


			case q14:
				if (simbolo == ' ')
					Estado = q14;
				if (simbolo == '\n')
					Estado = q15;
				break;
			case q15:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q15;
				if (simbolo == '-')
					Estado = q16;
				if (simbolo == '}')
					Estado = q29;
				break;
			case q16:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q17;
				break;
			case q17:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q17;
				if (simbolo == '(')
					Estado = q18;
				break;
			case q18:
				if (simbolo == ')')
					Estado = q19;
				if (simbolo == '#')
					Estado = q20;
				if (simbolo == '\'')
					Estado = q22;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q25;
				break;
			case q19:
				if (simbolo == ' ')
					Estado = q19;
				if (simbolo == ';')
					Estado = q28;
				break;
			case q20:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q21;
				if (simbolo == ' ')
					Estado = q11;
				break;
			case q21:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q21;
				if (simbolo == ')')
					Estado = q19;
				if (simbolo == ',')
					Estado = q18;
				break;
			case q22:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q23;
				break;
			case q23:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q23;
				if (simbolo == '\'')
					Estado = q24;
				break;
			case q24:
				if (simbolo == ')')
					Estado = q19;
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
