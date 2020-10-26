#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int setInt(int *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries) {
	int retorno = -1;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		scanf("%d", pOutput);

		if (*pOutput >= min && *pOutput <= max) {
			printf("Ingreso correcto\n");
			retries = -1;
			retorno = 0;
		} else if (retries > 1) {
			printf("Intentelo nuevamente.\n");
		}

		--retries;
	}
	if (retorno == -1)
		printf("%s\n", errorMessage);
	return retorno;
}


int setString(char *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries) {
	int retorno = -1;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		fgets(pOutput, 13, stdin);

		pOutput[strlen(pOutput) - 1] = '\0';

		if ((strlen(pOutput)) >= min && (strlen(pOutput)) <= max) {
			printf("Ingreso correcto\n");

			//		if (pOutput[0] >= 'a' && pOutput[0] <= 'z') {
			//			pOutput[0] = (char) (('A' - 'a') + pOutput[0]);
			//		}
			retries = -1;
			retorno = 0;
		} else {
			--retries;
			if (retries >= 1) {
				printf("Intentelo nuevamente.\n");
			}
		}

	}
	if (retorno == -1)
		printf("%s\n", errorMessage);

	return retorno;
}


int setFloat(float *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries) {
	int retorno = -1;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		scanf("%f", pOutput);

		if (*pOutput >= (float) min && *pOutput <= (float) max) {
			printf("Ingreso correcto\n");
			retries = -1;
			retorno = 0;
		} else if (retries > 1) {
			printf("Intentelo nuevamente.\n");
		}

		--retries;
	}
	if (retorno == -1)
		printf("%s\n", errorMessage);
	return retorno;
}

int setStringAlphanumeric(char *pOutput, char message[51],
		char errorMessage[51], int min, int max, int retries) {
	int retorno = -1;
	int flagOk = 0;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		fgets(pOutput, 13, stdin);

		pOutput[strlen(pOutput) - 1] = '\0';

		if ((strlen(pOutput)) >= min && (strlen(pOutput)) <= max) {
			flagOk = 1;
		}
		if (flagOk == 1) {
			for (int i = 0; i < strlen(pOutput); i++) {
				if (pOutput[i] >= 'a' && pOutput[i] <= 'z') {
					flagOk = 2;
					pOutput[i] += -32;										//CONVERSION DE MINUSCULAS A MAYUSCULAS

				} else if (pOutput[i] >= 'A' && pOutput[i] <= 'Z') {
					flagOk = 2;
				} else if (pOutput[i] >= '0' && pOutput[i] <= '9') {
					flagOk = 2;
				} else {
					flagOk = 0;
					break;
				}
			}

		}

		if (flagOk == 2) {
			printf("Ingreso correcto\n");
			retries = -1;
			retorno = 0;
		} else {
			--retries;
			if (retries >= 1) {
				printf("Intentelo nuevamente.\n");
			}
		}

	}
	if (retorno == -1)
		printf("%s\n", errorMessage);

	return retorno;
}
