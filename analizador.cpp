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
	
	string tablaSimbolos[500] = {"Mientras","Programa","Fn","Principal","Segun","Caso","Repetir","Definir","Leer","Mostrar","Si","Sino","No","Entero","Cadena","Decimal","Defecto","Hasta","Finrepeticion","Verdadero","Falso"};
	string nombreArchivoEntrada;
	string nombreArchivoSalida;
	string contenido;
	enum TEstado {qe, qa, q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28, q29, q30, q31, q32, q33, q34, q35, q36, q37, q38, q39, q40, q41, q42, q43, q44, q45, q46, q47, q48, q49, q50, q51, q52, q53, q54, q55, q56, q57, q58, q59, q60, q61, q62, q63, q64, q65, q66, q67, q68, q69, q70, q71, q72, q73, q74, q75, q76, q77, q78, q79, q80, q81, q82, q83, q84, q85, q86, q87, q88, q89, q90, q91, q92, q93, q94, q95, q96, q97, q98, q99, q100, q101, q102, q103, q104, q105, q106, q107, q108, q109, q110, q111, q112, q113, q114, q115, q116, q117, q118, q119, q120, q121, q122, q123, q124, q125, q126, q127, q128, q129, q130, q131, q132, q133, q134, q135, q136, q137, q138, q139, q140, q141, q142, q143, q144, q145, q146, q147, q148, q149, q150, q151, q152, q153, q154, q155, q156, q157, q158, q159, q160, q161, q162, q163, q164, q165, q166, q167, q168, q169, q170, q171, q172, q173, q174, q175, q176, q177, q178, q179, q180, q181, q182, q183, q184, q185, q186, q187, q188, q189, q190, q191, q192};
	
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
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
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
				if (simbolo == '{')
					Estado = q5;
				break;
			case q4:
				if (simbolo == '{')
					Estado = q5;
				if (simbolo == ' ')
					Estado = q4;
				break;
			case q5:
				if (simbolo == ' ' || simbolo == '\n')
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
					Estado = q34;
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
				if (simbolo == '(')
					Estado = q12;
				break;
			case q11:
				if (simbolo == ' ')
					Estado = q11;
				if (simbolo == '(')
					Estado = q12;
				break;
			case q12:
				if (simbolo == ' ')
					Estado = q13;
				if (simbolo == ')')
					Estado = q14;
				break;
			case q13:
				if (simbolo == ' ')
					Estado = q13;
				if (simbolo == ')')
					Estado = q14;
				break;
			case q14:
				if (simbolo == ' ')
					Estado = q15;
				if (simbolo == '{')
					Estado = q16;
				break;
			case q15:
				if (simbolo == ' ')
					Estado = q15;
				if (simbolo == '{')
					Estado = q16;
				break;
			case q16:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q17;
				break;
			case q17:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q17;
				if (simbolo >= '-')
					Estado = q18;
				if (simbolo == '}')
					Estado = q32;
				break;
			case q18:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q19;
				break;
			case q19:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q19;
				break;
			case q20:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q28;
				if (simbolo == '\'')
					Estado = q25;
				if (simbolo == '#')
					Estado = q22;
				if (simbolo == ')')
					Estado = q21;
				break;
			case q21:
				if (simbolo == ';')
					Estado = q31;
				break;
			case q22:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q23;
				break;
			case q23:
				if (simbolo == ',')
					Estado = q24;
				if (simbolo == ')')
					Estado = q21;
				break;
			case q24:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q28;
				if (simbolo == '\'')
					Estado = q25;
				if (simbolo == '#')
					Estado = q22;
				break;
			case q25:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q26;
				break;
			case q26:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q26;
				if (simbolo == '\'')
					Estado = q27;
				break;
			case q27:
				if (simbolo == ',')
					Estado = q24;
				if (simbolo == ')')
					Estado = q21;
				break;
			case q28:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q28;
				if (simbolo == ',')
					Estado = q24;
				if (simbolo == ')')
					Estado = q21;
				if (simbolo == '.')
					Estado = q29;
				break;
			case q29:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q30;
				break;
			case q30:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q30;
				if (simbolo == ',')
					Estado = q24;
				if (simbolo == ')')
					Estado = q21;
				break;
			case q31:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q17;
				break;
			case q32:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q33;
				break;
			case q33:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q33;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q7;
				if (simbolo == '}')
					Estado = qa;
				break;
			case q34:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q35;
				break;
			case q35:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q35;
				if (simbolo == ' ')
					Estado = q36;
				break;
			case q36:
				if (simbolo == ' ')
					Estado = q36;
				if (simbolo == '(')
					Estado = q37;	
				break;

			case q37:
				if (simbolo == '#')
					Estado = q40;
				if (simbolo == ')')
					Estado = q38;
				if (simbolo == ' ')
					Estado = q39;
				break;
			case q38:
				if (simbolo == ' ')
					Estado = q38;
				if (simbolo == '{')
					Estado = q46;
				break;
			case q39:
				if (simbolo == ' ')
					Estado = q39;
				if (simbolo == ')')
					Estado = q38;
				if (simbolo == '#')
					Estado = q40;
				break;
			case q40:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q41;
				break;
			case q41:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q41;
				if (simbolo == ')')
					Estado = q38;
				if (simbolo == ',')
					Estado = q42;
				if (simbolo == ' ')
					Estado = q43;
				break;
			case q42:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q43;
				break;



			case q43:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q43;
				if (simbolo == ')')
					Estado = q35;
				if (simbolo == ',')
					Estado = q34;
				break;
			case q44:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q45;
				break;
			case q45:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q39;
				break;
			case q46:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q39;
				if (simbolo == '\'')
					Estado = q40;
				break;
			case q47:
				if (simbolo == ')')
					Estado = q35;
				if (simbolo == ',')
					Estado = q34;
				break;
			case q48:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q41;
				if (simbolo == ')')
					Estado = q35;
				if (simbolo == '.')
					Estado = q42;
				if (simbolo == ',')
					Estado = q34;
				break;
			case q49:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q43;
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


	
//	while (longitud > i){
//		simbolo = contenido[i];
//		if(simbolo == '\n'){
//			cout<<"|";
//		} else if(simbolo == ' ') {
//			cout<<"\\";
//		} else  {
//			cout<<contenido[i];
//		}
//		i++;
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