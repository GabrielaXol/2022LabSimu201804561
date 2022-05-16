/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p2.c -o p2p2.c
Fecha: Sun May 15 17:52:29 CST 2022
Librerias: stdio, etc.
Resumen: Este programa caclcula el factorial de un numero entero positivo
Entradas: números
Salidas: números
*/
// gcc -o problema6.out problema6.c -lm
// Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Prototipa funciones
float a(int m);
float b(int m);
float c(int m);
float d(int m);


int main(int argc, char const *argv[]) {
  // Define la variable n
  int n; 
  // Pide ingresar un número entero y mayor a 2
  puts("Ingrese un número (entero y mayor a 2)");
  // Se guarda el número en la variable
  scanf("%d", &n); 
  puts("Los resultados, en orden de incisos son:");
  printf("Sum [k²(k-3)] = %f\n", a(n)); 
  printf("Sum [3/(k-1)] = %f\n", b(n)); 
  printf("Sum [((1+√(5))/2)^k/√(5) - ((1-√(5))/2)^k/√(5) ]= %f\n", c(n));
  printf("Sum [0.1(3*2^(k-2)+4)] = %f\n", d(n));
  return 0;
}
// Para el inciso a
float a(int m){
  float sum = 0; 
  for (float k = 1; k <= m; k++) {
    sum += pow(k,2)*(k-3); 
  }
  return sum;
}
// Para el inciso b
float b(int m){
  float sum = 0; 
  for (float k = 2; k <= m; k++) {
    sum += 3/(k-1); 
  }
  return sum;
}
// Para el inciso c
float c(int m){
  float sum = 0; 
  for (float k = 1; k <= m; k++) {
    sum += pow((1+sqrt(5))/2,k)/sqrt(5) - pow((1-sqrt(5))/2,k)/sqrt(5); 
  }
  return sum;
}
// Para el inciso d
float d(int m){
  float sum = 0; 
  for (float k = 1; k <= m; k++) {
    sum += 0.1*(3*pow(2,(k-2)) + 4); 
  }
  return sum;
}