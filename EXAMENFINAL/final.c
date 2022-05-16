/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc final.cpp -o final
Fecha: Mon May 16 11:28:24 CST 2022
Librerias: stdio, etc.
Resumen: Simula el despeje del cohete Ah Mun
Entradas: Vectores con decimales
Salidas: Decimales
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 30*60*10+1 // tamaño de los vectores para 30 minutos
float despegue_cohete(float);
main()
{
float mf0=1.5*pow(10,6); // masa inicial del combustible (kg)
float altura_max;
altura_max= despegue_cohete(mf0);
}

float despegue_cohete(float mf0)

{  
// Variables auxiliares
FILE *pf;
int k, kfinal, impacto, comb_agotado;
float tiempo_agot_comb, tiempo_impacto, masa, altura_max, Ek, g, Fa;

// constantes fisicas generales
 float G = (6.693)*pow(10,-11);
 float Rt = (6.378) * pow(10,6);
 float Mt = (5.9736)* pow(10,24);
 float R = 287.06;
 float L = 6.5 * pow(10,-3);
 float g0 = 9.81;
 float T0 = 288.15;
 float P0 = 101325;
 float delta = 0.1;
// Constantes para este cohete en específico
float mc= 1.1*pow(10,5);
float TSFC=3.248*pow(10,-4);
float CD=61.27;
float A=201.06;
// parámetros del despegue
float E0=3*pow(10,7);
// parametros de integracion
float delta= 0.1; 
float Tfinal=30*60 
kfinal=(int)(Tfinal/delta)
// condiciones iniciales (cohete en la altura inicial)
float y0=61 // posición inicial (mis dos últimos digitos del carnet)
float v0=0

// Vectores del problema
float t[TAM]; // tiempo
float y[TAM]; // altura del cohete
float v[TAM]; // velocidad del cohete
float mf[TAM]; // combustible restante
float rho[TAM]; // densidad del combustible restante
// se guardan los datos obtenidos en un fichero
if((pf=fopen ("altura_del_cohete.txt", "wt"))==NULL)
{
 printf("ERROR abriendo el fichero\n");
 exit(0);
}
// Se inicializan las variables
t[0]=0;
y[0]=y0v;
v[0]=v0;
mf[0]=mf0;
altura_max=0;
//iteraciones de integración
k=0;
impacto=0;
comb_agotado==;
Ek=E0;
while (impacto==0 && k<kfinal)
{
   fprintf (pf, "%.2f\t%.2f\n",t[k],y[k]);
   t[k+1]=t[k]+delta;
   masa=mc+mf[k]
   //Calculo de la densidad de la atmosfera (rho)
   if(y[k]>T0/L)
   rho[k]=0;
   else
   rho[k]=(P0/(R*T0))*pow((1-L*y[k]/T0), (g0/(R*L)));
   // El rozamiento con la atmósfera (Fa)
   Fa=0.5*rho[k]*CDÁv[k]*fabs(v[k]);
   // Aceleración de la gravedad en funcion de la altura
   g=G*Mt/((Rt+y[k])*(Rt+y[k]));
   // printf("g=%5.2f\n",g);
   // Se detecta el combustible agotado:
   if(mf[k]<=0)
   {
    Ek=0;
    mf[k]=0
    if(comb_agotado==0)
    {
     tiempo_agot_comb=t[k];
     comb_agotado=1;   
    }   
   }
   //print("y=%5.2f, mf=%5.2\n",y[k],mf[k]);
   //  EDOs
   //Para el cambio de posicion del cohete
   y[k+1]y[k]+delta*v[k];
   //aceleracion
   v[k+1]=v[k]+delta*(Ek/masa-g-Fa/masa);
   // Cambio en el combustible
   mf[k+1]=mf[k]+delta*(-TSFC*Ek);
   if(y[k+1]>altura_max)
    altura_max=y[k+1];
    // Para detectar el impacto en el suelo
    // Si se impacta con el suelo, se detiene
    if(v[k]<0 && y[k]<0)
    {
     impacto=1;
     tiempo_impacto=t[k];   
    }
    // incrementa las iteraciones
    k++;
}
// Muestra lo solicitado cuando ya no hay combustible
if(comb_agotado)
 printf("El combustible se agotó en t=%d min %5.2f s\n",(int)(tiempo_agot_comb/60), tiempo_agot_comb-60*((int)(tiempo_agot_comb/60)));
// Si se produjo un impacto
if(impacto)
 printf("El impacto se llevó a cabo en  t=%d min %5.2f s\n",(int)(tiempo_impacto/60), tiempo_impacto-60*((int)(tiempo_impacto/60)));
 printf("La altura máxima que alcanza el cohete es: %5.2f m\n", altura_max);
 fclose(pf);
return altura_max;
}