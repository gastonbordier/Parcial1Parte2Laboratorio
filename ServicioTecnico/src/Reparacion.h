/*
 * Reparacion.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Administrador
 */

#ifndef REPARACION_H_
#define REPARACION_H_

#include "Fecha.h"
#include "Servicio.h"
#include "Cliente.h"

#include "Electrodomestico.h"





typedef struct {
		int id;
		Electrodomestico ElectroR;
		Servicio ServicioR;
		Cliente clienteR;
		Fecha fecha;
		int isEmpty;
}Reparacion;

int initArrayReparacion(Reparacion *reparacion, int len);
int searchFirstEmptyReparacion(Reparacion reparacion[], int len);

int getReparacionesAdded(Reparacion reparacion[], int len);

int getReparacionArrayPositionById( Reparacion reparacion[], int len, int id);

int addReparacion(Reparacion *reparacion, int arrayPosition, Fecha fecha,
		Electrodomestico electro, Servicio servicio, Cliente cliente);

int printArrayReparacion(Reparacion reparacion[], int len);

#endif /* REPARACION_H_ */
