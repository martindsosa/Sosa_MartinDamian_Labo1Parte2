/*
 * avion.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#include "avion.h"
#define LIBRE 1
#define OCUPADO 0
/**
 * \fn void InicializarAviones(eAvion[], int)
 * \brief Inicializa el array de aviones en libre
 * \param listaAviones array de aviones
 * \param tam tamaño del vector de aviones
 */
void InicializarAviones(eAvion listaAviones[],int tam){
    int i;
    for (i=0;i<tam;i++){
        listaAviones[i].isEmpty = LIBRE;
    }
}
