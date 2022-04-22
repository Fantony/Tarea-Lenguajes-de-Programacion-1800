#include <iostream>
using namespace std;

class PalabraReservada{
public:
	int contador = 0;
	void esPalabraReservada(string cadena){
		// true
		// false
		// null
		
		enum TEstado {q0, q1, q2, q3, q4};
		TEstado Estado;
		Estado = q0;
		
		string simbolo;
		string primerCaracter;
		
		int i = 0;
		int longitud = cadena.size();
		
		Estado = q0;
		primerCaracter = cadena[0];
		
		if(primerCaracter != "t" && primerCaracter != "f" && primerCaracter != "n"){
			i = longitud;
		}
		
		while(i < longitud){
			
			simbolo = cadena[i];
			
			if(longitud == 4 && primerCaracter == "t"){
				
				switch (Estado){
					
				case q0:
					
					if(simbolo == "t"){
						Estado = q1;
					}
					break;
					
				case q1:
					
					if(simbolo == "r"){
						Estado = q2;
					}
					break;
					
				case q2:
					
					if(simbolo == "u"){
						Estado = q3;
					}
					break;
					
				case q3:
					
					if(simbolo == "e"){
						Estado = q4;
					}
					
					break;
					
				}
				
				if(
				   !(simbolo == "t") && !(simbolo == "r") &&
				   !(simbolo == "u") && !(simbolo == "e")
				   ){
					break;
					
				}else{
					   i++;
				   }
			}
			
			if(longitud == 5 && primerCaracter == "f"){
				
				switch (Estado){
					
				case q0:
					
					if(simbolo == "f"){
						Estado = q1;
					}
					break;
					
				case q1:
					
					if(simbolo == "a"){
						Estado = q2;
					}
					break;
					
				case q2:
					
					if(simbolo == "l"){
						Estado = q3;
					}
					break;
					
				case q3:
					
					if(simbolo == "s"){
						Estado = q4;
					}
					break;
					
				case q4:
					
					if(simbolo == "e"){
						Estado = q4;
					}
					break;
				}
				
				if(
				   !(simbolo == "f") && !(simbolo == "a") &&
				   !(simbolo == "l") && !(simbolo == "s") &&
				   !(simbolo == "e")
				   ){
					break;
				}else{
					   i++;
				   }
			}
			
			if(longitud == 4 && primerCaracter == "n"){
				
				switch (Estado){
					
				case q0:
					
					if(simbolo == "n"){
						Estado = q1;
					}
					break;
					
				case q1:
					
					if(simbolo == "u"){
						Estado = q2;
					}
					break;
					
				case q2:
					
					if(simbolo == "l"){
						Estado = q3;
					}
					break;
					
				case q3:
					
					if(simbolo == "l"){
						Estado = q4;
					}
					break;
					
				}
				
				if(
				   !(simbolo == "n") && !(simbolo == "u") &&
				   !(simbolo == "l") && !(simbolo == "l")
				   ){
					break;
				}else{
					   i++;
				   }
			}
		}
		
		if(Estado == q4){
			contador++;
		}			
	}
};
