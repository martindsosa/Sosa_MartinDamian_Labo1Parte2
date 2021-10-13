/*
 ============================================================================
 Name        : Sosa_MartinDamian_ppLabo1.c
 Author      : Martin D. Sosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "marca.h"
#include "avion.h"
#include "viaje.h"
#include "avion-marca.h"
#define TAMANIOMARCA 4
#define TAMAVION 3
#define TAMVIAJE 4
#define LIBRE 1
#define OCUPADO 0

int main()
{
    setbuf(stdout,NULL);
    int opcion;
    int resp;
    int numAvion = 1;
    eMarca listaMarcas[TAMANIOMARCA];
    eAvion listaAviones[TAMAVION];
    eViaje listaViajes[TAMVIAJE];

    HardCodearMarca(listaMarcas,TAMANIOMARCA);
    HardCodearViaje(listaViajes,TAMVIAJE);
    InicializarAviones(listaAviones,TAMAVION);
    /*for (int i=0;i<TAMANIOMARCA;i++){
    	printf("marca %d %20s %d \n",listaMarcas[i].id,listaMarcas[i].descripcion,listaMarcas[i].isEmpty);
    }
    for (int i=0;i<TAMVIAJE;i++){
        	printf("Viajes %d %20s %.2f %d \n",listaViajes[i].idViaje,listaViajes[i].descripcion,listaViajes[i].kms,listaViajes[i].isEmpty);
    }*/
    do{
        opcion = Menu();
        switch(opcion){
    	    case 1:
    		    printf("“Ud. ha seleccionado lo opción 1-ALTA\n");
    		    CargarListadoAviones(listaAviones,TAMAVION,&numAvion,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);

        	break;
        	case 2:
    	    	printf("“Ud. ha seleccionado lo opción 2-BAJA”\n");
    	    	resp = BajaAvion(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);
    	    	if (resp == 1){
    	    		printf("AVION dado de BAJA !!!");
    	    	}else if(resp == 0){
    	    		printf("NO se realizo BAJA !!!");
    	    	}else{
    	    		printf("No hay aviones dados de alta !!!");

    	    	}
    	    break;
    	    case 3:
    		    printf("“Ud. ha seleccionado lo opción 3-MODIFICACION”\n");
    		    resp = ModificarAvion(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);
    		    if (resp == 1){
					printf("Se realizo MODIFICACION !!!");
				}else if(resp == 0){
					printf("NO se realizo MODIFICACION !!!");
				}else{
					printf("No hay aviones dados de alta !!!");
				}
    	    break;
		    case 4:
    			printf("“Ud. ha seleccionado lo opción 4-MOSTRAR”\n");
    			OrdenarAvionesPorMarcaMatricula(listaAviones,TAMAVION);
        	    resp = MostrarAviones(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);
        	    if (resp == 0)
        	    {
        	        printf ("No hay AVIONES DADOS DE ALTA !!!");
        	    }
       		break;
    		case 5:
    			printf("“Ud. ha seleccionado lo opción 5-Mostrar viajes”\n");
    			MostrarViajes(listaViajes,TAMVIAJE);
    		break;
    		case 6:
    			printf("“Ud. ha seleccionado lo opción 6-Mostrar marcas\n");
    			MostrarMarcas(listaMarcas,TAMANIOMARCA);

    		break;
    		case 7:
				printf("“Ud. ha seleccionado lo opción 7-”\n");
				resp = MostrarAvionesBoing(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);
				if (resp == 0)
				{
					printf ("No hay AVIONES DADOS DE ALTA !!!");
				}
			break;
    		case 8:
				printf("“Ud. ha seleccionado lo opción 8-\n");
				resp = MostrarAvionesMarcaSeleccionada(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);

				if(resp == 0){
					printf("No hay aviones para la marca ingresada !!!");
				}else if(resp == -1){
					printf("Agoto la cantidad de ingresos de la marca");
				}
			break;
    		case 9:
				printf("“Ud. ha seleccionado lo opción 9-\n");
				resp = MostrarMatriculaMarcaNeuquen(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA,listaViajes,TAMVIAJE);

				if(resp == 0){
					printf("No hay aviones a NEUQUEN !!!");
				}
			break;
    		case 10:
				printf("“Ud. ha seleccionado lo opción 10-\n");
				resp = MostrarKmsAtr(listaAviones,TAMAVION,listaViajes,TAMVIAJE);

				if(resp == 0){
					printf("No hay aviones MARCA ATR !!!");
				}

			break;
    		case 11:
				printf("“Ud. ha seleccionado lo opción 11-\n");

			break;
    		case 12:
				printf("“Ud. ha seleccionado lo opción 12-\n");

			break;

    		case 13:
    			printf("Gracias por usar el Sistema!!!\n");
    		break;
    		default:
    			printf("Opcion ingresada erronea. Reingrese\n");
    	}
    }while(opcion!=13);
    return 0;
}

