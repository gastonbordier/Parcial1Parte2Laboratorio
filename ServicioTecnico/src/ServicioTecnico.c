/*
 ============================================================================
 Name        : ServicioTecnico.c
 Author      : Gaston Bordier
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
				printf("El id está vacio\n");
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

			filter2020Reparacion(reparacion, MAX);
			break;
		case 10:
			filterElectrodomesticoByMarca(electro, MAX, marca);
			break;
		case 11:
			showReparacionesByElectrodomestico(electro, reparacion, MAX);
			break;
		case 12:
			facturacionTotalPorMantenimientos(reparacion, MAX);
			break;
		case 21:
			response = -1;
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
			printf("9 - Mostrar electrodomesticos del anio 2020\n");
			printf(
					"10 - Mostrar electrodomesticos de una marca seleccionada\n");
			printf(
					"11 - Mostrar todas las reparaciones efectuadas al electrodomestico seleccionado\n");
			printf("12 - Sumar lo recaudado por mantenimientos.\n");


		}
		printf("21 - Salir \n");

		fflush( stdin);
		scanf("\n%d", &retorno);

		if (!(retorno >= 1 && retorno <= 21)) {
			printf("Opcion incorrecta\n");
		}
		if (retorno == 21) {
			printf("Esta seguro que desea salir?(s/n)\n");
			fflush( stdin);
			scanf("\n%c", &flagExitM);
		}
		if (retorno == 21 && flagExitM == 's') {
			printf("Adios!\n");

		}
		if (retorno == 21 && flagExitM != 's') {
			printf("Operacion cancelada\n");
			flagExitM = 'n';
			retorno = 0;
		}

	} while (!(retorno >= 1 && retorno <= 21));

	return retorno;
}
