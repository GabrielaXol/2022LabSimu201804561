#! /bin/bash

: << 'Header'
Autor:              Gabriela Xol
Carnet:             201804561
Tipo de archivo:    Script de bash
Ejecución:          ./ejercicio2.sh
Resumen:            Este script funciona como plantilla para crear un archivo en C.
Header

echo Ingrese nombre para el archivo       # Se solicita el nombre de un archivo.
read nombre                                         # El resultado se asigna a la variable "nombre". Que crea en la misma línea.
                                                    
if [ -n "$nombre" ]; then                           # Detecta si hay valores asignados a la variable para ejecutar los comandos que siguen.
                                                    
    echo "/*" > $nombre.c                           # Inserta el inicio del comentario.
    echo -e "Autor: \t\t\t$USER" >> $nombre.c       # Inserta el nombre del usuario.
        gcc --version > tvC            # Se un archivo temporal donde se va a guardar la información ingresada.
                                                    # obtenida del comando gcc --version.
        version=$(head tvC --lines=1)  # esta variable lee la primer línea del archivo temporal.
    echo -e "Compilador: \t$version" >> $nombre.c   # Inserta el valor de la variable recién creada.
        rm tvC                         # Elimina el archivo tvC.
    echo -e "Compilado: \t\tgcc $nombre.c -o $nombre" >> $nombre.c      #Indica cómo se debe compilar el programa.
        date +%D > tfecha                    # se crea archivo temporal con la información del comando fecha.
        fecha=$(cat tfecha)                  #se crea otra variable que lee el nuevo archivo temporal.
    echo -e "Fecha: \t\t\t$fecha" >> $nombre.c      # Inserta el valor de la variable en el archivo
        rm tfecha                            # Elimina el archivo tfecha.
    echo -e "Librerias:      stdio" >> $nombre.c    # librerias que seran usadas.
    echo "Ingrese resumen"          # el usuario ingresa su resumen para el programa
        read resumen                                # se lee y se le asigna una variable al resumen
    echo "Ingrese entradas"        # solicita entradas del programa.
        read entrada                                # se leen y se le asignan a una variable.
    echo "Ingrese salidas"         # solicita salidas del programa.
        read salida                                 # Se leen y se le asignan a una variable.
    echo -e "Resumen: \t\t$resumen" >> $nombre.c    # Todas las variables anteriores se ingresan en el archivo nombre.c
    echo -e "Entrada: \t\t$entrada" >> $nombre.c
    echo -e "Salida: \t\t$salida" >> $nombre.c
    echo -e "*/ \n\n//Librerias \n#include <stdio.h> \n//Numerar los pasos del pseudocódigo." >> $nombre.c
                                                    # Se guardan todas las variables anteriores en el archivo nombre.c
    chmod +x $nombre.c                              # Se concenden permisos de ejecución
elif [ -z "$nombre" ]; then                         
    exit                                           #Si la variable nombre está vacía, finaliza el programa 
fi