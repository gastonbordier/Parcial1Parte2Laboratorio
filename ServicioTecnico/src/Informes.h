/*
 * Informes.h
 *
 *  Created on: 21 oct. 2020
 *      Author: Gaston
 */

#include "Reparacion.h"
#include "validations.h"



int filter2020Electro(Electrodomestico electro[], int len);

int filterElectrodomesticoByMarca(Electrodomestico electro[], int len,
		Marca marca[]);

int showReparacionesByElectrodomestico(Electrodomestico electro[], Reparacion reparacion[], int len);

int facturacionTotalPorMantenimientos(Reparacion reparacion[], int len);

#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */
