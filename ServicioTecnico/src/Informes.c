/*
 * Informes.c
 *
 *  Created on: 21 oct. 2020
 *      Author: Gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Informes.h"

int filter2020Electro(Electrodomestico electro[], int len) {

	int retorno = -1;
	int large = getElectrosAdded(electro, len);

	int filtred = 0;

	for (int h = 0; h < large; h++) {

		if (electro[h].modelo == 2020) {

			if (h != filtred) {
				electro[filtred] = electro[h];
			}
			++filtred;
		}

	}
	printArrayElectro(electro, filtred);
	return retorno;
}

int filterElectrodomesticoByMarca(Electrodomestico electro[], int len,
		Marca marca[]) {
	Electrodomestico electroO[len];
	for (int i = 0; i < len; i++) {
		electroO[i] = electro[i];
	}

	int retorno = -1;
	int large = getElectrosAdded(electroO, len);
	int chosen;

	printf("Ingrese el id de la marca deseada\n");
	printMarcas(marca);

	int flag1 = 0;

	flag1 += setInt(&chosen, "Elija de la lista", "Ingreso de marca cancelado",
			1001, 1005, 3);

	if (flag1 == 0) {
		int comp;
		int filtred = 0;

		for (int h = 0; h < large; h++) {

			comp = (electroO[h].marcaElectro.id == chosen);
			if (comp == 1) {
				if (h != filtred) {
					electroO[filtred] = electroO[h];
				}
				++filtred;
			}

		}
		printArrayElectro(electroO, filtred);
	}

	return retorno;
}

int showReparacionesByElectrodomestico(Electrodomestico electro[],
		Reparacion reparacion[], int len) {
	int retorno = -1;
	int chosenE = -1;
	int flagOk = 0;
	int arrayLengthE = getElectrosAdded(electro, len);
	int arrayLengthR = getReparacionesAdded(reparacion, len);
	int filtred = 0;
	printf("array length = %d", arrayLengthE);

	printArrayElectro(electro, len);

	flagOk += setInt(&chosenE, "Ingrese el id electrodomestico deseado",
			"Accion cancelada", 1, arrayLengthE, 3);

	if (flagOk == 0) {

		for (int i = 0; i < arrayLengthR; i++) {
			if (reparacion[i].ElectroR.id == chosenE) {
				if (i != filtred) {
					reparacion[filtred] = reparacion[i];
				}

				++filtred;
			}
		}
		printArrayReparacion(reparacion, filtred);
	}

	return retorno;
}

int facturacionTotalPorMantenimientos(Reparacion reparacion[], int len) {

	int total = 0;
	int suma = 0;

	for (int i = 0; i < len; i++) {

		if (reparacion[i].ServicioR.idServicio == 20002) {
			++suma;
			total += reparacion[i].ServicioR.precio;

		}
	}

	printf("El total recaudado en %d mantenimientos es $ %d\n", suma, total);

	return 0;
}

int listElectroWithoutReparaciones(Electrodomestico electroO[],
		Reparacion reparacion[], int len) {

	Electrodomestico electro[len];
	for (int i = 0; i < len; i++) {
		electro[i] = electroO[i];
	}

	int retorno = -1;
	int arrayLengthE = getElectrosAdded(electro, len);
	int arrayLengthR = getReparacionesAdded(reparacion, len);
	int flagOk;
	int filtred = 0;

	for (int i = 0; i < arrayLengthE; i++) {
		flagOk = 1;
		for (int j = 0; j < arrayLengthR; j++) {
			if (electro[i].id == reparacion[j].ElectroR.id) {
//				printf(
//						"Electro[%d].id coincide con reparacion[%d].ElectroR.id. Corte de bucle\n",
//						i, j);
//
				flagOk = 0;
				break;
			} else {
//			printf("Electro[%d].id no coincide con reparacion[%d].ElectroR.id. Sigue el bucle\n",
//					i, j);
			}
		}
		if (flagOk == 1) {
			if (i == filtred) {
//				printf("Electro[%d].id continua en el mismo lugar\n", i);
			}
			if (i != filtred) {
				electro[filtred] = electro[i];
//				printf("Electro[%d].id para a electro[%d] \n", i, filtred);
			}
			++filtred;
//			printf("Valor de filtred pasa a %d\n", filtred);
		}

//			system("pause");
	}
	printArrayElectro(electro, filtred);

	return retorno;
}

int showTotalIncomeByElectrodomestico(Electrodomestico electroO[],
		Reparacion reparacionO[], int len) {

	Electrodomestico electro[len];
	for (int i = 0; i < len; i++) {
		electro[i] = electroO[i];
	}
	Reparacion reparacion[len];
	for (int i = 0; i < len; i++) {
		reparacion[i] = reparacionO[i];
	}

	int retorno = -1;
	int chosenE = -1;
	int flagOk = 0;
	int arrayLengthE = getElectrosAdded(electro, len);
	int arrayLengthR = getReparacionesAdded(reparacion, len);
	int filtred = 0;
	int totalAmount = 0;
	printf("array length = %d", arrayLengthE);

	printArrayElectro(electro, len);

	flagOk += setInt(&chosenE, "Ingrese el id electrodomestico deseado",
			"Accion cancelada", 1, arrayLengthE, 3);

	if (flagOk == 0) {

		for (int i = 0; i < arrayLengthR; i++) {
			if (reparacion[i].ElectroR.id == chosenE) {
				if (i != filtred) {
					reparacion[filtred] = reparacion[i];
				}

				++filtred;
			}
		}
		for (int i = 0; i < filtred; i++) {
			totalAmount += reparacion[i].ServicioR.precio;
		}
		printf(
				"El importe total de las reparaciones efectuadas al electrodomestico elegido es %d\n",
				totalAmount);
	}

	return retorno;
}

int getMostRequiredServicio(Reparacion reparacion[], int len,
		Servicio servicioO[]) {
	Servicio servicio[4];
	for (int i = 0; i < 4; i++) {
		servicio[i] = servicioO[i];
	}

	int retorno = 0;
	int counting[] = { 0, 0, 0, 0 };
	int arrayLengthR = getReparacionesAdded(reparacion, len);
	Servicio tempS;
	int tempC;

	for (int i = 0; i < arrayLengthR; i++) {
		for (int j = 0; j < 4; j++) {
			if (reparacion[i].ServicioR.idServicio == servicio[j].idServicio) {
				++counting[j];
			}

		}
	}

	int large = 3;
	for (int i = 0; i < (4 - 1); i++) {
		for (int j = 0; j < large; j++) {

			if (counting[j] < counting[j + 1]) {

				tempS = servicio[i];
				servicio[j] = servicio[j + 1];
				servicio[j + 1] = tempS;

				tempC = counting[j];
				counting[j] = counting[j + 1];
				counting[j + 1] = tempC;
//				printf("%s tiene %d y %s tiene %d, se hace el swap\n", servicio[i].descripcion, counting[i],servicio[i+1].descripcion, counting[i+1]);

			} else {
//				printf("%s tiene %d y %s tiene %d, no se hace el swap\n", servicio[i].descripcion, counting[i],servicio[i+1].descripcion, counting[i+1]);

			}
//			system("pause");
		}
		--large;
	}

	if (counting[0] == counting[3]) {
		printf("Todos los servicios fueron igual de pedidos\n");
	} else if (counting[0] == counting[2]) {
		printf("Los servicios mas pedidos fueron %s, %s y %s\n",
				servicio[0].descripcion, servicio[1].descripcion,
				servicio[2].descripcion);
	} else if (counting[0] == counting[1]) {
		printf("Los servicios mas pedidos fueron %s y %s\n",
				servicio[0].descripcion, servicio[1].descripcion);
	} else {
		printf("El servicio mas pedido fue %s\n", servicio[0].descripcion);
	}
	return retorno;
}

int getTotalIncomeByDate(Reparacion reparacionO[], int len) {
	int retorno = 0;
	int arrayLengthR = getReparacionesAdded(reparacionO, len);
	Fecha datesWithReparaciones[arrayLengthR];
	for (int i = 0; i < arrayLengthR; i++) {
		strcpy(datesWithReparaciones[i].completeDate, "01/01/1900");
	}

	Reparacion reparacion[arrayLengthR];
	for (int i = 0; i < arrayLengthR; i++) {
		reparacion[i] = reparacionO[i];
	}

	int dateRepeated = 0;
	int arrayPositionD = 0;

	int compare = 0;

	for (int i = 0; i < arrayLengthR; i++) {
//	printf("%d\n", arrayLengthR);
//
//	printf(" i = %d. arraylengthR = %d. arrayPositionD = %d\n", i, arrayLengthR, arrayPositionD);

		dateRepeated = 0;

		for (int j = 0; j < arrayPositionD; j++) {
			dateRepeated = 0;
			compare = strcmp(reparacion[i].fecha.completeDate,
					datesWithReparaciones[j].completeDate);
//			printf(
//					"reparacion[%d].fecha.completeDate, datesWithReparaciones[%d].completeDate\n",
//					i, j);
//			printf("strcmp( %s, %s) = %d\n", reparacion[i].fecha.completeDate,
//					datesWithReparaciones[j].completeDate, compare);

			if (compare == 0) {
//				printf("La comparacion da igual\n");
				dateRepeated = 1;
				break;
			}

//			system("pause");
		}

		if (dateRepeated == 0) {
//			printf("Se agrega al datesith\n");
			datesWithReparaciones[arrayPositionD] = reparacion[i].fecha;
//			printf("datesWithReparaciones[%d] = %s\n", arrayPositionD ,datesWithReparaciones[arrayPositionD].completeDate );
			++arrayPositionD;

		}
//		system("pause");
	}

	printf("Fechas con reparaciones, elija una para ver el detalle:\n");
	for (int i = 1; i <= arrayPositionD; i++) {
		printf("Id %5d  | %10s\n", i,
				datesWithReparaciones[i - 1].completeDate);
	}
	int chosenD;
	int flagOk = setInt(&chosenD, "Elija una para ver el detalle:",
			"Operacion cancelada", 1, arrayPositionD, 3);
	int filtred = 0;
	if (flagOk == 0) {
		int totalByDate = 0;

		for (int i = 0; i < arrayLengthR; i++) {
			if (strcmp(reparacion[i].fecha.completeDate,
					datesWithReparaciones[chosenD - 1].completeDate) == 0) {
				if (i != filtred) {
					reparacion[filtred] = reparacion[i];
				}
				totalByDate += reparacion[i].ServicioR.precio;

				++filtred;
			}
		}
		printArrayReparacion(reparacion, filtred);
		printf("El total recaudado en el día es de $ %d.\n", totalByDate);
	}

	return retorno;
}

int getElectrosWithGarantia(Electrodomestico electroO[],
		Reparacion reparacionO[], int len) {

	Reparacion reparacion[len];
	for (int i = 0; i < len; i++) {
		reparacion[i] = reparacionO[i];
	}
	int arrayLengthE = getReparacionesAdded(reparacion, len);
	Electrodomestico electroGarantia[100];
	Fecha dateGarantia[100];
	int arrayPosition = 0;

	for (int i = 0; i < arrayLengthE; i++) {
		if (reparacion[i].ServicioR.idServicio == 20001) {
			electroGarantia[arrayPosition] = reparacion[i].ElectroR;
			dateGarantia[arrayPosition] = reparacion[i].fecha;
			++arrayPosition;
		}

	}

	printf("\n|%3s|%10s|%10s|%7s|%15s|\n\n", "Id", "Serie", "Marca", "Modelo",
			"Fecha Garantia");
	for (int i = 0; i < arrayPosition; i++) {

		if (electroGarantia[i].isEmpty == 0) {
			printf("|%3d|%10s|%10s|%7d|%15s|\n", electroGarantia[i].id,
					electroGarantia[i].serie,
					electroGarantia[i].marcaElectro.descripcion,
					electroGarantia[i].modelo, dateGarantia[i].completeDate);

		} else {
			break;
		}

	}
	printf("\n");

	return 0;
}

int getReparacionesfrom2018Electros(Electrodomestico electroO[],
		Reparacion reparacionO[], int len) {

	int retorno = 0;
	int arrayLength2018 = 0;




	int arrayLenghtR = getReparacionesAdded(reparacionO, len);
	Reparacion reparacion[arrayLenghtR];
	for (int i = 0; i < arrayLenghtR; i++) {
		reparacion[i] = reparacionO[i];
	}

	for (int i = 0; i < arrayLenghtR; i++) {
		if (reparacion[i].ElectroR.modelo == 2018) {

			if (i != arrayLength2018) {
				reparacion[arrayLength2018] = reparacion[i];
			}

			++arrayLength2018;
		}

	}
	if( arrayLength2018 > 0)
		printArrayReparacion(reparacion, arrayLength2018);
	else{
		printf("No hay ninguna reparacion efectuada a un Electrodomestico modelo 2018\n");
	}

	return retorno;

}

int showMarcaRefaccion(Reparacion reparacionO[], int len){
	int retorno = 0;
	Marca marca[] = { { 1001, "Whirpool" }, { 1002, "Sony" }, { 1003, "Liliana" }, {
			1004, "Gafa" }, { 1005, "Phillips" }

	};
	int countRefacciones[5] = {0,0,0,0,0};

	int arrayLenghtR = getReparacionesAdded(reparacionO, len);
	Reparacion reparacion[arrayLenghtR];
	for (int i = 0; i < arrayLenghtR; i++) {
		reparacion[i] = reparacionO[i];
	}

	for( int i = 0 ; i < arrayLenghtR ; i++){
		if( reparacion[i].ServicioR.idServicio == 20004){
			switch( reparacion[i].ElectroR.marcaElectro.id){
			case 1001:
				++countRefacciones[0];
							break;
			case 1002:
				++countRefacciones[1];
							break;
			case 1003:
				++countRefacciones[2];
							break;
			case 1004:
				++countRefacciones[3];
							break;
			case 1005:
				++countRefacciones[4];
							break;

			}
		}

	}
	for( int i = 0 ; i < 5 ; i++){
		printf("%d\n", countRefacciones[i]);
	}

	return retorno;
}
