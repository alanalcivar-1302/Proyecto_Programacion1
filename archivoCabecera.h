#ifndef ARCHIVOCABECERA_H
#define ARCHIVOCABECERA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Tamaño de carácteres en arreglos
#define TAM_CEDULA 15
#define TAM_NOMBRE 100
#define TAM_PLACA 10

typedef struct{
	char nombrePropietario[TAM_NOMBRE];
	char numCedula[TAM_CEDULA];
	char modeloAuto[10];
	char placa[TAM_PLACA];
	char colorAuto[10];
	int anioAuto;
}datos;

void menu();

void clearInputBuffer();

int continuar();

int validarCedula(char cedula[]);

int validarNombre(char nombre[]);

int validarPlaca(char placa[]);

void pedirCedula(char cedula[]);

void pedirNombre(char nombre[]);

void pedirPlaca(char placa[]);

float calcularValormatricula(int pagoAtiempo, int hizoRevisionVehiculo, int diasPago, float multasVehiculo, int tipoVehiculo);
#endif
