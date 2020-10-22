/*
 * validations.h
 *
 *  Created on: 8 oct. 2020
 *      Author: Gaston
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_


 int setInt(int *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries);
 int setString(char *pOutput, char message[51], char errorMessage[51], int min,
 		int max, int retries);
 int setFloat(float *pOutput, char message[51], char errorMessage[51], int min,
 		int max, int retries);
 int setDate(char *dateDDMMYY);

#endif /* VALIDATIONS_H_ */
