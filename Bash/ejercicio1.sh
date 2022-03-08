#! /bin/bash
#Este script corresponde al ejercicio1 del laboratorio3
curl -s wttr.in/Guatemala > ~/ejercicio_docker/clima1.sh #Se crea el archivo clima1 en donde se almacena la información del clima en Guatemala.
head -n 7 ./clima1.sh # Indica el numero de lineas que va a leer del archivo donde se almaceno la informacion.
echo $leer #indica que este archivo es de lectura
rm clima1.sh #Comando que va a eliminar el archivo clima1
