/*
 ============================================================================
 Name        : ServicioTecnico.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Informes.h"

#define MAX 10
#define MAX2 100

int retorno;
char flagExitM;
Electrodomestico electro[MAX];
Reparacion reparacion[MAX];
int electrosAdded, reparacionesAdded;

int menu();

int main(void) {
	setbuf(stdout, NULL);
	system("MODE 160,35");

	int response, emptyArray;
	int arrayLength = 0;
	int arrayPosition;
	int idToChange;
	int dataToChange;
	int flag1, flag2, flag7, flagClean;
	int marcaChoice, servicioChoice, clienteChoice;

	Electrodomestico tempElectro;

	Reparacion tempR;

	Servicio servicio[] = { { 20001, "Garantia", 250 }, { 20002,
			"Mantenimiento", 500 }, { 20003, "Repuestos", 400 }, { 20004,
			"Refaccion", 600 }

	};

	Marca marca[] = { { 1001, "Whirpool" }, { 1002, "Sony" },
			{ 1003, "Liliana" }, { 1004, "Gafa" }, { 1005, "Phillips" }

	};

	Marca marcaEmpty = { 1000, "Empty" };

	Cliente cliente[] = { { 501, "Gaston", "Bordier" }, { 502, "Monica",
			"Introvigne" }, { 503, "Silvia", "Bordier" }, { 504, "Patricia",
			"Moles" }, { 505, "Armando", "Carmona" }, { 506, "Jose", "Zuleta" },
			{ 507, "Pablo", "Zulieta" }, { 508, "Azul", "Escobar" }, { 509,
					"Dora", "Bordier" },

	};

	initArrayElectro(electro, MAX);
	initArrayReparacion(reparacion, MAX);

	int firstArray;

	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "AO4OD0S0", marca[1], 2015);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "AB0D020S", marca[2], 2015);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "CLDL4LWL", marca[3], 2009);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "AD2DS000", marca[2], 2002);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "AR2DS000", marca[4], 2018);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "FD2HS000", marca[1], 2007);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "DI5WS0A7", marca[4], 2010);
	firstArray = searchFirstEmptyElectro(electro, MAX);
	addElectro(electro, firstArray, "AO27S064", marca[0], 2012);

	firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	Fecha fechaHardCode[9];

	strcpy(fechaHardCode[0].completeDate, "01/05/20");
	strcpy(fechaHardCode[1].completeDate, "22/10/20");
	strcpy(fechaHardCode[2].completeDate, "24/05/20");
	strcpy(fechaHardCode[3].completeDate, "23/10/20");
	strcpy(fechaHardCode[4].completeDate, "23/10/20");
	strcpy(fechaHardCode[5].completeDate, "06/07/20");
	strcpy(fechaHardCode[6].completeDate, "04/02/20");
	strcpy(fechaHardCode[7].completeDate, "15/08/20");
	strcpy(fechaHardCode[8].completeDate, "04/11/20");

	addReparacion(reparacion, firstArray, fechaHardCode[0], electro[0],
			servicio[0], cliente[7]);

	firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	addReparacion(reparacion, firstArray, fechaHardCode[1], electro[5],
			servicio[1], cliente[0]);

	firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	addReparacion(reparacion, firstArray, fechaHardCode[2], electro[1],
			servicio[1], cliente[5]);

	 firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	 addReparacion(reparacion, firstArray, fechaHardCode[3], electro[7], servicio[2], cliente[8]);

	 firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	 addReparacion(reparacion, firstArray, fechaHardCode[4], electro[1], servicio[1], cliente[1]);

	 firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	 addReparacion(reparacion, firstArray, fechaHardCode[5], electro[4], servicio[2], cliente[3]);

	 firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	 addReparacion(reparacion, firstArray, fechaHardCode[6], electro[4], servicio[1], cliente[2]);

	 firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	 addReparacion(reparacion, firstArray, fechaHardCode[7], electro[6], servicio[3], cliente[4]);

	 firstArray = searchFirstEmptyReparacion(reparacion, MAX);
	 addReparacion(reparacion, firstArray, fechaHardCode[8], electro[2], servicio[3], cliente[6]);

	flagClean = 0;

	do {

		if (flagClean == 1) {
			system("pause");
			system("cls");
		}
		if (flagClean == 0) {
			++flagClean;
		}

		response = menu();

		switch (response) {

		case 1:
			//ALTA ELECTRODOMESTICO
			emptyArray = searchFirstEmptyElectro(electro, MAX);

			flag1 = 0;
			marcaChoice = 0;

			tempElectro.id = emptyArray + 1;

			printf("Se ingresara un electrodomestico en el id #%d.\n",
					tempElectro.id);

			if (flag1 == 0) {
				flag1 +=
						setString(tempElectro.serie,
								"Ingrese el codigo de serie (8 alfanumericos)",
								"Ingreso de codigo de serie cancelado tras reiterados intentos",
								8, 8, 3);
			}

			if (flag1 == 0) {
				printf("Ingrese el id de la marca del electrodomestico\n");
				printMarcas(marca);

				flag1 += setInt(&tempElectro.marcaElectro.id,
						"Elija de la lista", "Ingreso de marca cancelado", 1001,
						1005, 3);

				for (int i = 0; i <= 4; i++) {
					if (tempElectro.marcaElectro.id == marca[i].id) {
						marcaChoice = i;
						strcpy(tempElectro.marcaElectro.descripcion,
								marca[i].descripcion);
						break;
					}
				}
			}

			if (flag1 == 0) {
				flag1 += setInt(&tempElectro.modelo,
						"Ingrese el anio de fabricacion del modelo(2000,2020)",
						"Ingreso incorrecto", 2000, 2020, 3);
			}

			if (flag1 == 0) {
				printf("Ingreso de electrodomestico exitoso\n");
				addElectro(electro, emptyArray, tempElectro.serie,
						marca[marcaChoice], tempElectro.modelo);
			} else {

				printf("Ingreso de electrodomestico cancelado\n");
			}

			break;
		case 2:

			printf("Electrodomesticos existentes:\n");
			arrayLength = printArrayElectro(electro, MAX);
			printf("Array length = %d\n", arrayLength);
			idToChange = -1;
			dataToChange = 0;
			arrayPosition = -1;
			flag2 = 0;

			flag2 += setInt(&idToChange, "Ingrese el id del electrodomestico\n",
					"Modificacion de electrodomestico cancelada", 1,
					arrayLength, 3);
			arrayPosition = getElectroArrayPositionById(electro, MAX,
					idToChange);
			if (arrayPosition != -1) {
				printf("1 - Serie\n");
				printf("2 - Marca\n");
				printf("3 - Modelo\n");
				flag2 = setInt(&dataToChange,
						"Que informacion desea modificar?\n",
						"Modificacion cancelada", 1, 3, 3);
			}
			switch (dataToChange) {

			case 1:
				flag2 +=
						setString(tempElectro.serie,
								"Ingrese el codigo de serie (8 alfanumericos)",
								"Ingreso de codigo de serie cancelado tras reiterados intentos",
								8, 8, 3);
				if (flag2 == 0) {
					strcpy(electro[arrayPosition].serie, tempElectro.serie);
				}

				break;

			case 2:
				printf("Ingrese el id de la marca del electrodomestico\n");
				printMarcas(marca);

				flag2 += setInt(&tempElectro.marcaElectro.id,
						"Elija de la lista", "Ingreso de marca cancelado", 1001,
						1005, 3);

				for (int i = 0; i <= 4; i++) {
					if (tempElectro.marcaElectro.id == marca[i].id) {
						marcaChoice = i;
						strcpy(tempElectro.marcaElectro.descripcion,
								marca[i].descripcion);
						break;
					}
				}
				if (flag2 == 0) {
					strcpy(electro[arrayPosition].marcaElectro.descripcion,
							tempElectro.marcaElectro.descripcion);
					electro[arrayPosition].marcaElectro.id =
							tempElectro.marcaElectro.id;
				}
				break;

			case 3:

				flag2 += setInt(&tempElectro.modelo,
						"Ingrese el anio de fabricacion del modelo(2000,2020)",
						"Ingreso incorrecto", 2000, 2020, 3);
				if (flag2 == 0) {
					electro[arrayPosition].modelo = tempElectro.modelo;
					break;

				}

				if (flag2 == 0) {
					printf("Modificacion de electrodomestico exitoso\n");

				} else {
					printf("Modificacion de electrodomestico cancelada\n");
				}
			}

			break;
		case 3:

			printf("Electrodomesticos existentes:\n");
			arrayLength = printArrayElectro(electro, MAX);
			printf("Array length = %d\n", arrayLength);
			idToChange = -1;
			dataToChange = 0;
			arrayPosition = -1;
			flag2 = 0;
			char flagDelete = 'n';

			flag2 +=
					setInt(&idToChange, "Ingrese el id del electrodomestico\n",
							"Ingreso erroneo. Modificacion de electrodomestico cancelada",
							1, arrayLength, 3);
			arrayPosition = getElectroArrayPositionById(electro, MAX,
					idToChange);
			if (arrayPosition != -1 && electro[arrayPosition].isEmpty == 0) {
				printf(
						"Esta a punto de eliminar el Electrodomestico de id %d, esta seguro(s/n)?\n",
						idToChange);

				fflush(stdin);
				scanf("%c", &flagDelete);

				if (flagDelete == 's') {
					printf("Electrodomestico eliminado\n");
					addElectro(electro, arrayPosition, "___EMPTY", marcaEmpty,
							1000);
					electro[arrayPosition].isEmpty = 1;

				} else {
					printf("Operacion cancelada\n");
				}
			} else if (electro[arrayPosition].isEmpty != 0
					&& arrayPosition != -1) {
				printf("El id est� vacio\n");
			}

			break;
		case 4:
			printArrayElectro(electro, MAX);
			break;
		case 5:
			printMarcas(marca);
			break;
		case 6:
			printServicios(servicio);
			break;
		case 7:
			;
			//ALTA REPARACION

			emptyArray = searchFirstEmptyReparacion(reparacion, MAX);
			flag7 = 0;
			arrayPosition = -1;

			tempR.id = emptyArray + 1;

			printf("Se ingresara una Reparacion en el id de Reparacion #%d.\n",
					tempR.id);

			printf("Electrodomesticos existentes:\n");
			arrayLength = printArrayElectro(electro, MAX);
			printf("array length = %d", arrayLength);

			flag7 += setInt(&idToChange, "Ingrese el id del electrodomestico\n",
					"Modificacion de electrodomestico cancelada", 1,
					arrayLength, 3);
			arrayPosition = getElectroArrayPositionById(electro, MAX,
					idToChange);
			tempR.ElectroR = electro[arrayPosition];

			if (flag7 == 0) {

				arrayPosition = -1;
				printf("Clientes disponibles:\n");
				printClientes(cliente);
				flag7 += setInt(&clienteChoice, "Ingrese el id del cliente\n",
						"Eleccion de servicio cancelada", 501, 509, 3);
				arrayPosition = clienteChoice - 500 - 1;

			}

			if (flag7 == 0) {
				tempR.clienteR = cliente[arrayPosition];

				arrayPosition = -1;
				printf("Servicios disponibles:\n");
				printServicios(servicio);
				flag7 += setInt(&servicioChoice, "Ingrese el id del servicio\n",
						"Eleccion de servicio cancelada", 20001, 20004, 3);
				arrayPosition = servicioChoice - 20000 - 1;

			}

			if (flag7 == 0) {
				tempR.ServicioR = servicio[arrayPosition];
				flag7 += setStringFecha(&tempR.fecha,
						"Ingreso de fecha cancelado", 2020, 2020, 3);
			}

			if (flag7 == 0) {
				printf("Ingreso de Reparacion exitoso\n");
				addReparacion(reparacion, emptyArray, tempR.fecha,
						tempR.ElectroR, tempR.ServicioR, tempR.clienteR);
			} else {

				printf("Ingreso de reparacion cancelado\n");
			}
			break;
		case 8:
			printArrayReparacion(reparacion, MAX);
			break;
		case 9:
			response = -1;
			break;
		case 10:
			;

			orderReparacionBySerieCode(reparacion, MAX);
			break;
		}
	} while (response != -1);

	system("pause");
	return EXIT_SUCCESS;
}

int menu() {
	retorno = 0;
	flagExitM = 's';

	do {
		reparacionesAdded = getReparacionesAdded(reparacion, MAX);
		electrosAdded = getElectrosAdded(electro, MAX);

		printf("Bienvenido al menu principal\n");
		printf("\nCantidad de Electrodomesticos ingresados = %d.\n",
				electrosAdded);
		if (electrosAdded == 0)
			printf(
					"\nModificacion, eliminacion, listado de Electrodomesticos \ny alta de Reparaciones no disponibles\n");
		printf("\nCantidad de Reparaciones ingresadas = %d.\n",
				reparacionesAdded);
		if (reparacionesAdded == 0)
			printf("\nListado de Reparaciones no disponibles\n");

		printf("\nElija una opcion: \n");
		printf("1 - Agregar electrodomestico \n");
		if (electrosAdded != 0) {
			printf("2 - Modificar electrodomestico\n");
			printf("3 - Eliminar electrodomestico\n");
			printf("4 - Listar electrodomesticos\n");
		}
		printf("5 - Listar marcas\n");
		printf("6 - Listar servicios\n");
		if (electrosAdded != 0) {
			printf("7 - Alta reparacion\n");
		}
		if (reparacionesAdded != 0) {
			printf("8 - Lista reparaciones\n");
		}
		printf("9 - Salir \n");

		fflush( stdin);
		scanf("\n%d", &retorno);

		if (!(retorno >= 1 && retorno <= 10)) {
			printf("Opcion incorrecta\n");
		}
		if (retorno == 9) {
			printf("Esta seguro que desea salir?(s/n)\n");
			fflush( stdin);
			scanf("\n%c", &flagExitM);
		}
		if (retorno == 9 && flagExitM == 's') {
			printf("Adios!\n");

		}
		if (retorno == 9 && flagExitM != 's') {
			printf("Operacion cancelada\n");
			flagExitM = 'n';
			retorno = 0;
		}

	} while (!(retorno >= 1 && retorno <= 10));

	return retorno;
}