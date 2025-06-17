//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//funciones de la libreria
#include "archivoCabecera.h"

int main(){
	
	//Variables
	int opcion = 0;
	char cedulaBusqueda[TAM_CEDULA];
	datos person;
	FILE *archivoDatos;
	int nuevo_Pagomatricula = 1;
	
	//std::string 
	//string ruta = "C:\\Users\\nahin\\Documents\\Programacion1\\ProyectoProgramacion1\\Librerias\\datosVehiculos.txt";
	
	//std::ofstream archivo(ruta);
	
	//Bucle del menú, acabará si el usuario ingresa el número 5
	while (opcion != 5){
		
		menu();
		
		printf("¿Qué desea realizar? \n");
		scanf("%d",&opcion);
		
		//Limpiar el terminal
		system("cls");
		
		
		switch (opcion){
			case 1: 
				printf("-----Registro de vehiculos-----\n");
				
				archivoDatos = fopen("C:\\Users\\nahin\\Documents\\Programacion1\\ProyectoProgramacion1\\Librerias\\datosVehiculos.txt","a");
				
				//Ingreso de Datos y validación
				clearInputBuffer();				
				pedirNombre(person.nombrePropietario);
				pedirCedula(person.numCedula);
				printf("Ingresar el modelo del vehículo\n");
				scanf("%s",&person.modeloAuto);
				clearInputBuffer();      
				pedirPlaca(person.placa);
				printf("Ingresar el color del vehículo\n");
				scanf("%s",&person.colorAuto);
				printf("Ingresar año del vehículo\n");
				scanf("%d",&person.anioAuto);
				clearInputBuffer();
				
				//Ingreso de datos en el archivo txt
				fprintf(archivoDatos,"%s,%s,%s,%s,%s,%d\n",person.nombrePropietario, person.numCedula, person.modeloAuto, person.placa, person.colorAuto, person.anioAuto);
				fclose(archivoDatos);
				
				opcion = continuar();
				
				break;
				
			case 2:
				
				printf("-----Buscar vehículo-----\n");
				
				printf("Ingresar el número de cédula del propietario del vehículo que desea buscar\n");
				pedirCedula(cedulaBusqueda);
				
				archivoDatos = fopen("C:\\Users\\nahin\\Documents\\Programacion1\\ProyectoProgramacion1\\Librerias\\datosVehiculos.txt","a");
				
				
				
				
				fclose(archivoDatos);
				opcion = continuar();
				
				break;
				
				
				
			case 3:
				
				printf("-----Consulta valor a pagar-----\n");
				
				while (nuevo_Pagomatricula) {
					int pagoAtiempo, hizo_revisionVehiculo, diasPago, tipoVehiculo;
					float multasVehiculo, total_pagoMatricula ;
					
					printf("Seleccione su tipo de vehículo: \n");
					printf(" 1. Automóvil \n 2. Motocicleta \n 3. Camión \n 4. Bus \n");
					scanf("%d", &tipoVehiculo);
					
					printf("¿Realizó la revisión técnica? (1=Sí, 0=No): \n");
					scanf("%d", &hizo_revisionVehiculo);
					
					printf("¿Pagó la matrícula a tiempo? (1=Sí, 0=No): \n");
					scanf("%d", &pagoAtiempo);
					
					printf("¿Cuántos días han pasado desde la notificación?: \n");
					scanf("%d", &diasPago);
					
					printf("Valor total de multas (sin descuentos): $\n");
					scanf("%f", &multasVehiculo);
					
					//Total a pagar de la matrícula
					total_pagoMatricula = calcularValormatricula(pagoAtiempo, hizo_revisionVehiculo, diasPago, multasVehiculo, tipoVehiculo);
					
					if (total_pagoMatricula >= 0) {
						printf("\n--------------- COMPROBANTE DE MATRICULA ---------------\n");
						printf("Recuerde guardar el comprobante. \n");
						printf("Multas: $%.2f\n", multasVehiculo);
						printf("Total a pagar: $%.2f\n", total_pagoMatricula);
						printf("----------------------------------------------------------\n");
					}
					
					// Desea revisar nuevo pago?
					
					printf("\n¿Desea procesar otro pago de matrícula? (1 = Sí, 0 = No): \n");
					scanf("%d", &nuevo_Pagomatricula);
				}
				opcion = continuar();
				break;
			case 4:
				printf("-----Agendamiento de citas -----\n");
				opcion = continuar();
				break;
			case 5:
				break;
		default:
			printf("Opción no valida\n");
			break;
		}
	}
	
	return 0;
}
	
	
