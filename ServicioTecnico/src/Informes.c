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

int orderReparacionBySerieCode(Reparacion reparacionO[], int len) {
	int retorno = -1;
	int large = getReparacionesAdded(reparacionO, len);
	int largeC = large;
	printf("Large = %d\n", large);

	Reparacion rtemp;

	int comp;

	for (int h = 0; h < (large - 1); h++) {
		for (int i = 0; i < (largeC - 1); i++) {
			int j = i + 1;

			comp = strcmp(reparacionO[i].ElectroR.serie,
					reparacionO[j].ElectroR.serie);
			//		printf(" Comparacion entre %s y %s = %d\n",
			//				reparacionO[i].ElectroR.serie,
			//				reparacionO[j].ElectroR.serie, comp);

			if (comp == 1) {
				//			printf("%s sube de lugar\n", reparacionO[j].ElectroR.serie);
				rtemp = reparacionO[i];
				reparacionO[i] = reparacionO[j];
				reparacionO[j] = rtemp;
			}
			//	printArrayReparacion(reparacionO, len);
			//		system("pause");
			//		printf("\n\n");
		}
		--largeC;

	}
	printf(
			"Listado de reparaciones ordenado alfabeticamente por codigo de serie.\n");
	printArrayReparacion(reparacionO, len);
	return retorno;
}

int orderReparacionByLastName(Reparacion reparacionO[], int len) {
	int retorno = -1;
	int large = getReparacionesAdded(reparacionO, len);
	int largeC = large;
	printf("Large = %d\n", large);

	Reparacion rtemp;

	int comp;

	for (int h = 0; h < (large - 1); h++) {
		for (int i = 0; i < (largeC - 1); i++) {
			int j = i + 1;

			comp = strcmp(reparacionO[i].clienteR.apellido,
					reparacionO[j].clienteR.apellido);
			//	printf(" Comparacion entre %s y %s = %d\n",
			//			reparacionO[i].clienteR.apellido,
			//			reparacionO[j].clienteR.apellido, comp);

			if (comp == 1) {
				//		printf("%s sube de lugar\n", reparacionO[j].clienteR.apellido);
				rtemp = reparacionO[i];
				reparacionO[i] = reparacionO[j];
				reparacionO[j] = rtemp;
			}
			//	system("pause");
			//	printf("\n\n");
		}
		--largeC;

	}
	printf(
			"Listado de reparaciones ordenado alfabeticamente por apellido del cliente\n");
	printArrayReparacion(reparacionO, len);
	return retorno;
}
