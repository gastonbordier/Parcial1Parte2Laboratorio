/*
 * validations.h
 *
 *  Created on: 8 oct. 2020
 *      Author: Gaston
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

/*
 * author Gaston Bordier
 * \brief valida ingreso de dato de tipo entero
 * \param *pOutput la variable original int a sobreescribir
 * \param message mensaje a mostrar pidiendo el tipo de ingreso
 * \param errorMessage mensaje a mostrar si la validacion falla
 * \param min entero minimo aceptado
 * \param max entero maximo aceptado
 * \param retries numero de reintentos
 * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
 */
 int setInt(int *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries);

 /*
  * author Gaston Bordier
  * \brief valida ingreso de dato de tipo array de caracteres
  * \param *pOutput la variable original char[] a sobreescribir
  * \param message mensaje a mostrar pidiendo el tipo de ingreso
  * \param errorMessage mensaje a mostrar si la validacion falla
  * \param min cantidad de caracteres minima aceptada
  * \param max cantidad de caracteres maxima aceptada
  * \param retries numero de reintentos
  * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
  */
 int setString(char *pOutput, char message[51], char errorMessage[51], int min,
 		int max, int retries);

 /*
  * author Gaston Bordier
  * \brief valida ingreso de dato de tipo flotante
  * \param *pOutput la variable original float a sobreescribir
  * \param message mensaje a mostrar pidiendo el tipo de ingreso
  * \param errorMessage mensaje a mostrar si la validacion falla
  * \param min flotante minimo aceptado
  * \param max flotante maximo aceptado
  * \param retries numero de reintentos
  * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
  */
 int setFloat(float *pOutput, char message[51], char errorMessage[51], int min,
 		int max, int retries);


 /*
  * author Gaston Bordier
  * \brief valida ingreso de dato de tipo array de caracteres alfanumericos excluyentemente
  * \param *pOutput la variable original char[] a sobreescribir
  * \param message mensaje a mostrar pidiendo el tipo de ingreso
  * \param errorMessage mensaje a mostrar si la validacion falla
  * \param min cantidad de caracteres minima aceptada
  * \param max cantidad de caracteres maxima aceptada
  * \param retries numero de reintentos
  * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
  */
 int setStringAlphanumeric(char *pOutput, char message[51],
 		char errorMessage[51], int min, int max, int retries);

#endif /* VALIDATIONS_H_ */
