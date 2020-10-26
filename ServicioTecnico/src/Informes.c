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

int showReparacionesByElectrodomestico(Electrodomestico electro[], Reparacion reparacion[], int len){
	int retorno = -1;
	int chosenE = -1;
	int flagOk = 0;
	int arrayLengthE = getElectrosAdded(electro, len);
	int arrayLengthR = getReparacionesAdded(reparacion, len);
	int filtred = 0;
	printf("array length = %d", arrayLengthE);

	printArrayElectro(electro, len);

	flagOk += setInt(&chosenE, "Ingrese el id electrodomestico deseado", "Accion cancelada", 1, arrayLengthE, 3);

	if( flagOk == 0){

		for( int i = 0; i < arrayLengthR ; i++){
			if( reparacion[i].ElectroR.id == chosenE){
				if( i != filtred){
					reparacion[filtred] = reparacion[i];
				}

				++filtred;
			}
		}
		printArrayReparacion(reparacion, filtred);
	}

return retorno;
}

int facturacionTotalPorMantenimientos(Reparacion reparacion[], int len){

	int total = 0;
	int suma = 0;

	for( int i = 0; i < len ; i++){

		if( reparacion[i].ServicioR.idServicio == 20002){
			++suma;
			total += reparacion[i].ServicioR.precio;

		}
	}

	printf("El total recaudado en %d mantenimientos es $ %d\n", suma, total);

	return 0;
}
