#include "funciones.h"

#include <stdio.h>
	

void opcionesUsuario(int *opcionEscoger, int rangoOpciones){
	
	while ((*opcionEscoger < 0) || (*opcionEscoger > rangoOpciones	)){
		printf("Opcion no valida, ingrese nuevamente (1-%d)\n",rangoOpciones);
		scanf("%d",opcionEscoger);
	}
};

void validacionCaracteres(char stringValidar[]){
	for (int i = 0; stringValidar[i] != "\0"; i++){
		
	}
}
