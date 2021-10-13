/*
 * avion-marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
#include "avion.h"
#include "viaje.h"
#include "avion-marca.h"
#include "utn.h"

#define LIBRE 1
#define OCUPADO 0

/**
 * \fn int SubMenu()
 * \brief
 * \param
 * \param
 * \return devuelve INT numero elegido del menu
 */
int SubMenu(){
	int miOpcion;
	printf("\nSUBMENU MODIFICACIONES \n");
	printf("-----------------------\n");
	printf("1. MODELO\n");
	printf("2. CANTIDAD DE ASIENTOS\n");
	printf("3. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &miOpcion);
    return miOpcion;
}
/**
 * \fn int BuscarAvionLibre(eAvion*, int)
 * \brief Determina si hay espacio en el array de aviones
 * \param listaAviones
 * \param sizeAvion
 * \return INT el indice encontrado o -1 si no encontro lugar libre
 */
int BuscarAvionLibre(eAvion* listaAviones, int sizeAvion)
{
    int i;
    int index = -1;
    for(i=0; i<sizeAvion; i++)
    {
        if(listaAviones[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * \fn void CargarListadoAviones(eAvion[], int, int*, eMarca[], int, eViaje[], int)
 * \brief
 * \param listaAviones
 * \param sizeAvion tamaño del array aviones
 * \param numAvion int
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 * \param listaViajes
 * \param sizeViajes tamño del array de viajes
 */
void CargarListadoAviones(eAvion listaAviones[],int sizeAvion,int* numAvion,eMarca listaMarcas[],int sizeMarca,eViaje listaViajes[],int sizeViajes)
{
    int encontro;
    encontro = BuscarAvionLibre(listaAviones,sizeAvion);
    if(encontro!=-1){
       listaAviones[encontro] = CargarUnAvion(numAvion,listaMarcas,sizeMarca,listaViajes,sizeViajes);
    }
    else{
        printf("No hay espacio para un nuevo avion");
    }
}
/**
 * \fn eAvion CargarUnAvion(int*, eMarca[], int, eViaje[], int)
 * \brief
 * \param numAvion
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 * \param listaViajes
 * \param sizeViajes tamaño del array de viajes
 * \return devuelve la estructura del avion dada de alta
 */
eAvion CargarUnAvion (int* numAvion,eMarca listaMarcas[],int sizeMarca,eViaje listaViajes[],int sizeViajes)
{
    eAvion miAvion;
    int matricula;
    int fecha;
    int viaje;
    int marca;
    int modelo;
    int cantAsientos=0;

    miAvion.idAvion = *numAvion;
    (*numAvion)++;


    if(!GetInt(&matricula,"Ingrese numero de matricula : ","Error!!! \n",0,999999,2)){
		miAvion.matricula = matricula;
	}else{
		miAvion.matricula = 0;
	}

    if(!GetInt(&fecha,"Ingrese fecha ddmmaaaa : ","Error!!! \n",0,99999999,2)){
		miAvion.fecha = fecha;
	}else{
		miAvion.fecha = 0;
	}
    MostrarViajes(listaViajes,sizeViajes);
    if(!GetInt(&viaje,"Ingrese id viaje : ","Error!!! \n",100,104,2)){
		miAvion.idViaje = viaje;
	}else{
		miAvion.idViaje = 0;
	}

    MostrarMarcas(listaMarcas,sizeMarca);
    if(!GetInt(&marca,"Ingrese id marca : ","Error!!! \n",1000,1003,2)){
		miAvion.idMarca = marca;
	}else{
		miAvion.idMarca = 0;
	}

    if (!GetInt(&modelo,"Ingrese modelo(anio): ","Error!!!(0-2021)\n",0,2021,2)){
		miAvion.modelo = modelo;
	}else{
		miAvion.modelo = 0;
	}
    if(!GetInt(&cantAsientos,"Ingrese cantidad de asientos (maximo 600): ","Error!!!(0-600) \n",0,600,2)){
		miAvion.cantAsientos = cantAsientos;
	}else{
		miAvion.cantAsientos = 0;
	}
    miAvion.isEmpty = OCUPADO;
    return miAvion;
}
/**
 * \fn int BajaAvion(eAvion[], int, eMarca[], int, eViaje[], int)
 * \brief
 * \param listaAviones
 * \param sizeAvion tamaño del array de aviones
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 * \param listaViajes
 * \param sizeViaje tamaño del array de viajes
 * \return devuelve el estado de la baja 0(no se realizo baja) 1(baja) -1(no hay aviones dados de alta)
 */
int BajaAvion(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca,eViaje listaViajes[],int sizeViaje)
{
    int i;
    int auxMatricula;
    int avionDadoDeBaja = 0;
    if(MostrarAviones(listaAviones,sizeAvion,listaMarcas,sizeMarca,listaViajes,sizeViaje)== 1){
    	printf("Ingrese matricula del avion a dar de baja: ");
		scanf ("%d",&auxMatricula);
		for (i=0;i<sizeAvion;i++){
			if(auxMatricula == listaAviones[i].matricula){
				listaAviones[i].isEmpty = LIBRE;
				avionDadoDeBaja = 1;
				break;
			}
		}
    }else{
    	avionDadoDeBaja = -1;
	}
    return avionDadoDeBaja;
}
/**
 * \fn int MostrarViajes(eViaje[], int)
 * \brief
 * \param listaViajes
 * \param sizeViajes
 * \return devuelve 0-> si no hay viajes 1->si hay viajes
 */
int MostrarViajes(eViaje listaViajes[],int sizeViajes){
	int i;
	int flagHayViaje = 0;
	printf("  \t LISTADO DE VIAJES \n");
	printf("-------------------------------------\n");
	printf("ID VIAJE \t   DESCRIPCION \t KMS\n");
	for (i=0;i<sizeViajes;i++)
	{
		if(listaViajes[i].isEmpty == OCUPADO)
		{
			MostrarUnViaje(listaViajes[i]);
			flagHayViaje = 1;
		}
	}
	return flagHayViaje;
}
/**
 * \fn void MostrarUnViaje(eViaje)
 * \brief Muestra los datos de un viaje
 * \param miViaje estructura de un viaje
 */
void MostrarUnViaje(eViaje miViaje){

    printf("%4d \t %20s \t %5.2f \n",miViaje.idViaje,miViaje.descripcion,miViaje.kms);
}
/**
 * \fn void OrdenarAvionesPorMarcaMatricula(eAvion[], int)
 * \brief Ordena en forma descendente el array de aviones por numero de marca y matricula
 * \param listaAviones array de aviones
 * \param sizeAviones tamaño del array de aviones
 */
void OrdenarAvionesPorMarcaMatricula(eAvion listaAviones[],int sizeAviones){
	int i;
	int j;
	eAvion auxAvion;
	for(i=0; i<sizeAviones-1; i++){
		for(j=i+1; j<sizeAviones; j++){
			if(listaAviones[i].idMarca > listaAviones[j].idMarca){
			   auxAvion  =  listaAviones[i];
			   listaAviones[i] = listaAviones[j];
			   listaAviones[j] = auxAvion;
			}else{
			   if(listaAviones[i].idMarca == listaAviones[j].idMarca){
				   if(listaAviones[i].matricula > listaAviones[j].matricula){
					   auxAvion  =  listaAviones[i];
					   listaAviones[i] = listaAviones[j];
					   listaAviones[j] = auxAvion;
					}
			   }
			}
		}
	}
}
/**
 * \fn int MostrarAviones(eAvion[], int, eMarca[], int, eViaje[], int)
 * \brief
 * \param listaAviones
 * \param sizeAvion tamaño del array de aviones
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 * \param listaViajes
 * \param sizeViaje tamaño del array de viajes
 * \return devuelve 0(si no hay aviones) 1(si hay aviones)
 */
int MostrarAviones(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca,eViaje listaViajes[],int sizeViaje)
{
    int i;
    int flagHayAvion = 0;
    char descMarca[20] = " ";
    int indiceMarca = 0;
    char descViaje[25] = " ";
    int indiceViaje = 0;

    printf("  LISTADO DE AVIONES \n");
    printf("----------------------\n");
    printf("ID AVION \t MATRICULA \tFECHA \t\t\t\tVIAJE \t\t\tMARCA   \tMODELO \tCANT DE ASIENTOS\n");
    for (i=0;i<sizeAvion;i++)
    {
        if(listaAviones[i].isEmpty == OCUPADO)
        {
        	indiceMarca = BuscarMarca(listaMarcas,sizeMarca,listaAviones[i].idMarca);
        	if( indiceMarca != -1){
        		strcpy(descMarca,listaMarcas[indiceMarca].descripcion);
        	}else{
        		strcpy(descMarca,"SIN MARCA");
        	}
        	indiceViaje = BuscarViaje(listaViajes,sizeViaje,listaAviones[i].idViaje);
			if( indiceViaje != -1){
				strcpy(descViaje,listaViajes[indiceViaje].descripcion);
			}else{
				strcpy(descViaje,"SIN VIAJE");
			}
            MostrarUnAvion(listaAviones[i],descMarca,descViaje);
            flagHayAvion = 1;
        }
    }
    return flagHayAvion;
}
/**
 * \fn void MostrarUnAvion(eAvion, char[], char[])
 * \brief	Muestra los datos de un avion
 * \param miAvion estructura de un avion
 * \param descripcion marca del avion
 * \param descViaje viaje realizado por el avion
 */
void MostrarUnAvion(eAvion miAvion,char descripcion[],char descViaje[])
{

    printf("%4d \t\t%6d \t\t%8d    %25s  \t%20s  \t\t%4d \t\t%4d\n",miAvion.idAvion
                    	  	  	  	  	   						   ,miAvion.matricula
																   ,miAvion.fecha
																   ,descViaje
																   ,descripcion
																   ,miAvion.modelo
																   ,miAvion.cantAsientos);
}
/**
 * \fn int ModificarAvion(eAvion[], int, eMarca[], int, eViaje[], int)
 * \brief Modificacion de datos de avion
 * \param listaAviones
 * \param sizeAvion tamaño del array de aviones
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 * \param listaViajes
 * \param sizeViaje tamaño del array de viajes
 * \return devuelve 0-> si no se realizo modificacion 1->si se modifico
 */
int ModificarAvion(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca,eViaje listaViajes[],int sizeViaje)
{
    int posicion= -1;
    int flagModificacion = 0;
    int auxModelo;
    int auxCantAsientos;
    int intento = 0;
    int auxMatricula;
    int opcion;

    if(MostrarAviones(listaAviones,sizeAvion,listaMarcas,sizeMarca,listaViajes,sizeViaje)== 1){
    	printf("Ingrese matricula de avion a MODIFICAR: ");
		scanf ("%d",&auxMatricula);
		do{
			posicion = BuscarAvion(listaAviones,sizeAvion,auxMatricula);
			if (posicion == -1){
				MostrarAviones(listaAviones, sizeAvion, listaMarcas, sizeMarca,listaViajes,sizeViaje);
				printf("\nError Reingrese matricula: ");
				scanf("%d",&auxMatricula);
				intento++;
			}

		}while(intento<3 && posicion == -1);
		if(intento <3 && posicion != -1){
			do{
				opcion = SubMenu();
				switch(opcion){
				case 1:
				    if(!GetInt(&auxModelo,"Ingrese modelo : ","Error!!! \n",0,2021,2)){
				    	listaAviones[posicion].modelo = auxModelo;
				    	flagModificacion = 1;
				    }
				break;
				case 2:
					if(!GetInt(&auxCantAsientos,"Ingrese cantidad de asientos : ","Error!!! \n",0,600,2)){
						listaAviones[posicion].cantAsientos = auxCantAsientos;
						flagModificacion = 1;
					}
				break;
				default:
					printf("Opcion ingresada erronea. Reingrese\n");
				}
			}while(opcion!=3);
		}
	}else{
		flagModificacion = -1;
	}
    return flagModificacion;
}
/**
 * \fn void MostrarMarcas(eMarca[], int)
 * \brief Muestra el listado de marcas
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 */
void MostrarMarcas(eMarca listaMarcas[],int sizeMarca)
{
    int i;
    int flagHayMarcas = 0;
    printf("   LISTADO DE MARCAS \n");
    printf(" ------------------------ \n");
    printf("NUMERO\t\t DESCRIPCION\n");
    for (i=0;i<sizeMarca;i++)
    {
        if(listaMarcas[i].isEmpty == OCUPADO)
        {
            MostrarUnaMarca(listaMarcas[i]);
            flagHayMarcas = 1;
        }
    }
    if (flagHayMarcas != 1)
    {
        printf ("No hay marcas cargadas ");
    }
}
/**
 * \fn void MostrarUnaMarca(eMarca)
 * \brief Muestra una marca por pantalla
 * \param miMarca datos de una marca
 */
void MostrarUnaMarca(eMarca miMarca)
{
	printf("%4d \t %15s \n",miMarca.id,miMarca.descripcion);
}
/**
 * \fn int BuscarMarca(eMarca[], int, int)
 * \brief Determina si hay una marca en el array de marcas
 * \param listaMarcas
 * \param sizeMarca tamaño del array de marcas
 * \param marca id de marca a buscar
 * \return devuelve indice si se encontro -1 si no encontro la marca en el array
 */
int BuscarMarca(eMarca listaMarcas[],int sizeMarca,int marca){
	int i;
	int indice = -1;

	for (i=0;i<sizeMarca;i++){
		if(listaMarcas[i].id == marca){
			indice = i;
			break;
		}
	}
	return indice;
}
/**
 * \fn int BuscarViaje(eViaje[], int, int)
 * \brief Determina si hay un viaje en el array de viajes
 * \param listaViajes
 * \param sizeViajes tamaño del array de viajes
 * \param viaje id de viaje a buscar
 * \return devuelve indice si se encontro -1 si no encontro el viaje en el array
 */
int BuscarViaje(eViaje listaViajes[],int sizeViajes,int viaje){
	int i;
	int indice = -1;

	for (i=0;i<sizeViajes;i++){
		if(listaViajes[i].idViaje == viaje){
			indice = i;
			break;
		}
	}
	return indice;
}
/**
 * \fn int BuscarAvion(eAvion[], int, int)
 * \brief Determina si hay una matricula en el array de aviones
 * \param listaAviones
 * \param sizeAvion tamaño del array de aviones
 * \param matricula numero de matricula
 * \return devuelve indice si se encontro -1 si no encotro la matricula en el array
 */
int BuscarAvion(eAvion listaAviones[],int sizeAvion,int matricula){
    int i;
    int indice = -1;
    for (i=0;i<sizeAvion;i++){
        if(listaAviones[i].matricula == matricula){
            indice = i;
            break;
        }
    }
    return indice;
}
int MostrarAvionesBoing(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca,eViaje listaViajes[],int sizeViaje){
	int i;
	int flagHayAvion = 0;
	int indiceViaje;
	int indiceMarca;
	char descripcionMarca[25] = " ";
	char descripcionViaje[20];
	printf("AVIONES BOING\n");
	printf("----------------------\n");
	for(i=0;i<sizeAvion;i++){
		if(listaAviones[i].idMarca == 1000 && listaAviones[i].isEmpty == OCUPADO){
			if(flagHayAvion == 0){
				printf("ID AVION \t MATRICULA \tFECHA \t\t\t\tVIAJE \t\t\tMARCA   \tMODELO \tCANT DE ASIENTOS\n");
				flagHayAvion = 1;
			}
			indiceMarca = BuscarMarca(listaMarcas,sizeMarca,listaAviones[i].idMarca);
			strcpy(descripcionMarca,listaMarcas[indiceMarca].descripcion);
			indiceViaje = BuscarViaje(listaViajes,sizeViaje,listaAviones[i].idViaje);
			if( indiceViaje != -1){
				strcpy(descripcionViaje,listaViajes[indiceViaje].descripcion);
			}else{
				strcpy(descripcionViaje,"SIN VIAJE");
			}
			MostrarUnAvion(listaAviones[i],descripcionMarca,descripcionViaje);
		}
	}
	return flagHayAvion;
}
int MostrarAvionesMarcaSeleccionada(eAvion listaAviones[],
									int sizeAvion,
									eMarca listaMarcas[],
									int sizeMarca,
									eViaje listaViajes[],
									int sizeViaje){
	int i;
	int flagHayAvion = 0;
	int indiceViaje;
	int indiceMarca;
	int idMarca;
	char descripcionMarca[25] = " ";
	char descripcionViaje[20];
	MostrarMarcas(listaMarcas,sizeMarca);
	if(!GetInt(&idMarca,"Ingrese id marca : ","Error!!! \n",1000,1003,2)){
		indiceMarca = BuscarMarca(listaMarcas,sizeMarca,idMarca);
		strcpy(descripcionMarca,listaMarcas[indiceMarca].descripcion);
		printf("AVIONES MARCA %s\n",descripcionMarca);
		printf("----------------------\n");
		for(i=0;i<sizeAvion;i++){
			if(listaAviones[i].idMarca == idMarca && listaAviones[i].isEmpty == OCUPADO){
				if(flagHayAvion == 0){
					printf("ID AVION \t MATRICULA \tFECHA \t\t\t\tVIAJE \t\t\tMARCA   \tMODELO \tCANT DE ASIENTOS\n");
					flagHayAvion = 1;
				}
				indiceMarca = BuscarMarca(listaMarcas,sizeMarca,listaAviones[i].idMarca);
				strcpy(descripcionMarca,listaMarcas[indiceMarca].descripcion);
				indiceViaje = BuscarViaje(listaViajes,sizeViaje,listaAviones[i].idViaje);
				if( indiceViaje != -1){
					strcpy(descripcionViaje,listaViajes[indiceViaje].descripcion);
				}else{
					strcpy(descripcionViaje,"SIN VIAJE");
				}
				MostrarUnAvion(listaAviones[i],descripcionMarca,descripcionViaje);
			}
		}
	}
	else{
		flagHayAvion = -1;
	}
	return flagHayAvion;
}
int MostrarMatriculaMarcaNeuquen(eAvion listaAviones[],
								int sizeAvion,
								eMarca listaMarcas[],
								int sizeMarca,
								eViaje listaViajes[],
								int sizeViaje){
	int i;
	int flagHayAvion = 0;
	int indiceMarca;
	char descripcionMarca[25] = " ";

	printf("   AVIONES A NEUQUEN\n");
	printf("----------------------\n");
	for(i=0;i<sizeAvion;i++){
		if(listaAviones[i].idViaje == 102 && listaAviones[i].isEmpty == OCUPADO){
			if(flagHayAvion == 0){
				printf("MATRICULA \t\t\tMARCA\n");
				flagHayAvion = 1;
			}
			indiceMarca = BuscarMarca(listaMarcas,sizeMarca,listaAviones[i].idMarca);
			strcpy(descripcionMarca,listaMarcas[indiceMarca].descripcion);
			MostrarUnAvionNeuquen(listaAviones[i],descripcionMarca);
		}
	}
	return flagHayAvion;
}
void MostrarUnAvionNeuquen(eAvion miAvion,char descripcionMarca[])
{
    printf("%10d \t%20s\n",miAvion.matricula,descripcionMarca);
}
int MostrarKmsAtr(eAvion listaAviones[],int sizeAvion,eViaje listaViajes[],int sizeViaje){
	int i;
	int j;
	int flagHayAvion = 0;
	float totalKmsAtr = 0;
	printf(" AVIONES MARCA ATR\n");
	printf("-------------------\n");
	for(i=0;i<sizeAvion;i++){
		if(listaAviones[i].idMarca == 1002 && listaAviones[i].isEmpty == OCUPADO){
			for(j=0;j<sizeViaje;j++){
				if (listaAviones[i].idViaje == listaViajes[j].idViaje){
					totalKmsAtr += listaViajes[j].kms;
					flagHayAvion = 1;
				}
			}
		}
	}
	if (totalKmsAtr != 0){
		printf("Total de KMS: %.2f",totalKmsAtr);
	}
	return flagHayAvion;
}
