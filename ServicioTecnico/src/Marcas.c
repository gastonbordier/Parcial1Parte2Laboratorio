/*
 * Marcas.c
 *
 *  Created on: 22 oct. 2020
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marcas.h"

int printMarcas(Marca *marca) {

	printf("Id\tMarca\n");
	for (int i = 0; i <= 4; i++) {
		printf("%d\t%s\n", marca[i].id, marca[i].descripcion);
	}

	return 0;
}
