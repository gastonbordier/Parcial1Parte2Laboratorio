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



int filter2020Reparacion(Reparacion reparacion[], int len) {
	Reparacion reparacionO[len];
	for (int i = 0; i < len; i++) {
		reparacionO[i] = reparacion[i];
	}

	int retorno = -1;
	int large = getReparacionesAdded(reparacionO, len);

	int filtred = 0;
	printf("Large = %d\n", large);

	int comp;

	for (int h = 0; h < large; h++) {

		comp = (reparacionO[h].fecha.anio == 2020);

		if (comp == 1) {

			if (h != filtred) {
				reparacionO[filtred] = reparacionO[h];
			}
			++filtred;
			//		printArrayReparacion(reparacionO, len);

			//	system("pause");
		}

	}
	printf("Listado de reparaciones del año 2020.\n");
	printf("\n%5s|%13s|%13s|%13s|%13s|%13s|%9s|%13s|%7s|\n\n", "Id", "Fecha",
			"Nombre", "Apellido", "Serie", "Marca", "Modelo", "Servicio",
			"Precio");
	for (int i = 0; i < filtred; i++) {

		if (reparacionO[i].isEmpty == 0) {
			printf("%5d|%13s|%13s|%13s|%13s|%13s|%9d|%13s|%7d|\n",
					reparacionO[i].id, reparacionO[i].fecha.completeDate,
					reparacionO[i].clienteR.nombre,
					reparacionO[i].clienteR.apellido,
					reparacionO[i].ElectroR.serie,
					reparacionO[i].ElectroR.marcaElectro.descripcion,
					reparacionO[i].ElectroR.modelo,
					reparacionO[i].ServicioR.descripcion,
					reparacionO[i].ServicioR.precio);

		} else {
			break;
		}

	}
	printf("\n");

	return retorno;
}

int filterElectrodomesticoByMarca(Electrodomestico *electro, int len,
		Marca *marca) {
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

int showReparacionesByElectrodomestico(Electrodomestico *electro,
		Reparacion reparacion[], int len) {
	int retorno = 0;
	Electrodomestico electroO[len];
	for (int i = 0; i < len; i++) {
		electroO[i] = electro[i];
	}
	Reparacion reparacionO[len];
	for (int i = 0; i < len; i++) {
		reparacionO[i] = reparacion[i];
	}

	int largeE = getElectrosAdded(electroO, len);
	int largeR = getReparacionesAdded(reparacionO, len);

	printArrayElectro(electroO, len);

	int flagOk = 0;
	int chosen = 0;
	int comp;
	int filtred = 0;

	flagOk += setInt(&chosen, "Ingrese el id del electrodomestico",
			"Ingreso cancelado", 1, largeE, 3);

	if (flagOk == 0) {

		for (int h = 0; h < largeR; h++) {

			comp = (reparacionO[h].ElectroR.id == chosen);
			if (comp == 1) {
				if (h != filtred) {
					reparacionO[filtred] = reparacionO[h];
				}
				++filtred;
			}
			//	printf("Id %d Comp %d\n", reparacionO[h].ElectroR.id, comp);

		}
		printf("Mostrando las reparaciones existentes al id %d\n", chosen);
		printArrayReparacion(reparacionO, filtred);
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
