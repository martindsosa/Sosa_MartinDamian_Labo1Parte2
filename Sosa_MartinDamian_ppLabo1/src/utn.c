/*
 * utn.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */
#include <stdio.h>
#include <ctype.h>
/** \brief RECIBE UN ENTERO Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param INT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param INT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return INT -1 si salio mal 0 si salio bien
 *
 */
int GetInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno=-1;
    int bufferInt;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
        do{
            printf("%s",mensaje);
            scanf("%d",&bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo){
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else{
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos > 0);
    }
    return retorno;
}
/** \brief RECIBE UN FLOAT Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR LABEL MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param FLOAT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param FLOAT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return FLOAT NUMERO DENTRO DEL RANGO
 *
 */
int GetFloat(char* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
    int retorno=-1;
    int bufferFloat;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
        do{
            printf("%s",mensaje);
            scanf("%d",&bufferFloat);
            if(bufferFloat >= minimo && bufferFloat <= maximo){
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else{
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos > 0);
    }
    return retorno;
}
/** \brief RECIBE UN CHAR Y CONTROLA QUE SEA UNA ENTRE MIN Y MAXIMO
 *
 * \param CHAR MENSAJE PARA PEDIR EL CHAR
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param CHAR MINIMO UNA RESPUESTA ACEPTADA
 * \param CHAR MAXIMO OTRA RESPUESTA ACEPTADA
 * \return INT 0-> si salio todo bien -1->si salio mal
 * *
 */
int GetChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char buffer;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
        do{
            printf ("%s",mensaje);
            scanf("%c",&buffer);
            //__fpurge(stdin);
            fflush(stdin);
            if(buffer >= minimo && buffer <= minimo){
                *pResultado = buffer;
                retorno = 0;
                break;
            }else{
                printf ("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/** \brief RECIBE UN CHAR Y CONTROLA QUE SEA UNA U OTRA RESPUESTA
 *
 * \param CHAR LABEL MENSAJE PARA PEDIR EL CHAR SIN REINTENTOS
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param CHAR RESPUESTA1 UNA RESPUESTA ACEPTADA
 * \param CHAR RESPUESTA2 OTRA RESPUESTA ACEPTADA
 * \return CHAR CARACTER LETRA QUE RESPONDIO
 *
 */
char GetSiNo(char label[],char mensajeError[],char respuesta1,char respuesta2)
{
    char caracter;
    printf ("%s\n",label);
    scanf("%c",&caracter);
    //__fpurge(stdin);
    fflush(stdin);
    caracter = tolower(caracter);
    while(caracter!= respuesta1 && caracter != respuesta2)
    {
        printf ("%s\n",mensajeError);
        scanf("%c",&caracter);
        //__fpurge(stdin);
        fflush(stdin);
    }
    return caracter;
}

/** \brief LA FUNCION DETERMINA SI EL NUMERO ES PAR O IMPAR
 *
 * \param LABEL MENSAJE PARA PEDIR EL DATO
 * \param MENSAJEERROR MENSAJE DE ERROR
 * \return DEVUELVE 0 SI ES IMPAR
 *         DEVUELVE 1 SI ES PAR
 */
int esPar(char label[],char mensajeError[])
{
    int resultado = 0;
    int numero;
    printf("%s",label);
    scanf("%d",&numero);
    if(numero%2 == 0)
    {
        resultado = 1;
    }
    return resultado;
}
/** \brief
 *
 * \param CHAR MENSAJE DE ERROR
 * \param INT NUMPARAFACTOREAR NUMERO PARA FACTOREAR
 * \return DEVUELVE EL NUMERO FACTORIADO O -1 SI EL NUMERO NO SE PUEDE FACTOREAR
 *
 */

int getFactorial(char mensajeError[],int numParaFactorear){
    long resultado = 1;
    int i;
    if(numParaFactorear < 0)
    {

        printf("%s",mensajeError);
        resultado = -1;
    }
    else if (numParaFactorear == 0){
        resultado = 1;
    }else{
        for(i = 1; i <= numParaFactorear; i++)
        {
            resultado *= i;
        }
    }
    return resultado;
}



/** \brief Inicializa un vector en un valor fuera del rango del vector
 *
 * \param int numeros[] vector de numeros
 * \param int tam tamaño del vector
 * \param int valorInicial valor con el que se va a inicializar el vector
 * \return void no devuelve nada
 *
 */
void InicializarArrayDeNumeros(int numeros[], int tam,int valorInicial)
{
    int i;
    for(i=0; i<tam; i++)
    {
        numeros[i] = valorInicial;
    }
}
/** \brief Carga numeros en forma secuencial
 *
 * \param numeros[] vector de numeros enteros
 * \param tam tamaño del vector
 * \return void
 *
 */

void CargarArrayDeNumerosSecuencial(int numeros[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
}
/** \brief muestra el vector de numeros
 *
 * \param tam tamaño del vector
 * \param orden en que se muestra el vector 1 del primero al ultimo -1 del ultimo al primero
 * \return void
 *
 */

void MostrarArrayDeNumeros(int numeros[], int tam, int orden)
{

    int i;

    switch(orden)
    {
        case 1:
          //muestra todos los numeros (del primero al ultimo)
          printf("En orden de ingreso: \n");
            for(i=0; i<tam; i++)
            {
                printf("%d\n", numeros[i]);
            }
        break;
        case -1:
            //muestra todos los numeros ( del ultimo al primero)
            printf("A la inversa: \n");
            for(i=tam-1; i>-1; i--)
            {
                printf("%d\n", numeros[i]);
            }
        break;
    }
}
/** \brief Recorre el vector y obtiene cual es la nota maxima
 *
 * \param arrayPorParametro vector del que voy a sacar el valor maximo
 * \param tam tamaño del vector
 * \return valorDeRetorno devuelve la nota maxima encontrada
 *
 */
 int SacarNotaMaxima(int arrayPorParametro[],int tam)
 {
     int valorDeRetorno=arrayPorParametro[0];
     int i;
     for(i=1;i<tam;i++)
     {
         if(valorDeRetorno<arrayPorParametro[i])
         {
             valorDeRetorno=arrayPorParametro[i];
         }
     }
     return valorDeRetorno;
 }
/** \brief Recorre el vector y la suma de todos los valores del vector
 *
 * \param arrayPorParametro vector del que voy a sumar los valores enteros
 * \param tam tamaño del vector
 * \return int suma devuelve la suma de todo el vector
 *
 */
 int SacarSumaAcumulada( int arrayPorParametro[],int tam){
    int suma=0;
    int i;
    for(i=0;i<tam;i++){
        if(arrayPorParametro[i]!=-1){
            suma=suma+arrayPorParametro[i];
        }

    }
    return suma;
}
/** \brief Cuenta la cantidad de notas que estan cargadas en el arreglo
 *
 * \param int arrayPorParametro[] arreglo de enteros
 * \param int tam tamaño del arreglo
 * \param int valorInicial valor con el que esta inicializado el arreglo
 * \return int contador cantidad de notas cargadas
 *
 */

int SacarCantidadDeNotas(int arrayPorParametro[],int tam,int valorInicial)
{
    int i;
    int contador=0;
    for(i=0;i<tam;i++)
    {
        if(arrayPorParametro[i] != valorInicial)
        {
            contador++;
        }
    }
    return contador;
}

/** \brief Recorre todo el arreglo y cuenta cuantos son mayores al filtro
 *
 * \param int tam tamaño del arreglo
 * \param int filtro valor por el cual voy a filtrar los aprobados
 * \return int contador cantidad que pasaron el filtro
 *
 */
int SacarCantidadDeAprobados (int arrayPorParametro[],int tam,int filtro){
    int contador=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(arrayPorParametro[i]>filtro)
        {
            contador++;
        }
    }
    return contador;
}
/** \brief Calcula el promedio dentro de un arreglo
 *
 * \param int arrayPorParametro[] arreglo
 * \param tam tamaño del arreglo
 * \return float valorDeRetorno devuelve el valor del promedio
 *
 */

float SacarPromedio(int arrayPorParametro[],int tam,int valorInicial)
{
    /*
    float valorDeRetorno;

    int cantidadDeAlumnos=SacarCantidadDeNotas(arrayPorParametro,tam);
    int sumaDeNotas=SacarSumaAcumulada(arrayPorParametro,tam);

    valorDeRetorno=(float)sumaDeNotas/cantidadDeAlumnos;
    return valorDeRetorno;
    */

    return (float)SacarSumaAcumulada(arrayPorParametro,tam)/SacarCantidadDeNotas(arrayPorParametro,tam,valorInicial);
}


