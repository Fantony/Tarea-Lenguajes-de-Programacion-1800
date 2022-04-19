#include <iostream>
using namespace std;

class Decimal{
	
public:
	// Se almacenan la cantidad de decimales validos
	int contador = 0;
	
	void esDecimal(string cadena){
		// "-" | 0-9 -> 0-9 -> "." -> 0-9		
		enum TEstado{q0, q1, q2};
		
		TEstado Estado;
		string simbolo;
		
		int i;
		int longitud;
		
		i = 0;
		Estado = q0;
		
		longitud = cadena.size();
		
		while(longitud > i){
			
			simbolo = cadena[i];
			
			switch(Estado){
				
			case q0:
				
				if((simbolo == "-" ) || (simbolo >= "0" && simbolo <= "9")){
					Estado = q1;
				}
				break;
				
			case q1:
				
				if(simbolo >= "0" && simbolo <= "9"){
					Estado = q1;
				}
				
				if(simbolo == "."){
					Estado = q2;
				}
				break;
				
			case q2:
				
				if(simbolo >= "0" && simbolo <= "9"){
					Estado = q2;
				}
				break;
			}
			
			if(!(simbolo == "-" || simbolo == ".") && !(simbolo >= "0" && simbolo <= "9")){
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
