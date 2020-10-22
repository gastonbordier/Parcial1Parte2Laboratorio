/*
 * Electrodomestico.h
 *
 *  Created on: 18 oct. 2020
 *      Author: Gaston
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#include "Marcas.h"


typedef struct {
	int id;
	char serie[9];
	Marca marcaElectro;
	int modelo;//AÑO DE FABRICACION
	int isEmpty;
}Electrodomestico;

/*
 * author Gaston Bordier
 *\brief inicializa el array de estructuras Electrodomestico
 *\param *e El array de estructuras a manipular
 *\param len la longitud maxima del array
 *\return 0
 *  */
int initArrayElectro(Electrodomestico *e, int len);

/*
 * author Gaston Bordier
 *\brief imprime por pantalla el array de estructuras Electrodomestico
 *\param *electroEmployee El array de estructuras a manipular
 *\param len la longitud maxima del array
 *\return 0
 *  */
int printArrayElectro(Electrodomestico *electro, int len);


/*
 * author Gaston Bordier
 *\brief averigua el primer elemento vacio del array de estructuras Electrodomestico
 *\param *electro El array de estructuras a manipular
 *\param len la longitud maxima del array
 *\return la ubicacion del primer elemento vacio
 *  */
int searchFirstEmptyElectro(Electrodomestico *electro, int len);

/*
 * author Gaston Bordier
 *\brief averigua la cantidad de elementos existentes en el array de estructuras Electrodomestico
 *\param *electro El array de estructuras a manipular
 *\param len la longitud maxima del array
 *\return la cantidad de elementos existentes
 *  */
int getElectrosAdded(Electrodomestico *electro, int len);

/*
 * author Gaston Bordier
 *\brief agrega un elemento al array de estructuras Electrodomestico
 *\param *electro El array de estructuras a manipular
 *\param arrayPosition la posicion del array donde se agregara el nuevo elemento
 *\param serie[] el codigo de serie
 *\param marca la marca del electrodomestico
 *\param modelo el año de fabricacion
 *\return 0
 *  */
int addElectro(Electrodomestico *electro, int arrayPosition, char serie[], Marca marca, int modelo);

/*
 * author Gaston Bordier
 *\brief toma un numero de id y devuelve su posicion en el array
 *\param *electro El array de estructuras a manipular
 *\param len la longitud maxima del array
 *\param id el id buscado
 *\return 0 si lo encuentra, -1 si la posicion esta vacia
 *  */
int getElectroArrayPositionById( Electrodomestico *electro, int len, int id);




#endif /* ELECTRODOMESTICO_H_ */
