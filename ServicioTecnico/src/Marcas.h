/*
 * Marcas.h
 *
 *  Created on: 22 oct. 2020
 *      Author: Administrador
 */

#ifndef MARCAS_H_
#define MARCAS_H_

typedef struct {
	int id;
	char descripcion[20];

}Marca;


int printMarcas( Marca *marca);

#endif /* MARCAS_H_ */
