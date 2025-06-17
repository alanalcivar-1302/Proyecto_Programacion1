#include <stdio.h>

float calcularValormatricula(int pagoAtiempo, int hizoevisionVehiculo, int diasPago, float multasVehiculo, int tipoVehiculo) {

	//Datos del recargo y descuentos
	float recargoRevision = 50.0; //Dólares
	float recargoMes = 25.0; //Dólares
	float descuentoProntopago = 0.5; //Porcentaje de descuento (50%)
	float MatriculaporVehiculo; //Variable de subsecciones para el tipo de vehículo.
	
	//Precio de matrícula con respecto al tipo de vehículo 
	switch (tipoVehiculo){
		case 1: MatriculaporVehiculo = 100.0;  //Para auto
			break;
		case 2: MatriculaporVehiculo = 150.0; //Para motocicleta
			break;
		case 3: MatriculaporVehiculo = 250.0; //Para camión
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
	
	// Descuento solamente si días <= 20
	if (pagoAtiempo == 1 && diasPago <= 20) {
		MatriculaporVehiculo *= (1 - descuentoProntopago);   // Para 50% de descuento
	}
	
	// Total a pagar
	return MatriculaporVehiculo + multasVehiculo;
	
}
	
	//Función principal
int main (){
	
	int nuevoPagomatricula = 1;
	
	while (nuevoPagomatricula) {
	int pagoAtiempo, hizoevisionVehiculo, diasPago, tipoVehiculo ;
	float multasVehiculo, totalpagoMatricula ;
	
	printf("Seleccione su tipo de vehículo: \n");
	printf(" 1. Automóvil \n 2. Motocicleta \n 3. Camión \n 4. Bus \n");
	scanf("%d", &tipoVehiculo);
	
	printf("¿Realizó la revisión técnica? (1=Sí, 0=No): \n");
	scanf("%d", &hizoevisionVehiculo);
	
	printf("¿Pagó la matrícula a tiempo? (1=Sí, 0=No): \n");
	scanf("%d", &pagoAtiempo);
	
	printf("¿Cuántos días han pasado desde la notificación?: \n");
	scanf("%d", &diasPago);
	
	printf("Valor total de multas (sin descuentos): $\n");
	scanf("%f", &multasVehiculo);
	
	//Total a pagar de la matrícula
	totalpagoMatricula = calcularValormatricula(pagoAtiempo, hizoevisionVehiculo, diasPago, multasVehiculo, tipoVehiculo) ;
	
	if (totalpagoMatricula >= 0) {
		printf("\n--------------- COMPROBANTE DE MATRICULA ---------------\n");
		printf("Recuerde guardar el comprobante. \n");
		printf("Multas: $%.2f\n", multasVehiculo);
		printf("Total a pagar: $%.2f\n", totalpagoMatricula);
		printf("----------------------------------------------------------\n");
	}
	
	// Desea revisar nuevo pago?
	
	printf("\n¿Desea procesar otro pago de matrícula? (1 = Sí, 0 = No): \n");
	scanf("%d", &nuevoPagomatricula);
}
	
	printf("Gracias por preferir nuestro sistema. Regrese mas tarde.\n");
	
	return 0;
}
