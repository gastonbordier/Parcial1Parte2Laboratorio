/*
 * Fecha.c
 *
 *  Created on: 22 oct. 2020
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"

int getDay(char fecha[]) {

	int day = -1;

	day = ((int) fecha[0] - (int) '0') * 10;
	day += (int) fecha[1] - (int) '0';

	return day;
}

int getMonth(char fecha[]) {

	int month = -1;

	month = ((int) fecha[3] - (int) '0') * 10;
	month += (int) fecha[4] - (int) '0';

	return month;
}

int getYear(char fecha[]) {

	int year = -1;

	year = ((int) fecha[6] - (int) '0') * 1000;
	year += ((int) fecha[7] - (int) '0') * 100;
	year += ((int) fecha[8] - (int) '0') * 10;
	year += (int) fecha[9] - (int) '0';

	return year;
}

int setStringFecha(Fecha *fecha, char errorMessage[51], int minYear,
		int maxYear, int retries) {
	int retorno = -1;
	int day, month, year;
	int flagOk = -1;
	char inputString[10];
	printf("%s\n", "Ingrese la fecha en formato DD/MM/AAAA\n");

	while (retries > 0) {

		fflush(stdin);
		fgets(inputString, 11, stdin);

	//	printf("strlen previo = %d\n", strlen(inputString));
		for (int i = 0; i <= (strlen(inputString) - 1); i++) {
	//		printf("[%d] = %c\n", i, inputString[i]);
		}

		if ((strlen(inputString)) >= 11 && (strlen(inputString)) <= 11) {
			flagOk = 0;
			day = getDay(inputString);
			month = getMonth(inputString);
			year = getYear(inputString);

		}
		if (flagOk == 0) {
			if (year < minYear || year > maxYear) {
				printf("Anio fuera del rango permitido\n");
				flagOk = -1;
			}
		}

		if (flagOk == 0) {
			switch (month) {

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day < 1 || day > 31) {
					printf("Dia incorrecto respecto al mes\n");
					flagOk = -1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day < 1 || day > 30) {
					printf("Dia incorrecto respecto al mes\n");
					flagOk = -1;
				}
				break;
			case 2:
				if (day < 1 || day > 29) {
					printf("Dia incorrecto respecto al mes\n");
					flagOk = -1;
				}
				break;
			default:
				printf("Mes incorrecto\n");
				flagOk = -1;
				break;
			}

		}

		if (flagOk == 0) {
			retries = -1;
		}
		if (flagOk == -1) {
			--retries;
			printf("Intentelo nuevamente\n");
		}

	}
	if (flagOk == 0) {
		fecha->dia = day;
		fecha->mes = month;
		fecha->anio = year;

		inputString[strlen(inputString)-1] = '\0';
		strcpy(fecha->completeDate, inputString);
		retorno = 0;
		printf("Ingreso exitoso\n");
	}
	if (retorno == -1)
		printf("%s\n", errorMessage);


	return retorno;
}
