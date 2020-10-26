/*
 * Electrodomestico.c
 *
 *  Created on: 18 oct. 2020
 *      Author: Gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Electrodomestico.h"

int initArrayElectro(Electrodomestico *electro, int len) {

	for (int i = 0; i < len; i++) {
		electro[i].id = i + 1;
		strcpy(electro[i].serie, "___EMPTY");
		electro[i].marcaElectro.id = 1000;
		strcpy(electro[i].marcaElectro.descripcion, "Empty");
		electro[i].modelo = 1000;
		electro[i].isEmpty = 1;
	}

	return 0;
}

int addElectro(Electrodomestico *electro, int arrayPosition, char serie[],
		Marca marca, int modelo) {

	strcpy(electro[arrayPosition].serie, serie);
	electro[arrayPosition].marcaElectro = marca;

	electro[arrayPosition].modelo = modelo;
	electro[arrayPosition].isEmpty = 0;

	return 0;
}

int searchFirstEmptyElectro(Electrodomestico *electro, int len) {

	int retorno;
	for (int i = 0; i < len; i++) {

		if (electro[i].isEmpty == 1) {
			retorno = i;
			break;
		}
	}

	return retorno;
}

int getElectrosAdded(Electrodomestico *electro, int len) {

	int retorno = 0;
	for (int i = 0; i < len; i++) {

		if (electro[i].isEmpty == 0) {
			++retorno;

		}
	}

	return retorno;
}

int getElectroArrayPositionById(Electrodomestico *electro, int len, int id) {
	int returnElectro = -1;

	for (int i = 0; i < len; i++) {
		if (electro[i].id == id) {
			returnElectro = i;
			break;
		}
	}

	return returnElectro;
}

int printArrayElectro(Electrodomestico electro[], int len) {

	int arrayLength = 0;
	printf("\n|%3s|%10s|%10s|%7s\n\n", "Id", "Serie", "Marca", "Modelo");
	for (int i = 0; i < len; i++) {

		if (electro[i].isEmpty == 0) {
			printf("|%3d|%10s|%10s|%7d\n", electro[i].id, electro[i].serie,
					electro[i].marcaElectro.descripcion, electro[i].modelo);
			++arrayLength;
		} else {
			break;
		}

	}
	printf("\n");
	return arrayLength;
}

