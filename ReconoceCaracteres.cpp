#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
using std::strcmp;
using std::strncmp;



/*
https://parzibyte.me/blog
*/

int main() {
	string TablaSimbolos[7] = {"Programa","Fn_Principal() {","cadena","entero","decimal","imprimir","}fin"};
	//tipo de dato estado
	enum TEstado{q0, q1, q2, q3, q4, q5, q6,q7,q8,qe,qf};
	
	TEstado Estado;//variable estados
	int Simbolo; //un caracter o simbolo a validar en ASCII
	int i; //posicion del caracter leido en la cadena
	int longitud;//longitud total de la cadena
    string nombreArchivo; //la cadena a validar
    
    //valores iniciales
	i=longitud=0;
	Estado = q0;
   
    
    cout<<"escriba un archivo que quiera que se lea"<<endl;
    cin>>nombreArchivo;
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea, ' ') )
	{
		
		longitud = linea.size();
		while(longitud > i )
	{
		Simbolo = linea[i];
		switch(Estado)
		{
			case q0:
				if(Simbolo >= 'A' && Simbolo <= 'Z')
				{
					Estado = q1;
					break;
				}
			case q1:
				if(Simbolo >= 'a' && Simbolo <= 'z' )
				{
					Estado = q1;
				}
				if(isspace(Simbolo))
				{
					Estado = q2;
				}
				break;
			case q2:
				{
					if(Simbolo >= 'A' && Simbolo <= 'Z')
					{
						Estado = q1;
					}
					if(Simbolo >= 'a' && Simbolo <= 'z')
					{
						Estado = q1;
					}
					if(Simbolo >= '0' && Simbolo <= '9')
					{
						Estado = q2;
					}
					if(Simbolo == ' ')
					{
						Estado = q3;
					}
					break;
				}
			case q3:
				{
					if(Simbolo == '{')
					{
						Estado = q4;
					}
					
					break;
				}
			case q4:
				{
					if(Simbolo >= 'A' && Simbolo <= 'Z')
					{
						Estado = q0;
					}
					if(Simbolo >= 'a' && Simbolo <= 'z')
					{
						Estado = q1;
					}
					if(Simbolo == '_')
					{
						Estado = q4;
					}
					if(Simbolo == ' ')
					{
						Estado = q4;
					}
					if(Simbolo == '(')
					{
						Estado = q4;
					}
					if(Simbolo == ')')
					{
						Estado = q4;
					}
					if(Simbolo == '{')
					{
						Estado = q5;
					}
					if(Simbolo == '}')
					{
						Estado = qf;
					}
					break;
				}
			case q5:
				{
					if(Simbolo >= 'a' && Simbolo <= 'z')
					{
						Estado = q1;
					}
					if(Simbolo == '=')
					{
						Estado = q6;
					}
					break;
				}
			case q6:
				{
					if(Simbolo >= 'A' && Simbolo <= 'Z')
					{
						Estado = q0;
					}
					if(Simbolo >= 'a' && Simbolo <= 'z')
					{
						Estado = q1;
					}
					if(Simbolo == ';')
					{
						Estado = q7;
					}
					break;
				}
				
			
		} 	
		i++;
		
	}
	
	if( Estado == q0 || Estado == q1  || Estado == q2 || Estado == q3 || Estado == q4 || Estado == q5 || Estado == q6 || Estado == q7 )
	{
		
		
		cout <<"Cadena aceptada "<<linea<<endl;
		//buscar en la tabla de simbolos
		int j;
		int TamanioArreglo = sizeof TablaSimbolos;
		for(j=0; j<TamanioArreglo; j++)
		{
			if (linea.compare(0, linea.length(), TablaSimbolos[j]))
			{
				cout<<"Palabra reservada: "<<linea<<endl;
				break;
				
			}
		}
	}
	else
	{
		cout<< "Cadena no valida"<<endl;
	}
	
	}
        
return 0;
}
