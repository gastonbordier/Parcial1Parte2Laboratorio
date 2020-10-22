/*
 * Servicio.c
 *
 *  Created on: 20 oct. 2020
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"

int printServicios( Servicio *servicio){

	printf("Id\tServicio\tPrecio\n");
	for( int i = 0; i <= 3; i++){
		printf("%d\t%s\t%d\n", servicio[i].idServicio, servicio[i].descripcion, servicio[i].precio);
	}

	return 0;
}
