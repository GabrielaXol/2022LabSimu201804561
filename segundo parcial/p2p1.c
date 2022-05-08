/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p1.c -o p2p1.c
Fecha: mar may 22:05:40 CST 2022
Librerias: stdio, etc.
Resumen: El siguiente programa realiza una grafica para la recta de regresión lineal de datos que comparan el valor del euro frente al dolar a través de los años.
Entradas: Vectores con decimales
Salidas: Decimales
*/
//Enumerar los pasos del pseudocodigo
//librerias
#include <stdio.h>
#include <math.h>

//declara e inicializa las variables globales
float x[]={2006,2007,2008,2009,2010,2011,2012,2013,2014,2015,2016,2017,2018,2019}, y[]={1.003,0.981,0.968,0.923,0.880,0.856,0.847,0.826,0.804,0.783,0.792, 0.750,0.726,0.738};
//medimos el tamanio del vector
int n = sizeof(x)/sizeof(x[0]);

//prototipar funciones
void imprimir(float datos[]);
float suma(float datos[]);
float sumaMulti(float datos1[], float datos2[]);


void main(){
    //Se declaran las variables del problema
    float b, m, d; 
    //imprimo los valores de los vectores para que el usuario conozca el set de datos
    imprimir(x);
    imprimir(y);
    //los valores de ecuacion lineal, por medio de minimos cuadrados
    m = (n*sumaMulti(x,y)-(suma(x)*suma(y)))/(n*sumaMulti(x,x)-(suma(x)*suma(x)));
    b = (suma(y)-m*suma(x))/n;
    // Para calcular el año en el que el dolar no valdrá nada tenemos que: mx+b=0, por lo que x=d
    d= -b/m;  
    //imprime la ecuacion lineal
    printf("y = %fx + %f\n",m,b);
    // imprime el año en el que el dolar no valdrá nada
    printf("año en el que el dolar no valdrá nada: x=%f",d);
}

//imprimir los datos del vector que ingrese a la funcion
void imprimir(float datos[]){
    puts("Valor de los datos");
    for (int i = 0; i < n; i++)
    {
        printf("%f ",datos[i]);
    }
    puts("\n");
}

//reliza la suma de los elementos de un vector ingresado
float suma(float datos[]){
    float resp = 0;
    for (int i = 0; i <= n; i++)
    {
        resp += datos[i];
    }
    return resp;
}

//realiza la suma del producto de los elementos de dos vectores ingresados
float sumaMulti(float datos1[], float datos2[]){
    float resp = 0;
    for (int i = 0; i <= n; i++)
    {
        resp += datos1[i]*datos2[i];
    }
    return resp;
}