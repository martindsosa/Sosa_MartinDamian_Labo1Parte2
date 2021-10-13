/*
 * marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id;
	char descripcion[20];
	int isEmpty;
}eMarca;
void HardCodearMarca(eMarca listaMarcas[],int);

#endif /* MARCA_H_ */
