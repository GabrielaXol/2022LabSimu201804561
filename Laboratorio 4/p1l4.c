/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc p2p2.c -o p2p2.c
Fecha: Thu May 12 11:59:34 CST 2022
Librerias: stdio, etc.
Resumen: Este programa ordena números pares del 1 al 20, de forma ascendente o descendente.
Entradas: números
Salidas: vectores
*/
//librerias
#include <stdio.h>
// Se declaran las variables
int v[10];
char c;
// Prototipar funciones
void fillVector();
void printVector(char o);

// Función principal
int main(){
    // Se añaden los elementos del vector
	fillVector();
	// Se pide el orden deseado
	puts("Deseo ver los elementos en orden:\n'a'=ascendente\n'd'=descendente");
	scanf("%s", &c);
	// Notificar error si no se ingresa una opción válida
	while(c != 'd' && c != 'a'){
		puts("(Opcion invalida)");
		puts("Deseo ver los elementos en orden:\n'a'=ascendente\n'd'=descendente");
		scanf("%s", &c);
	}
    // Se imprime el vector resultante dependiendo de la elección del ususario
	printVector(c); 
	return 0;
}

// Añade los elementos del vector:
void fillVector(){
	for (int i = 0; i < 10; i++){
		v[i] = (i + 1)*2;
	}
}

// Imprime los elementos del vector
void printVector(char o){
	// Variables dummies.
	int n = 1, k = 0;
	int a = 1;
	// cambia el orden por el contrario
	if (o == 'd'){
        // invierte el orden
		n = -1; 
        // define inicio/fin
		k = 9; 
	}
	for (int i = k; i != 9-k+n; i += n){
		// imprime el valor resultante
        printf("%d\n", v[i]); 
	}
}
