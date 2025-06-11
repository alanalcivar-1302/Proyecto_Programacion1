#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define TAM_CEDULA 15
#define TAM_NOMBRE 100
#define TAM_PLACA 10
//Definici�n funciones

void menu(){
	printf("1. Registrar veh�culo \n");
	printf("2. Buscar veh�culo por placa \n");
	printf("3. Consultar valor a pagar por matricula\n");
	printf("4. Agendar cita de revisi�n\n");
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
	printf("�Necesita consultar algo m�s? (1. Si / 2. No) \n");
	scanf("%d", &opcion);
	if (opcion == 2){
		printf("Gracias por preferir nuestro sistema. Regrese mas tarde.\n");
		return 5;
	}else
		return 0;
}
	
	
typedef struct{
	char nombrePropietario[TAM_NOMBRE];
	char numCedula[TAM_CEDULA];
	char modeloAuto[10];
	char placa[TAM_PLACA];
	char colorAuto[10];
	int anioAuto;
}datos;

/*void buscarVehiculo(){
	fp = fopen("datosVehiculo.txt","r");
	while (fscanf(fp,"%s,%s,%s,%s,%s,%d\n",person.nombrePropietario, person.numCedula, person.modeloAuto, person.placa, person.colorAuto, person.anioAuto)== 6){
		if (strcmp(person.numCedula,cedulaBuscar) == 0){
			printf("Se encontr� su veh�culo\n");
			printf("Nombre: %s\n",person.nombrePropietario);
			printf("C�dula: %s\n",person.numCedula);
			printf("Modelo: %s\n",person.modeloAuto);
			printf("Placa: %s\n".person.placa);
			printf("Color: %s\n"person.colorAuto);
			printf("A�o: %d\n".person.anioAuto);
			busqueda = 0;
		}
	}
}
*/

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
	if (strlen(placa) != 8) {
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		if (!isupper(placa[i])) {
			return 0;
		}
	}
	if (placa[3] != '-') {
		return 0;
	}
	for (int i = 4; i < 8; i++) {
		if (!isdigit(placa[i])) {
			return 0;
		}
	}
	return 1;
}


void pedirCedula(char cedula[]) {
	do {
		printf("Ingrese la cedula (10 digitos): ");
		fgets(cedula, TAM_CEDULA, stdin);
		cedula[strcspn(cedula, "\n")] = '\0';
		
		if (!validarCedula(cedula)) {
			printf("Cedula invalida, intente de nuevo.\n");
		}
	} while (!validarCedula(cedula));
}

void pedirNombre(char nombre[]) {
	do {
		printf("Ingrese el nombre \n");
		fgets(nombre, TAM_NOMBRE, stdin);
		nombre[strcspn(nombre, "\n")] = '\0';
		
		if (!validarNombre(nombre)) {
			printf("Nombre invalido, solo letras y espacios. Intente de nuevo.\n");
		}
	} while (!validarNombre(nombre));
}

void pedirPlaca(char placa[]) {
	do {
		printf("Ingrese la placa (ej: ABC-1234): \n");
		fgets(placa, TAM_PLACA, stdin);
		placa[strcspn(placa, "\n")] = '\0';
		
		if (!validarPlaca(placa)) {
			printf("Placa invalida, intente de nuevo.\n");
		}
	} while (!validarPlaca(placa));
}



float calcularValormatricula(int pagoAtiempo, int hizo_revisionVehiculo, int diasPago, float multasVehiculo) {
	
	//Datos del recargo y descuentos
	float recargoRevision = 50.0;
	float recargoMes = 25.0;
	float descuento_Prontopago = 0.5;
	float baseMatricula = 100.0;
	
	// Se suman recargos
	if (!hizo_revisionVehiculo) {
		baseMatricula += recargoRevision;
	}
	
	if (!pagoAtiempo) {
		baseMatricula += recargoMes;
	}
	
	// Descuento solamente si d�as <= 20
	if (pagoAtiempo == 1 && diasPago <= 20) {
		baseMatricula *= (1 - descuento_Prontopago);   // Para 50% de descuento
	}
	
	// Total a pagar
	return baseMatricula + multasVehiculo;
	
}

int main(){
	
	//Variables
	int opcion = 0;
	char cedulaBusqueda[TAM_CEDULA];
	datos person;
	FILE *fp;
	int nuevo_Pagomatricula = 1;
	
	while (opcion != 5){
		menu();
		printf("�Qu� desea realizar? \n");
		scanf("%d",&opcion);
		system("cls");
		switch (opcion){
			case 1: 
				fp = fopen("datosVehiculos.txt","a");
				if (fp == NULL){
					printf("No vale\n");
				}
				printf("-----Registro de vehiculos-----\n");
				clearInputBuffer();
				pedirNombre(person.nombrePropietario);
				//SE LLAMA A LA FUNCION
				
				pedirCedula(person.numCedula);
				
				
				printf("Ingresar el modelo del veh�culo\n");
				scanf("%s",&person.modeloAuto);
				clearInputBuffer();//SE LLAMA A LA FUNCION        
				pedirPlaca(person.placa);
				//SE LLAMA A LA FUNCION
				printf("Ingresar el color del veh�culo\n");
				scanf("%s",&person.colorAuto);
				clearInputBuffer();
				printf("Ingresar a�o del veh�culo\n");
				scanf("%d",&person.anioAuto);
				clearInputBuffer();
				fprintf(fp,"%s,%s,%s,%s,%s,%d\n",person.nombrePropietario, person.numCedula, person.modeloAuto, person.placa, person.colorAuto, person.anioAuto);
				opcion = continuar();
				fclose(fp);
				break;
				
			case 2:
				printf("-----Buscar veh�culo-----\n");
				printf("Ingresar el n�mero de c�dula del propietario del veh�culo que desea buscar\n");
				pedirCedula(cedulaBusqueda);
				opcion = continuar();
				break;
			case 3:
				printf("-----Consulta valor a pagar-----\n");
				
				while (nuevo_Pagomatricula) {
					int pagoAtiempo, hizo_revisionVehiculo, diasPago;
					float multasVehiculo, total_pagoMatricula ;
					
					printf("�Realiz� la revisi�n t�cnica? (1=S�, 0=No): \n");
					scanf("%d", &hizo_revisionVehiculo);
					
					printf("�Pag� la matr�cula a tiempo? (1=S�, 0=No): \n");
					scanf("%d", &pagoAtiempo);
					
					printf("�Cu�ntos d�as han pasado desde la notificaci�n?: \n");
					scanf("%d", &diasPago);
					
					printf("Valor total de multas (sin descuentos): $\n");
					scanf("%f", &multasVehiculo);
					
					//Total a pagar de la matr�cula
					total_pagoMatricula = calcularValormatricula(pagoAtiempo, hizo_revisionVehiculo, diasPago, multasVehiculo);
					
					if (total_pagoMatricula >= 0) {
						printf("\n--------------- COMPROBANTE DE MATRICULA ---------------\n");
						printf("Recuerde guardar el comprobante. \n");
						printf("Multas: $%.2f\n", multasVehiculo);
						printf("Total a pagar: $%.2f\n", total_pagoMatricula);
						printf("----------------------------------------------------------\n");
					}
					
					// Desea revisar nuevo pago?
					
					printf("\n�Desea procesar otro pago de matr�cula? (1 = S�, 0 = No): \n");
					scanf("%d", &nuevo_Pagomatricula);
				}
				opcion = continuar();
				break;
			case 4:
				printf("-----Agendamiento de citas -----\n");
				opcion = continuar();
				break;
		default:
			printf("Opci�n no valida\n");
			break;
		}
	}
	
	return 0;
}

