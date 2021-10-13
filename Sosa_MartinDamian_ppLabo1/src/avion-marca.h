/*
 * avion-marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#ifndef AVION_MARCA_H_
#define AVION_MARCA_H_
#include "marca.h"
#include "avion.h"
#include "viaje.h"
int SubMenu();
int BuscarAvionLibre(eAvion*, int);
int BuscarAvion(eAvion[],int,int);
void CargarListadoAviones(eAvion[],int,int*,eMarca[],int,eViaje[],int);
int MostrarAviones(eAvion[],int,eMarca[],int,eViaje[],int);
void MostrarUnAvion(eAvion,char[],char[]);
eAvion CargarUnAvion (int*,eMarca[],int,eViaje[],int);
int BajaAvion(eAvion[],int,eMarca[],int,eViaje[],int);
int ModificarAvion(eAvion[],int,eMarca[],int,eViaje[],int);
void MostrarUnaMarca(eMarca);
void MostrarMarcas(eMarca[],int);
int BuscarMarca(eMarca[],int,int);
int BuscarViaje(eViaje[],int,int);
void MostrarUnViaje(eViaje);
int MostrarViajes(eViaje[],int);
void OrdenarAvionesPorMarcaMatricula(eAvion[],int);
int MostrarAvionesBoing(eAvion[],int,eMarca[],int,eViaje[],int);
int MostrarAvionesMarcaSeleccionada(eAvion[],int,eMarca[],int,eViaje[],int);
int MostrarMatriculaMarcaNeuquen(eAvion[],int,eMarca[],int,eViaje[],int);
void MostrarUnAvionNeuquen(eAvion,char[]);
int MostrarKmsAtr(eAvion[],int,eViaje[],int);
#endif /* AVION_MARCA_H_ */
