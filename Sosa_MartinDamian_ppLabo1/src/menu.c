/*
 * menu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */



#include <stdio.h>
int Menu(){
	int miOpcion;
	printf("\nMENU DE OPCIONES \n");
	printf("------------------\n");
	printf("1. ALTA\n");
	printf("2. BAJA\n");
	printf("3. MODIFICACION\n");
	printf("4. MOSTRAR AVIONES\n");
	printf("5. MOSTRAR VIAJES\n");
	printf("6. MOSTRAR MARCAS\n");
	printf("-----------------\n");
	printf("    Informes\n");
	printf("-----------------\n");
	printf("7. MOSTRAR AVIONES BOING\n");
	printf("8. MOSTRAR AVIONES DE UNA MARCA\n");
	printf("9. MOSTRAR MATRICULA Y MARCA DE AVIONES A NEUQUEN\n");
	printf("10.INFORMAR KMS RECORRIDOS POR AVIONES MARCA ATR \n");
	printf("11. \n");
	printf("12. \n");
	printf("13. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &miOpcion);
    return miOpcion;
}
