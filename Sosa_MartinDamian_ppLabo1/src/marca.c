/*
 * marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0

#include "marca.h"
/**
 * \fn void HardCodearMarca(eMarca[], int)
 * \brief Carga de datos del array de marcas
 * \param listaMarcas array de marcas
 * \param tamMarca tamaño de array de marcas
 */
void HardCodearMarca(eMarca listaMarcas[],int tamMarca){
    int i;
    int id[4]={1000,1001,1002,1003};
    char descripcion[4][20]={"Boing","Airbus","ATR","Bombardier"};


    for(i=0; i<tamMarca; i++)
    {
        listaMarcas[i].id = id[i];
        strcpy(listaMarcas[i].descripcion, descripcion[i]);
        listaMarcas[i].isEmpty = OCUPADO;
    }
}
