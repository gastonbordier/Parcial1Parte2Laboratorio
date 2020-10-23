/*
 * Cliente.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Gaston
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {

	int id;
	char nombre[25];
	char apellido [25];


}Cliente;

int printClientes( Cliente *cliente);

#endif /* CLIENTE_H_ */
