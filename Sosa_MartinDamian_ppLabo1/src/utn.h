/*
 * utn.h
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#ifndef UTN_H_
#define UTN_H_

int GetChar(char*,char*,char*,char,char,int);
int GetInt(int*,char*,char*,int,int,int);
int GetFloat(float*,char*,char*,float,float,int);


int esPar(char[],char[]);
int getFactorial(char[],char[],int);

void InicializarArrayDeNumeros(int[],int,int);
void CargarArrayDeNumerosSecuencial(int [],int);
void MostrarArrayDeNumeros(int [],int,int);

int SacarNotaMaxima(int[],int);
int SacarSumaAcumulada(int[],int);
int SacarCantidadDeAprobados (int[],int,int);
float SacarPromedio(int[],int,int);
int SacarCantidadDeNotas(int[],int,int);


#endif /* UTN_H_ */
