/*
 * Servicio.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Administrador
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_


typedef struct {

	int idServicio; //INCREMENTAL
	char descripcion[20];
	int precio;

}Servicio;

int printServicios( Servicio *servicio);

#endif /* SERVICIO_H_ */
