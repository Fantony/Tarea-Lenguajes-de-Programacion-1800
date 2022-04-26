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
	enum TEstado {qe, qa, q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28, q29, q30, q31, q32, q33, q34, q35, q36, q37, q38, q39, q40, q41, q42, q43, q44, q45, q46, q47, q48, q49, q50, q51, q52, q53, q54, q55, q56, q57, q58, q59, q60, q61, q62, q63, q64, q65, q66, q67, q68, q69, q70, q71, q72, q73, q74, q75, q76, q77, q78, q79, q80, q81, q82, q83, q84, q85, q86, q87, q88, q89, q90, q91, q92, q93, q94, q95, q96, q97, q98, q99, q100, q101, q102, q103, q104, q105, q106, q107, q108, q109, q110, q111, q112, q113, q114, q115, q116, q117, q118, q119, q120, q121, q122, q123, q124, q125, q126, q127, q128, q129, q130, q131, q132, q133, q134, q135, q136, q137, q138, q139, q140, q141, q142, q143, q144, q145, q146, q147, q148, q149, q150, q151, q152, q153, q154, q155, q156, q157, q158, q159, q160, q161, q162, q163, q164, q165, q166, q167, q168, q169, q170, q171, q172, q173, q174, q175, q176, q177, q178, q179, q180, q181, q182, q183, q184, q185, q186, q187, q188, q189, q190, q191, q192,qn};
	
	TEstado Estado;
	
	int simbolo,i,longitud,numeroLinea;
	Estado = q0;
	
	mensajeBienvenida();
	cout<<"Argumentos: ";
	getline(cin,nombreArchivoEntrada);
	contenido = leerArchivo(nombreArchivoEntrada);
	
	
	i = numeroLinea = 0;
	longitud = contenido.size();
	while (longitud > i and Estado != qe and Estado != qa ){
		simbolo = contenido[i];
		if (simbolo == '\n'){
			numeroLinea++;
		}
		switch (Estado){
			case q0:
				if (simbolo >= 'A' && simbolo <= 'Z'){
					Estado = q1;
				} else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q1:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q1;
				else if (simbolo == ' ')
					Estado = q2;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q2:
				if (simbolo >= 'A' && simbolo <= 'Z'){
					Estado = q3;
				} else if (simbolo == ' '){
					Estado = q2;
				} else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q3:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q3;
				else if (simbolo == ' ')
					Estado = q4;
				else if (simbolo == '{')
					Estado = q5;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q4:
				if (simbolo == '{')
					Estado = q5;
				else if (simbolo == ' ')
					Estado = q4;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q5:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q6;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q6:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q6;
				else if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q7;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q7:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q7;
				else if (simbolo == ' ')
					Estado = q8;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q8:
				if (simbolo == ' ')
					Estado = q8;
				else if (simbolo == '_')
					Estado = q9;
				else if (simbolo == '-')
					Estado = q34;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
				break;
			case q9:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q10;
				else {
					Estado = qe;
					cout<<"Error en la linea: "<<numeroLinea<<", Sintaxis del programa erronea"<<endl;
				}
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
				if (simbolo == ' ')
					Estado = q42;
				if (simbolo == '#')
					Estado = q40;
				break;
			case q43:
				if (simbolo == ' ')
					Estado = q43;
				if (simbolo == ',')
					Estado = q42;
				if (simbolo == ')')
					Estado = q38;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q44;
				break;
			case q44:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z')
					Estado = q44;
				if (simbolo == ',')
					Estado = q42;
				if (simbolo == ')')
					Estado = q38;
				if (simbolo == ' ')
					Estado = q45;
				break;
			case q45:
				if (simbolo == ' ')
					Estado = q45;
				if (simbolo == ',')
					Estado = q42;
				if (simbolo == ')')
					Estado = q38;
				break;
			case q46:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q47;
				break;
			case q47:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q47;
				if (simbolo == '#')
					Estado = q48;
				if (simbolo == '-')
					Estado = q88;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q101;
				if (simbolo == '}')
					Estado = q33;
				break;
			case q48:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q49;
				break;
			case q49:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q49;
				if (simbolo == '=')
					Estado = q68;
				if (simbolo == ' ')
					Estado = q50;
				if (simbolo == '-')
					Estado = q53;
				if (simbolo == '*' || simbolo == '/' || simbolo == '%')
					Estado = q52;
				if (simbolo == '+')
					Estado = q51;
				break;


			case q50:
				if (simbolo == '=')
					Estado = q68;
				if (simbolo == ' ')
					Estado = q50;
				if (simbolo == '-')
					Estado = q53;
				if (simbolo == '*' || simbolo == '/' || simbolo == '%')
					Estado = q52;
				if (simbolo == '+')
					Estado = q51;
				break;
			case q51:
				if (simbolo == '=')
					Estado = q58;
				if (simbolo == '+')
					Estado = q54;
				break;
			case q52:
				if (simbolo == '=')
					Estado = q58;
				break;
			case q53:
				if (simbolo == '=')
					Estado = q58;
				if (simbolo == '-')
					Estado = q56;
				break;
			case q54:
				if (simbolo == ' ')
					Estado = q55;
				if (simbolo == ';')
					Estado = q57;
				break;
			case q55:
				if (simbolo == ' ')
					Estado = q55;
				if (simbolo == ';')
					Estado = q57;
				break;
			case q56:
				if (simbolo == ' ')
					Estado = q55;
				if (simbolo == ';')
					Estado = q57;
				break;
			case q57:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q47;
				break;
			case q58:
				if (simbolo == ' ')
					Estado = q58;
				if (simbolo == '#')
					Estado = q59;
				if (simbolo == '\'')
					Estado = q61;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q65;
				break;
			case q59:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q60;
				break;
			case q60:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q60;
				if (simbolo == ';')
					Estado = q64;
				break;
			case q61:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q62;
				break;
			case q62:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q62;
				if (simbolo == '\'')
					Estado = q63;
				break;
			case q63:
				if (simbolo == ';')
					Estado = q64;
				break;
			case q64:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q47;
				break;
			case q65:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q65;
				if (simbolo == ';')
					Estado = q64;
				if (simbolo == '.')
					Estado = q66;
				break;
			case q66:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q67;
				break;
			case q67:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q67;
				if (simbolo == ';')
					Estado = q64;
				break;
			case q68:
				if (simbolo == ' ')
					Estado = q68;
				if (simbolo == '#')
					Estado = q69;
				if (simbolo == '\'')
					Estado = q81;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q74;
				break;
			case q69:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q70;
				break;
			case q70:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q70;
				if (simbolo == ' ')
					Estado = q71;
				if (simbolo == '+')
					Estado = q73;
				if (simbolo == ';')
					Estado = q64;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/')
					Estado = q72;
				break;
			case q71:
				if (simbolo == ' ')
					Estado = q71;
				if (simbolo == '+')
					Estado = q73;
				// if (simbolo == ';')
				// 	Estado = q64;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/')
					Estado = q72;
				if (simbolo == ' ')
					Estado = q71;
				break;
			case q72:
				if (simbolo == ' ')
					Estado = q72;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q74;
				if (simbolo == '#')
					Estado = q77;
				break;
			case q73:
				if (simbolo == ' ')
					Estado = q73;
				if (simbolo == '#')
					Estado = q77;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q74;
				if (simbolo == '\'')
					Estado = q81;
				break;
			case q74:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q74;
				if (simbolo == ' ')
					Estado = q75;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q76;
				if (simbolo == '.')
					Estado = q79;
				if (simbolo == ';')
					Estado = q64;
				break;
			case q75:
				if (simbolo == ' ')
					Estado = q75;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q76;	
				if (simbolo == ';')
					Estado = q64;
				break;
			case q76:
				if (simbolo == ' ')
					Estado = q76;
				if (simbolo >= '#')
					Estado = q77;
				break;
			case q77:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q78;
				break;
			case q78:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q78;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q76;	
				if (simbolo == ';')
					Estado = q64;
				if (simbolo == ' ')
					Estado = q75;
				break;
			case q79:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q80;
				break;
			case q80:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q80;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q76;	
				if (simbolo == ';')
					Estado = q64;
				if (simbolo == ' ')
					Estado = q75;
				break;
			case q81:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q82;
				break;
			case q82:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q82;
				if (simbolo == '\'')
					Estado = q83;
				break;
			case q83:
				if (simbolo == ';')
					Estado = q64;
				if (simbolo == ' ')
					Estado = q84;
				if (simbolo == '+')
					Estado = q85;
				break;
			case q84:
				if (simbolo == ' ')
					Estado = q84;
				if (simbolo == ';')
					Estado = q64;
				if (simbolo == '+')
					Estado = q85;
				break;
			case q85:
				if (simbolo == ' ')
					Estado = q85;
				if (simbolo >= '#')
					Estado = q86;
				if (simbolo == '\'')
					Estado = q81;
				break;
			case q86:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q87;
				break;
			case q87:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q87;
				if (simbolo == '+')
					Estado = q85;
				if (simbolo == ' ')
					Estado = q84;
				if (simbolo == ';')
					Estado = q64;
				break;
			case q88:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q89;
				break;
			case q89:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q89;
				if (simbolo == ' ')
					Estado = q90;
				if (simbolo == '(')
					Estado = q91;
				break;
			case q90:
				if (simbolo == ' ')
					Estado = q90;
				if (simbolo == '(')
					Estado = q91;
				break;
			case q91:
				if (simbolo == ')')
					Estado = q92;
				if (simbolo == '#')
					Estado = q93;
				if (simbolo == '\'')
					Estado = q95;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q98;
				break;
			case q92:
				if (simbolo == ' ')
					Estado = q92;
				if (simbolo == ';')
					Estado = q64;
				break;
			case q93:
				if (simbolo >= 'A' && simbolo == 'Z')
					Estado = q94;
				break;
			case q94:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q94;
				if (simbolo == ',')
					Estado = q91;
				if (simbolo >= ')')
					Estado = q92;
				break;
			case q95:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q96;
				break;
			case q96:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q94;
				if (simbolo == '\'')
					Estado = q97;
				break;
			case q97:
				if (simbolo == ',')
					Estado = q91;
				if (simbolo == ')')
					Estado = q92;
				break;
			case q98:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q98;
				if (simbolo == ',')
					Estado = q91;
				if (simbolo == ')')
					Estado = q92;
				if (simbolo == '.')
					Estado = q99;
				break;
			case q99:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q100;
				break;
			case q100:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q100;
				if (simbolo == ')')
					Estado = q92;
				break;
			case q101:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q101;
				if (simbolo == ' ')
					Estado = q102;
				if (simbolo == '(')
					Estado = q108;
				break;
			case q102:
				if (simbolo == ' ')
					Estado = q102;
				if (simbolo == ' ')
					Estado = q103;
				if (simbolo == '(')
					Estado = q108;
				break;
			case q103:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q104;
				break;
			case q104:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q104;
				if (simbolo == ' ')
					Estado = q105;
				if (simbolo == ';')
					Estado = q107;
				if (simbolo == ',')
					Estado = q102;
				break;
			case q105:
				if (simbolo == ' ')
					Estado = q105;
				if (simbolo == ',')
					Estado = q102;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q106;
				break;
			case q106:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q106;
				if (simbolo == ';')
					Estado = q107;
				if (simbolo == ',')
					Estado = q102;
				break;
			case q107:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q47;	
				break;
			case q108:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q112;
				if (simbolo == '#')
					Estado = q110;
				if (simbolo == ' ')
					Estado = q109;
				break;
			case q109:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q112;
				if (simbolo == '#')
					Estado = q110;
				if (simbolo == ' ')
					Estado = q109;
				break;
			case q110:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q111;
				break;
			case q111:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q111;
				if (simbolo == '<' || simbolo <= '>')
					Estado = q117;
				if (simbolo == '=' || simbolo <= '!')
					Estado = q119;
				if (simbolo == ' ')
					Estado = qn;
				break;
			case qn:
				if (simbolo == '<' || simbolo <= '>')
					Estado = q117;
				if (simbolo == '=' || simbolo <= '!')
					Estado = q119;
				break;
			case q112:
				if (simbolo == '<' || simbolo <= '>')
					Estado = q117;
				if (simbolo == '=' || simbolo <= '!')
					Estado = q119;
				if (simbolo == ' ')
					Estado = q113;
				if (simbolo == '.')
					Estado = q114;
				break;
			case q113:
				if (simbolo == '<' || simbolo <= '>')
					Estado = q117;
				if (simbolo == '=' || simbolo <= '!')
					Estado = q119;
				if (simbolo == ' ')
					Estado = q113;
				break;
			case q114:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q115;
				break;
			case q115:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q115;
				if (simbolo == '<' || simbolo <= '>')
					Estado = q117;
				if (simbolo == '=' || simbolo <= '!')
					Estado = q119;
				if (simbolo == ' ')
					Estado = q116;
				break;
			case q116:
				if (simbolo == '<' || simbolo <= '>')
					Estado = q117;
				if (simbolo == '=' || simbolo <= '!')
					Estado = q119;
				if (simbolo == ' ')
					Estado = q116;
				break;
			case q117:
				if (simbolo == '=')
					Estado = q118;
				if (simbolo == ' ')
					Estado = q120;
				if (simbolo == '#')
					Estado = q123;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q121;
				break;
			case q118:
				if (simbolo == ' ')
					Estado = q118;
				if (simbolo == '#')
					Estado = q123;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q121;
				break;
			case q119:
				if (simbolo == '=')
					Estado = q122;
				break;
			case q120:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q87;
				break;
			case q121:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q121;
				if (simbolo == ')')
					Estado = q128;
				if (simbolo == '.')
					Estado = q124;
				if (simbolo == ' ')
					Estado = q126;
				break;
			case q122:
				if (simbolo == ' ')
					Estado = q122;
				if (simbolo == '#')
					Estado = q123;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q121;
				break;
			case q123:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q127;
				break;
			case q124:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q125;
				break;
			case q125:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q125;
				if (simbolo == ')')
					Estado = q128;
				if (simbolo == ' ')
					Estado = q126;
				break;
			case q126:
				if (simbolo == ')')
					Estado = q128;
				if (simbolo == ' ')
					Estado = q126;
				break;
			case q127:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q127;
				if (simbolo == ' ')
					Estado = q126;
				if (simbolo == ')')
					Estado = q128;
				break;
			case q128:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q129;
				if (simbolo == '{')
					Estado = q130;
				break;
			case q129:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q129;
				if (simbolo == '{')
					Estado = q130;
				break;
			case q130:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q131;
				break;
			case q131:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q131;
				if (simbolo == '#')
					Estado = q132;
				if (simbolo == '-')
					Estado = q172;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q186;
				if (simbolo == '}')
					Estado = q47;
				break;
			case q132:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q133;
				break;
			case q133:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q133;
				if (simbolo == '+')
					Estado = q136;
				if (simbolo == '-')
					Estado = q138;
				if (simbolo == ' ')
					Estado = q135;
				if (simbolo == '%' || simbolo == '*' || simbolo == '/')
					Estado = q137;
				if (simbolo == '=')
					Estado = q134;
				break;
			case q134:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q158;
				if (simbolo == '#')
					Estado = q152;
				if (simbolo == ' ')
					Estado = q134;
				if (simbolo == '\'')
					Estado = q165;
				break;
			case q135:
				if (simbolo == '+')
					Estado = q136;
				if (simbolo == '-')
					Estado = q138;
				if (simbolo == ' ')
					Estado = q135;
				if (simbolo == '%' || simbolo == '*' || simbolo == '/')
					Estado = q137;
				if (simbolo == '=')
					Estado = q134;
				break;
			case q136:
				if (simbolo == '+')
					Estado = q139;
				if (simbolo == '=')
					Estado = q143;
				break;
			case q137:
				if (simbolo == '=')
					Estado = q143;
				break;
			case q138:
				if (simbolo == '-')
					Estado = q141;
				if (simbolo == '=')
					Estado = q143;
				break;
			case q139:
				if (simbolo == ' ')
					Estado = q140;
				if (simbolo == ';')
					Estado = q142;
				break;
			case q140:
				if (simbolo == ' ')
					Estado = q140;
				if (simbolo == ';')
					Estado = q142;
				break;
			case q141:
				if (simbolo == ' ')
					Estado = q140;
				if (simbolo == ';')
					Estado = q142;
				break;
			case q142:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q131;
				break;
			case q143:
				if (simbolo == ' ')
					Estado = q143;
				if (simbolo == '#')
					Estado = q144;
				if (simbolo == '\'')
					Estado = q146;
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q149;
				break;
			case q144:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q145;
				break;
			case q145:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q145;
				if (simbolo >= ';')
					Estado = q157;
				break;
			case q146:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q147;
				break;
			case q147:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q147;
				if (simbolo == '\'')
					Estado = q148;
				break;
			case q148:
				if (simbolo == ';')
					Estado = q157;
				break;
			case q149:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q149;
				if (simbolo == '.')
					Estado = q150;
				if (simbolo == ';')
					Estado = q157;
				break;
			case q150:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q151;
				break;
			case q151:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q151;
				if (simbolo == ';')
					Estado = q157;
				break;
			case q152:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q127;
				break;
			case q153:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q153;
				if (simbolo == ';')
					Estado = q157;
				if (simbolo == '+')
					Estado = q156;
				if (simbolo == ' ')
					Estado = q154;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/')
					Estado = q155;
				break;
			case q154:
				if (simbolo == '+')
					Estado = q156;
				if (simbolo == ' ')
					Estado = q154;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/')
					Estado = q155;
				break;
			case q155:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q158;
				if (simbolo == '#')
					Estado = q161;
				if (simbolo == ' ')
					Estado = q155;
				break;
			case q156:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q158;
				if (simbolo == '#')
					Estado = q161;
				if (simbolo == ' ')
					Estado = q156;
				if (simbolo == '\'')
					Estado = q165;
				break;
			case q157:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q131;
				break;
			case q158:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q158;
				if (simbolo == ' ')
					Estado = q159;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q160;
				if (simbolo == '.')
					Estado = q163;
				if (simbolo == ';')
					Estado = q157;
				break;
			case q159:
				if (simbolo == ' ')
					Estado = q159;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q160;
				if (simbolo == ';')
					Estado = q157;
				break;
			case q160:
				if (simbolo == ' ')
					Estado = q160;
				if (simbolo == '#')
					Estado = q161;
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q158;
				break;
			case q161:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q162;
				break;
			case q162:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q162;
				if (simbolo == ';')
					Estado = q157;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q160;
				if (simbolo == ' ')
					Estado = q159;
				break;
			case q163:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q164;
				break;
			case q164:
				if (simbolo >= '0' && simbolo <= '9')
					Estado = q164;
				if (simbolo == ' ')
					Estado = q159;
				if (simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '+')
					Estado = q160;
				if (simbolo == ';')
					Estado = q157;
				break;
			case q165:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q166;
				break;
			case q166:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q166;
				if (simbolo == '\'')
					Estado = q167;
				break;
			case q167:
				if (simbolo == ';')
					Estado = q157;
				if (simbolo == ' ')
					Estado = q168;
				if (simbolo == '+')
					Estado = q169;
				break;
			case q168:
				if (simbolo == ' ')
					Estado = q168;
				if (simbolo == ';')
					Estado = q157;
				if (simbolo == '+')
					Estado = q169;
				break;
			case q169:
				if (simbolo == ' ')
					Estado = q169;
				if (simbolo == '\'')
					Estado = q165;
				if (simbolo == '#')
					Estado = q170;
				break;
			case q170:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q171;
				break;
			case q171:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q171;
				if (simbolo == '+')
					Estado = q169;
				if (simbolo == ' ')
					Estado = q168;
				if (simbolo == ';')
					Estado = q157;
				break;
			case q172:
				if (simbolo >= 'A' && simbolo >= 'Z')
					Estado = q173;
				break;
			case q173:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q173;
				if (simbolo == ' ')
					Estado = q174;
				if (simbolo == '{')
					Estado = q175;
				break;
			case q174:
				if (simbolo == ' ')
					Estado = q174;
				if (simbolo == '{')
					Estado = q175;
				break;
			case q175:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q182;
				if (simbolo == '\'')
					Estado = q179;
				if (simbolo == '#')
					Estado = q177;
				if (simbolo == ')')
					Estado = q176;
				break;
			case q176:
				if (simbolo == ' ')
					Estado = q176;
				if (simbolo == ';')
					Estado = q185;
				break;
			case q177:
				if (simbolo >= 'A' && simbolo >= 'Z')
					Estado = q178;
				break;
			case q178:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q178;
				if (simbolo == ',')
					Estado = q175;
				if (simbolo == ')')
					Estado = q176;
				break;
			case q179:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q180;
				break;
			case q180:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q180;
				if (simbolo == '\'')
					Estado = q181;
				break;
			case q181:
				if (simbolo == '\'')
					Estado = q175;
				if (simbolo == ')')
					Estado = q176;
				break;
			case q182:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q182;
				if (simbolo == ',')
					Estado = q175;
				if (simbolo == ')')
					Estado = q176;
				if (simbolo == '.')
					Estado = q183;
				break;
			case q183:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q184;
				break;
			case q184:
				if (simbolo >= '0' && simbolo >= '9')
					Estado = q184;
				if (simbolo == ')')
					Estado = q176;
				break;
			case q185:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q131;
				break;
			case q186:
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q186;
				if (simbolo == ' ')
					Estado = q187;
				break;
			case q187:
				if (simbolo == ' ')
					Estado = q187;
				if (simbolo == '#')
					Estado = q188;
				break;
			case q188:
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q189;
				break;


			case q189:
				if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
					Estado = q189;
				if (simbolo == ' ')
					Estado = q190;
				if (simbolo == ';')
					Estado = q192;
				if (simbolo == ',')
					Estado = q187;
				break;
			case q190:
				if (simbolo == ' ')
					Estado = q190;
				if (simbolo == ',')
					Estado = q187;
				if (simbolo >= 'A' && simbolo <= 'Z')
					Estado = q191;
				break;
			case q191:
				if (simbolo == ';')
					Estado = q192;
				if (simbolo == ',')
					Estado = q187;
				if (simbolo >= 'a' && simbolo <= 'z')
					Estado = q191;
				break;
			case q192:
				if (simbolo == ' ' || simbolo == '\n')
					Estado = q131;
				break;





			// case q193:
			// 	if (simbolo == ' ')
			// 		Estado = q140;
			// 	if (simbolo == ';')
			// 		Estado = q142;
			// 	break;
			// case q194:
			// 	if (simbolo == ' ')
			// 		Estado = q140;
			// 	if (simbolo == ';')
			// 		Estado = q142;
			// 	break;
			// case q195:
			// 	if (simbolo == ' ' || simbolo == '\n')
			// 		Estado = q131;
			// 	break;
			// case q196:
			// 	if (simbolo == ' ')
			// 		Estado = q143;
			// 	if (simbolo == '#')
			// 		Estado = q144;
			// 	if (simbolo == '\'')
			// 		Estado = q146;
			// 	if (simbolo >= '0' && simbolo >= '9')
			// 		Estado = q149;
			// 	break;
			// case q197:
			// 	if (simbolo >= 'A' && simbolo <= 'Z')
			// 		Estado = q145;
			// 	break;
			// case q198:
			// 	if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
			// 		Estado = q145;
			// 	if (simbolo >= ';')
			// 		Estado = q157;
			// 	break;
			// case q199:
			// 	if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
			// 		Estado = q147;
			// 	break;
			// case q200:
			// 	if (simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z' || simbolo >= '0' && simbolo <= '9')
			// 		Estado = q147;
			// 	if (simbolo == '\'')
			// 		Estado = q148;
			// 	break;
			// case q201:
			// 	if (simbolo == ';')
			// 		Estado = q157;
			// 	break;
			// case q202:
			// 	if (simbolo >= '0' && simbolo >= '9')
			// 		Estado = q149;
			// 	if (simbolo == '.')
			// 		Estado = q150;
			// 	if (simbolo == ';')
			// 		Estado = q157;
			// 	break;
			// case q203:
			// 	if (simbolo >= '0' && simbolo >= '9')
			// 		Estado = q151;
			// 	break;
			// case q204:
			// 	if (simbolo >= '0' && simbolo >= '9')
			// 		Estado = q151;
			// 	if (simbolo == ';')
			// 		Estado = q157;
			// 	break;
			
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