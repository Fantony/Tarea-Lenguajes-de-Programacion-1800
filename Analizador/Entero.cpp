#include <iostream>

using namespace std;

class Entero{
	
public:
	// Se almacena la cantidad de numeros enteros validos
	int contador = 0;
	void esEntero(string cadena){
		// "-" -> 1-9 -> 0-9
		// 1-9-> 0-9 
		
		enum TEstado {q0, q1, q2};
		
		TEstado Estado;
		
		string simbolo;
		string primerCaracter;
		
		int i;
		int longitud;
		
		i = 0;
		Estado = q0;
		
		primerCaracter = cadena[0];
		
		longitud = cadena.size();
		
		while(longitud > i){
			
			simbolo = cadena[i];
			
			if(primerCaracter == "-"){
				
				switch(Estado){
					
				case q0:
					
					if(simbolo == "-"){
						Estado = q1;
					}
					break;
					
				case q1:
					
					if(simbolo >= "1" && simbolo <= "9"){
						Estado = q2;
					}
					break;
					
				case q2:
					if(simbolo >= "0" && simbolo <= "9"){
						Estado = q2;
					}
					break;
				}   
				
			}
			
			if(primerCaracter >= "1" && primerCaracter <= "9"){
				
				switch(Estado){
					
				case q0:
					
					if(simbolo >= "1" && simbolo <= "9"){
						Estado = q2;
					}
					break;
					
				case q2:
					if(simbolo >= "0" && simbolo <= "9"){
						Estado = q2;
					}
					break;
				}   
			}
			
			if(primerCaracter == "0" && longitud == 1){
				Estado = q2;
			}
			
			if(
			   !(simbolo == "-") && 
			   !(simbolo >= "0" && simbolo <= "9")
			   ){
				break;
				
			}else{
				   
				   i++;
			   }
			   
		}
		
		if(Estado == q2){
			contador++;
		}
	}
		
};
