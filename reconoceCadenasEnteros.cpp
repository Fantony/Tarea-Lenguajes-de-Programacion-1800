#include <iostream>

using namespace std;

int main() 
{
	//tipos de datos estado
	enum TEstado{q0, q1};
	
	//Variable estado
	TEstado Estado;
	
	//variable en general
	string Cadena; //La cadena a validad
	int Simbolo; //Un caracter o simbolo a validar en ASCII
	bool EsNumero;
	
	int i; //posicion del caracter leido en la cadena
	int longitud; //longitud total de la cadena
	EsNumero = false;
	cout <<"Ingrese una cadena de numeros: ";
	cin>> Cadena;
	longitud = Cadena.size();
	
	while(longitud > i)
	{
		Simbolo = Cadena[i];
		
		EsNumero = (Simbolo >= '0' && Simbolo <='9');
		
		if(Estado == q0)
		{
			if(EsNumero)
			{
				Estado = q1;
			}	
		}
		
		if(Estado == q1)
		{
			if(EsNumero)
			{
				Estado = q1;
			}
		}
		
		if(!EsNumero)
		{
			Estado = q0;
			break;
		}
		
		i++; //avanza al siguiente caracter		
	}
	
	if(Estado == q1)
		cout<<"Cadena aceptada";
	else
		cout<<"Cadena no aceptada";
		
return 0;
	
}
