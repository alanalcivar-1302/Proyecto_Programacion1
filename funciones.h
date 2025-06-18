#ifndef FUNCIONES_H
#define FUNCIONES_H

//Tamaño de carácteres en arreglos
#define TAM_CEDULA 15
#define TAM_NOMBRE 100
#define TAM_PLACA 10

//Estructura de los datos

typedef struct{
	
	char nombrePropietario[TAM_NOMBRE];
	char numCedula[TAM_CEDULA];
	char modeloAuto[10];
	char placa[TAM_PLACA];
	char colorAuto[10];
	int anioAuto;
	
}datosUsuario;


//Funciones 

void menu();

int continuar();

void clearInputBuffer();

void opcionesUsuario(int *opcionEscoger, int rangoOpciones);float calcularValormatricula(int pagoAtiempo, int hizoRevisionVehiculo, int diasPago, float multasVehiculo, int tipoVehiculo);

#endif
