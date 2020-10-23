/*
 * Fecha.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Administrador
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct {
	int dia;
	int mes ;
	int anio;
	char completeDate[10];

}Fecha;


int getDay(char fecha[]);
int getMonth(char fecha[]);
int getYear(char fecha[]);
int setStringFecha(Fecha *fecha, char errorMessage[51], int minYear,
		int maxYear, int retries);

#endif /* FECHA_H_ */



