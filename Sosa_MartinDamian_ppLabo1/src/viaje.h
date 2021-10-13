/*
 * viaje.h
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#ifndef VIAJE_H_
#define VIAJE_H_

typedef struct{
	int idViaje;
	char descripcion[25];
	float kms;
	int isEmpty;
}eViaje;
void HardCodearViaje(eViaje listaViajes[],int);

#endif /* VIAJE_H_ */
