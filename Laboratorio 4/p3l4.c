
/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p2.c -o p2p2.c
Fecha: Sat May 14 18:27:46 CST 2022
Librerias: stdio, etc.
Resumen: Este programa pide las componentes de dos vectores y realiza operaciones con los dos vectores formados
Entradas: números
Salidas: vectores
*/
// Librerias
#include <stdio.h>
#include <math.h>
// Define las variables globales.
float a[3];
float b[3];
// Prototipa funciones.
// norma del vector
float norm(float v[3]); 
// suma de vectores
void sum();
// realiza el producto punto
float dot(float v[3], float u[3]); 
// realiza el producto cruz
void cross(float v[3], float u[3]); 
// ingresa los elementos de los vectores
void fillVectors();

int main(int argc, char const *argv[]) {

  // ingresa los elementos a los vectores
  fillVectors(); 
  puts("");
  puts("Resultados:");
  // En las siguientes funciones se muestran en orden: las normas, suma de los vectores, producto punto, producto cruz y el otro producto cruz.
  printf("||a|| = %.2f,\n||b|| = %.2f,\n", norm(a), norm(b)); 
  printf("a + b = "); sum(); puts(",");
  printf("a • b = %.2f,\n", dot(a,b)); 
  printf("a × b = "); cross(a,b); puts(",");
  printf("b × a = "); cross(b,a); puts(".");
  return 0;
}

// Calcula la norma del vector.
float norm(float v[3]){
  float norma = 0;
  norma = sqrt(dot(v,v)); 
  return norma;
}

// Realiza la suma de dos vectores.
void sum(){
  static float v[3];
  printf("( ");
  for (int i = 0; i < 3; i++) {
    v[i] = a[i] + b[i]; 
    printf("%.2f ", v[i]);
  }
  printf(")");
}

// Realiza el producto punto
float dot(float v[3], float u[3]){
  float sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += v[i]*u[i]; 
  }
  return sum;
}

// Realiza el producto cruz.
void cross(float v[3], float u[3]){
  static float w[3];
  w[0] = v[1]*u[2] - v[2]*u[1];
  w[1] = v[2]*u[0] - v[0]*u[2];
  w[2] = v[0]*u[1] - v[1]*u[0];

  // Imprime el vector
  printf("( ");
  for (int i = 0; i < 3; i++) {
    printf("%.2f ", w[i]);
  }
  printf(")");
}

// ingresa los elementos del vector
void fillVectors() {
  puts("Ingrese las componentes del vector a.");
  for (int i = 0; i < 3; i++) {
    printf("Ingrese la componente %d.\n", i+1);
    scanf("%f", &a[i]);
  }
  puts("Ingrese las componentes del vector b");
  for (int i = 0; i < 3; i++) {
    printf("Ingrese la componente %d\n", i+1);
    scanf("%f", &b[i]);
  }
}