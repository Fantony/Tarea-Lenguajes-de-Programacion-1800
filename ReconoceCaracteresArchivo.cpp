#include <iostream>
#include <fstream>
using namespace std;

/*
https://parzibyte.me/blog
*/

int main() {
	string TablaSimbolos[7] = {"programa","fn principal","cadena","entero","decimal","imprimir","}fin"};
	//tipo de dato estado
	enum TEstado{q0, q1, q2, q3, q4, q5, q6,qe};
	
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
    while (getline(archivo, linea)) 
	{
		longitud = linea.size();
		while(longitud > i && Estado != qe)
	{
		Simbolo = linea[i];
		switch(Estado)
		{
			case q0:
				if(Simbolo >= 'a' && Simbolo <= 'z')
				{
					Estado = q1;
					break;
				}
			case q1:
				if(Simbolo >= 'a' && Simbolo <= 'z' )
				{
					Estado = q1;
				}
				else
				{
					Estado = qe;
				}
				break;
		}
		i++; 
	}
	if(Estado == q0 || Estado == q1)
	{
		cout <<" Cadena aceptada "<<endl;
		//buscar en la tabla de simbolos
		int j;
		int TamanioArreglo = sizeof TablaSimbolos / sizeof TablaSimbolos[0];
		for(j=0; j<TamanioArreglo; j++)
		{
			if(linea.compare(TablaSimbolos[j])== 0)
			{
				cout<<"Palabra reservada: "<<linea;
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


	
	
	
	
	

