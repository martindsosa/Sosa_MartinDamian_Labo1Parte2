/*
 * avion.h
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#ifndef AVION_H_
#define AVION_H_
typedef struct{
	int idAvion;
	int matricula;
	int fecha;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int isEmpty;
}eAvion;
void InicializarAviones(eAvion[],int);

#endif /* AVION_H_ */
