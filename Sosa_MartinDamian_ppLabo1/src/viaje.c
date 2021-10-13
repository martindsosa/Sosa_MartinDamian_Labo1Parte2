/*
 * viaje.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0

#include "viaje.h"
/**
 * \fn void HardCodearViaje(eViaje[], int)
 * \brief Carga de datos en el array de viajes
 * \param listaViajes array de viajes
 * \param tamViaje tamaño del array de viajes
 */
void HardCodearViaje(eViaje listaViajes[],int tamViaje){
    int i;
    int idViaje[5]={100,101,102,103,104};
	char descripcion[5][25]={"Salta","Tucuman","Neuquen","Corrientes","Chubut"};
	float kms[5]={1462.5,1247.6,1139.4,670,1735.8};


    for(i=0; i<tamViaje; i++)
    {
        listaViajes[i].idViaje = idViaje[i];
        strcpy(listaViajes[i].descripcion, descripcion[i]);
        listaViajes[i].kms = kms[i];

        listaViajes[i].isEmpty = OCUPADO;
    }

}
