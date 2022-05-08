/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p2.c -o p2p2.c
Fecha: Tue May 08 02:55:34 CST 2022
Librerias: stdio, etc.
Resumen: Este programa calcula la raíz de una ecuación usando método Newton-Raphson (ejemplo básico)
Entradas: función
Salidas: raíces
*/
//librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototipos de funciones
float f(float x);
float df(float x);
void NewtonRaphson(float x0, float tol, int maxiter, int *actiter, float *sol);

void main (void)
{
    //definir variables
    float x_inicial, tolerancia, xS;
    int iteraciones, Aiteracion;
    
    //obtener datos
    printf("Ingrese el valor aproximado de x: ");
    scanf("%f",&x_inicial);
    printf("Ingrese el valor de tolerancia: ");
    scanf("%f",&tolerancia);
    printf("Ingrese el valor maximo de iteraciones: ");
    scanf("%d",&iteraciones);
    NewtonRaphson(x_inicial, tolerancia, iteraciones, &Aiteracion, &xS);
    if (Aiteracion == iteraciones)
        printf("\nNo hay solucion despues de %d iteraciones\n",iteraciones);
    else
    {
        printf("\nLuego de %d iteraciones la solucion es %.4f\n",Aiteracion,xS);
    }
}

void NewtonRaphson(float x0, float tol, int maxiter, int *actiter, float *sol)
{
    float xant, x, dif;
    int i=1;
    xant=x0;
    x=xant-f(xant)/df(xant);
    dif = x-xant;
    (dif<0)?dif=-dif:dif;
    printf("%f\n",dif);
    while (dif>tol && i<maxiter)
    {        
        xant=x;
        x=xant-f(xant)/df(xant);
        i++;
        dif = x-xant;
        (dif<0)?dif=-dif:dif; 
        printf("%f\n",dif);
    }
    *sol=x;
    *actiter = i;
}

float f(float x)
{
    float res =0;
    res = 0.1*x*x+x*log(x);
    return res;
}

float df(float x)
{
    float res =0;
    res=log(x)+x/5+1;
    return res;
}