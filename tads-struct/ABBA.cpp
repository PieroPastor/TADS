/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "TADS.h"
#include "ABBA.h"

void construir(ABBA &parbol)
{
    parbol = NULL;
}

NodoABBA *crearNodoABBA(Elemento e, NodoABBA *ant, NodoABBA *fuera)
{
    NodoABBA *p;
    p = new NodoABBA;
    p->e = e;
    p->hder = NULL;
    p->hizq = NULL;
    p->back = ant;
    p->dent = NULL;
    p->fuer = fuera;
    return p;
}

//Inicialmente (parbol, NULL, NULL, arrElem[n], 0, n);
void insertarRecursivo(ABBA &parbol, ABBA ant, ABBA fuera, Elemento *arrElem, int i, int n)
{
    if(i == n) return;
    if(parbol == NULL)
    {
        parbol = crearNodoABBA(arrElem[i], ant, fuera);
        insertarRecursivo(parbol->dent, NULL, parbol, arrElem, i+1, n);
    }
    else if(arrElem[i].valor1 < parbol->e.valor1) insertarRecursivo(parbol->hizq, parbol, parbol->fuer, arrElem, i, n);
    else if(arrElem[i].valor1 > parbol->e.valor1) insertarRecursivo(parbol->hder, parbol, parbol->fuer, arrElem, i, n);
    else insertarRecursivo(parbol->dent, NULL, parbol, arrElem, i+1, n);
}

NodoABBA* buscarRecursivo(ABBA parbol, Elemento *arrElem, int i, int n)
{
    if(i == n or parbol == NULL) return NULL; //Significa que no encontró el valor
    if(i == n-1 and parbol->e.valor1 == arrElem[i].valor1)
    {
        if(parbol->dent == NULL) return parbol;
        else return parbol->dent;
    }
    else if(arrElem[i].valor1 < parbol->e.valor1) return buscarRecursivo(parbol->hizq, arrElem, i, n);
    else if(arrElem[i].valor1 > parbol->e.valor1) return buscarRecursivo(parbol->hder, arrElem, i, n);
    else return buscarRecursivo(parbol->dent, arrElem, i+1, n);
}