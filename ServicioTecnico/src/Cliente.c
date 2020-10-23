/*
 * Cliente.c
 *
 *  Created on: 20 oct. 2020
 *      Author: Gaston
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"


int printClientes( Cliente *cliente){

	printf("Id\tNombre\tApellido\n");
	for( int i = 0; i <= 9; i++){
		printf("%d\t%s\t%s\n", cliente[i].id, cliente[i].nombre, cliente[i].apellido);
	}

	return 0;
}
