/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p2.c -o p2p2.c
Fecha: Sat May 14 22:06:19 CST 2022
Librerias: stdio, etc.
Resumen: Este programa caclcula el factorial de un numero entero positivo
Entradas: números
Salidas: números
*/
// Librerías.
#include <stdio.h>
// prototipa funciones
int factorial(int n);

// Función principal para calcular el factorial:
int main(int argc, char const *argv[]) {
  //Ingresa el 1 por defecto  
  int a = 1; 
  puts("Ingrese un número (que sea entero y positivo):");
  scanf("%d", &a); 
  // Devuelve el factorial
  printf("%d! = %d\n", a, factorial(a)); 
  return 0;
}

// La función recursiva:
int factorial(int n){
  if (n >= 1) {
    // si cumple las condiciones (mayor igual a 1), se multiplica por el anterior número  
    return n*factorial(n-1); 
  } else if (n == 0) {
    // Se establece el 1 como límite inferior, para asegurar que sea positivo y diferente de cero.  
    return 1; 
  } else {
     // Si no es válido el proceso devuelve cero 
    return 0; 
  }
}