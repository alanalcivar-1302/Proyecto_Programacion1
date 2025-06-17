#include "archivoCabecera.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Tamaño de carácteres en arreglos
#define TAM_CEDULA 15
#define TAM_NOMBRE 100
#define TAM_PLACA 10


void menu(){
	printf("1. Registrar vehículo \n");
	printf("2. Buscar vehículo por placa \n");
	printf("3. Consultar valor a pagar por matricula\n");
	printf("4. Agendar cita de revisión\n");
	printf("5. Salir \n");
	printf("\n");
	
}
	
//FUNCION IMPLEMENTADA Bufer	
void clearInputBuffer() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}







int continuar(){
int opcion;
printf("¿Necesita consultar algo más? (1. Si / 2. No) \n");
scanf("%d", &opcion);
if (opcion == 2){
	printf("Gracias por preferir nuestro sistema. Regrese mas tarde.\n");
	return 5;
}
else
	return 0;
}




/*
void buscarVehiculo(char cedulaBuscar, FILE * archivoDatos){
archivoDatos = fopen("datosVehiculo.txt","r");
while (fscanf(archivoDatos,"%s, %s, %s, %s, %s, %d\n",person.nombrePropietario, person.numCedula, person.modeloAuto, person.placa, person.colorAuto, person.anioAuto) == 6){
if (strcmp(person.numCedula,cedulaBuscar) == 0){
printf("Se encontró su vehículo\n");
printf("Nombre: %s\n",person.nombrePropietario);
printf("Cédula: %s\n",person.numCedula);
printf("Modelo: %s\n",person.modeloAuto);
printf("Placa: %s\n".person.placa);
printf("Color: %s\n"person.colorAuto);
printf("Año: %d\n".person.anioAuto);
busqueda = 1;
break;
}
}
fclose(archivoDatos);

if (busqueda != 1)
printf("El número de cédula no se encuentra en nuestra base de datos\n");
}
*/




//Funciones de validaciones de datos		
int validarCedula(char cedula[]) {
	if (strlen(cedula) != 10) {
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		if (!isdigit(cedula[i])) {
			return 0;
		}
	}
	return 1;
}


int validarNombre(char nombre[]) {
	for (int i = 0; nombre[i] != '\0'; i++) {
		if (!isalpha(nombre[i]) && nombre[i] != ' ') {
			return 0;
		}
	}
	return 1;
}


int validarPlaca(char placa[]) {
	if (strlen(placa) != 8)
		return 0;
	
	for (int i = 0; i < 3; i++) {
		if (!isupper(placa[i])) 
			return 0;
	}
	if (placa[3] != '-') 
		return 0;
	
	for (int i = 4; i < 8; i++) {
		if (!isdigit(placa[i])) 
			return 0;
	}
	return 1;
}


//Funciones para el ingreso de datos

void pedirCedula(char cedula[]) {
	do {
		printf("Ingrese la cedula (10 digitos): \n");
		fgets(cedula, TAM_CEDULA, stdin);
		cedula[strcspn(cedula, "\n")] = '\0';
		
		if (!validarCedula(cedula)) 
			printf("Cedula invalida, intente de nuevo.\n");
	} while (!validarCedula(cedula));
}


void pedirNombre(char nombre[]) {
	do {
		printf("Ingrese el nombre \n");
		fgets(nombre, TAM_NOMBRE, stdin);
		nombre[strcspn(nombre, "\n")] = '\0';
		
		if (!validarNombre(nombre)) 
			printf("Nombre invalido, solo letras y espacios. Intente de nuevo.\n");
	} while (!validarNombre(nombre));
}

void pedirPlaca(char placa[]) {
	do {
		printf("Ingrese la placa (ej: ABC-1234): \n");
		fgets(placa, TAM_PLACA, stdin);
		placa[strcspn(placa, "\n")] = '\0';
		if (!validarPlaca(placa)) 
			printf("Placa invalida, intente de nuevo.\n");
	} while (!validarPlaca(placa));
}
		
//Funcion para calcular el valor a pagar
float calcularValormatricula(int pagoAtiempo, int hizoevisionVehiculo, int diasPago, float multasVehiculo, int tipoVehiculo) {
	
	//Datos del recargo y descuentos
	float recargoRevision = 50.0; //Dólares
	float recargoMes = 25.0; //Dólares
	float descuentoProntopago = 0.5; //Porcentaje de descuento (50%)
	float MatriculaporVehiculo; //Variable de subsecciones para el tipo de vehículo.
	
	//Precio de matrícula con respecto al tipo de vehículo 
	switch (tipoVehiculo){
		case 1: 
			MatriculaporVehiculo = 100.0;  //Para auto
			break;
		case 2: 
			MatriculaporVehiculo = 150.0; //Para motocicleta
			break;
		case 3: 
			MatriculaporVehiculo = 250.0; //Para camión
			break;
		case 4: 
			MatriculaporVehiculo = 175,0; //Para Bus
			break;
		default:
		printf("Opción no valida \n");
		break;
	}
	
	// Se suman recargos
	if (hizoevisionVehiculo == 2) {
		MatriculaporVehiculo += recargoRevision;
	}
	
	if (pagoAtiempo == 2) {
		MatriculaporVehiculo += recargoMes;
	}
	
	// Descuento solamente si días <= 20
	if (pagoAtiempo == 1 && diasPago <= 20) {
		MatriculaporVehiculo *= (1 - descuentoProntopago);   // Para 50% de descuento
	}
	
	// Total a pagar
	return MatriculaporVehiculo + multasVehiculo;
	
}
		
