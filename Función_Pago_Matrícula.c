#include <stdio.h>

float calcularValormatricula(int pagoAtiempo, int hizoevisionVehiculo, int diasPago, float multasVehiculo, int tipoVehiculo) {

	//Datos del recargo y descuentos
	float recargoRevision = 50.0; //D�lares
	float recargoMes = 25.0; //D�lares
	float descuentoProntopago = 0.5; //Porcentaje de descuento (50%)
	float MatriculaporVehiculo; //Variable de subsecciones para el tipo de veh�culo.
	
	//Precio de matr�cula con respecto al tipo de veh�culo 
	switch (tipoVehiculo){
		case 1: MatriculaporVehiculo = 100.0;  //Para auto
			break;
		case 2: MatriculaporVehiculo = 150.0; //Para motocicleta
			break;
		case 3: MatriculaporVehiculo = 250.0; //Para cami�n
			break;
		case 4: MatriculaporVehiculo = 175,0; //Para Bus
			break;
	}
	
	// Se suman recargos
	if (hizoevisionVehiculo == 0) {
		MatriculaporVehiculo += recargoRevision;
	}
	
	if (pagoAtiempo == 0) {
		MatriculaporVehiculo += recargoMes;
	}
	
	// Descuento solamente si d�as <= 20
	if (pagoAtiempo == 1 && diasPago <= 20) {
		MatriculaporVehiculo *= (1 - descuentoProntopago);   // Para 50% de descuento
	}
	
	// Total a pagar
	return MatriculaporVehiculo + multasVehiculo;
	
}
	
	//Funci�n principal
int main (){
	
	int nuevoPagomatricula = 1;
	
	while (nuevoPagomatricula) {
	int pagoAtiempo, hizoevisionVehiculo, diasPago, tipoVehiculo ;
	float multasVehiculo, totalpagoMatricula ;
	
	printf("Seleccione su tipo de veh�culo: \n");
	printf(" 1. Autom�vil \n 2. Motocicleta \n 3. Cami�n \n 4. Bus \n");
	scanf("%d", &tipoVehiculo);
	
	printf("�Realiz� la revisi�n t�cnica? (1=S�, 0=No): \n");
	scanf("%d", &hizoevisionVehiculo);
	
	printf("�Pag� la matr�cula a tiempo? (1=S�, 0=No): \n");
	scanf("%d", &pagoAtiempo);
	
	printf("�Cu�ntos d�as han pasado desde la notificaci�n?: \n");
	scanf("%d", &diasPago);
	
	printf("Valor total de multas (sin descuentos): $\n");
	scanf("%f", &multasVehiculo);
	
	//Total a pagar de la matr�cula
	totalpagoMatricula = calcularValormatricula(pagoAtiempo, hizoevisionVehiculo, diasPago, multasVehiculo, tipoVehiculo) ;
	
	if (totalpagoMatricula >= 0) {
		printf("\n--------------- COMPROBANTE DE MATRICULA ---------------\n");
		printf("Recuerde guardar el comprobante. \n");
		printf("Multas: $%.2f\n", multasVehiculo);
		printf("Total a pagar: $%.2f\n", totalpagoMatricula);
		printf("----------------------------------------------------------\n");
	}
	
	// Desea revisar nuevo pago?
	
	printf("\n�Desea procesar otro pago de matr�cula? (1 = S�, 0 = No): \n");
	scanf("%d", &nuevoPagomatricula);
}
	
	printf("Gracias por preferir nuestro sistema. Regrese mas tarde.\n");
	
	return 0;
}
