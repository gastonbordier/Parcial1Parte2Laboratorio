/*
 * Reparacion.c
 *
 *  Created on: 20 oct. 2020
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reparacion.h"

int initArrayReparacion(Reparacion *reparacion, int len) {

	for (int i = 0; i < len; i++) {

		reparacion[i].id = 1000 + i + 1;
		strcpy(reparacion[i].fecha.completeDate, "01/01/1900");
		strcpy(reparacion[i].ElectroR.serie, "Empty");
		strcpy(reparacion[i].ElectroR.marcaElectro.descripcion, "Empty");
		strcpy(reparacion[i].ServicioR.descripcion, "Empty");
		reparacion[i].ServicioR.precio = 0;
		reparacion[i].isEmpty = 1;
	}

	return 0;
}

int addReparacion(Reparacion *reparacion, int arrayPosition, Fecha fecha,
		Electrodomestico electro, Servicio servicio, Cliente cliente)
 {

	reparacion[arrayPosition].fecha = fecha;
	reparacion[arrayPosition].ElectroR = electro;
	reparacion[arrayPosition].ServicioR = servicio;
	reparacion[arrayPosition].clienteR = cliente;

	reparacion[arrayPosition].isEmpty = 0;

	return 0;
}

int searchFirstEmptyReparacion(Reparacion *reparacion, int len) {

	int retorno;
	for (int i = 0; i < len; i++) {

		if (reparacion[i].isEmpty == 1) {
			retorno = i;
			break;
		}
	}

	return retorno;
}

int getReparacionesAdded(Reparacion *reparacion, int len) {

	int retorno = 0;
	for (int i = 0; i < len; i++) {

		if (reparacion[i].isEmpty == 0) {
			++retorno;
		}
	}

	return retorno;
}

int getReparacionArrayPositionById(Reparacion *reparacion, int len, int id) {
	int returnR = -1;

	for (int i = 0; i < len; i++) {
		if (reparacion[i].id == id) {
			returnR = i;
			break;
		}
	}

	return returnR;
}

int printArrayReparacion(Reparacion reparacion[], int len) {

	int arrayLength = 0;
	printf("\n%5s|%13s|%13s|%13s|%13s|%13s|%9s|%13s|%7s|\n\n", "Id", "Fecha", "Nombre", "Apellido", "Serie", "Marca", "Modelo", "Servicio", "Precio");
	for (int i = 0; i < len; i++) {

		if (reparacion[i].isEmpty == 0) {
			printf("%5d|%13s|%13s|%13s|%13s|%13s|%9d|%13s|%7d|\n", reparacion[i].id,
					reparacion[i].fecha.completeDate, reparacion[i].clienteR.nombre,
					reparacion[i].clienteR.apellido,
					reparacion[i].ElectroR.serie,
					reparacion[i].ElectroR.marcaElectro.descripcion,
					reparacion[i].ElectroR.modelo,
					reparacion[i].ServicioR.descripcion,
					reparacion[i].ServicioR.precio);
			++arrayLength;
		} else {
			break;
		}

	}
	printf("\n");
	return arrayLength;
}
