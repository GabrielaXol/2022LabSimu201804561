/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p2.c -o p2p2.c
Fecha: Sat May 14 15:42:34 CST 2022
Librerias: stdio, etc.
Resumen: Este programa pide 5 números y los ordena de forma ascendente
Entradas: números
Salidas: vectores
*/
// Libreria usada
#include <stdio.h>
// Se definen las variables
int v[5];
// Prototipar funciones
void fillVector();
void sort();
void printVector();

// Inicio del Main
int main(int argc, char const *argv[]) {
  // ingresa los elementos del vector
  fillVector(); 
  printVector();
  // ordena los elementos
  sort(); 
  // imprime el resultado
  printVector(); 
  return 0;
}

// ingresa elementos al vector
void fillVector(){
  int n = 0;
  for (int i = 0; i < 5; i++) {
    printf("Ingrese un número (debe ser entero).\n");
    scanf("%d", &n);
    v[i] = n;
    }
  }

// Ordena los elementos del vector
void sort(){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4-i; j++) {
      if (v[j] > v[j+1]) {
        int aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}

// Imprimir el resultado
void printVector(){
  puts("El vector ordenado es:");
  for (int i = 0; i < 5; i++) {
    printf("%d ", v[i]);
  }
  puts("");
}