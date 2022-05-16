/*
Autor: Gabriela_Xol
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc final.cpp -o final
Fecha: Mon May 16 08:15:24 CST 2022
Librerias: stdio, etc.
Resumen: Simula el despeje de cohetes
Entradas: Vectores con decimales
Salidas: Decimales
*/
#include <iostream>
#include <string>
#include <math.h>
// comenzamos definiendo variables


//Definimos las clases
/*class Cohetes
{
public:
    float  t0[], y0[], v0[]; 
public:
    Cohetes();
    ~Cohetes();
    //despegue que será distinto para c/u
    //virtual void Despegue(); 
};*/
//clase cohete1
class Cohete1 
{
public://caracteristicas
    float t0[11];
    float y0[11];
    float v0[11];
    float E0, TSFC, CD, A, m0, mf0;
public:
    Cohete1();
    ~Cohete1();
    //void Despegue();
};

//clase cohete2
class Cohete2
{
public://caracterisitcas
    float t0[11];
    float y0[11];
    float v0[11];
    float E0, TSFC, CD, A, m0, mf0;
public:
    Cohete2();
    ~Cohete2();
    //void Despegue();
};

//clase cohete3
class Cohete3
{
public://caracteristicas
    float t0[11];
    float y0[11];
    float v0[11];
    float E0, TSFC, CD, A, m0, mf0;
public:
    Cohete3();
    ~Cohete3();
    //void Despegue();
};
//inician los metodos
//constructores de las clases
//constructor y destructor clase cohete1
Cohete1::Cohete1()
{}

Cohete1::~Cohete1()
{}

//constructor y destructor clase cohete2
Cohete2::Cohete2()
{}

Cohete2::~Cohete2()
{}

//constructor y destructor clase cohete3
Cohete3::Cohete3()
{}

Cohete3::~Cohete3()
{}
//declaramos las funcion despegue
float Despegue();



int main()
{
    return 0;
}

//Deficinicion de la funcion
float Despegue()
{
    //inicializar los cohetes
    Cohete1 c1;
    
  


}