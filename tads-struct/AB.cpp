/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "TADS.h"
#include "AB.h"

using namespace std;

void construir(AB &parbol)
{
    Elemento e;
    e.valor1 = 0; e.valor2 = 0;
    parbol = crearNodoAB(e);
}

NodoAB* crearNodoAB(Elemento e)
{
    NodoAB *p;
    p = new NodoAB;
    p->e = e;
    p->hder = NULL;
    p->hizq = NULL;
    return p;
}

AB h_der(AB parbol)
{
    if(parbol == NULL) return parbol;
    else return parbol->hder;
}

AB h_izq(AB parbol)
{
    if(parbol == NULL) return parbol;
    else return parbol->hizq;
}

void insertarAB(AB &parbol, Elemento e)
{
    if(parbol == NULL) return;
    insertarAB(parbol->hizq, e);
    if(parbol->hizq == NULL)
    {
        e.valor2 = 0;
        parbol->hizq = crearNodoAB(e);
    }

    insertarAB(parbol->hder, e);
    if(parbol->hder == NULL)
    {
        e.valor2 = 1;
        parbol->hder = crearNodoAB(e);
    }
}

void hallarCombs(AB parbol, Pila &aux)
{
    if(parbol == NULL) return;
    
    apilar(aux, parbol->e);
    
    if(parbol->hder == NULL and parbol->hizq == NULL) mostrar(aux); //La pila debe mostrar el valor 2 para ver las combinaciones
    else
    {
        hallarCombs(parbol->hizq, aux);
        desapilar(aux);
        hallarCombs(parbol->hder, aux);
        desapilar(aux);
    }
}

AB buscarNodo(AB parbol, int valor)
{
    if(parbol == NULL or parbol->e.valor1 == valor) return parbol;
    if(valor < parbol->e.valor1) buscarNodo(parbol->hizq, valor);
    else buscarNodo(parbol->hder, valor);
}

void mostrarEnAmplitudAB(AB parbol)
{
    AB paux; Cola cola; Elemento aux;
    
    if(parbol == NULL) return;
    paux = parbol;
    construir(cola);
    encolar(cola, paux->e);
    while(cola.longitud != 0)
    {
        aux = desencolar(cola);
        cout << aux.valor1 << " ";
        paux = buscarNodo(parbol, aux.valor1);
        if(paux->hizq != NULL)   
        {
            aux = paux->hizq->e;
            encolar(cola, aux);
        }
        if(paux->hder != NULL)   
        {
            aux = paux->hder->e;
            encolar(cola, aux);
        }
    }
}

int mostrarEnAmplitudReconoceNivel(AB parbol)
{
    AB paux; Cola cola; Elemento aux, cambNivel;
    int niveles=0, flag=1;
    
    if(parbol == NULL) return 0;
    paux = parbol;
    construir(cola);
    encolar(cola, paux->e);
    cambNivel = paux->e;
    while(cola.longitud != 0)
    {
        aux = desencolar(cola);
        if(aux.valor1 == cambNivel.valor1 and flag)
        {
            cout << endl;
            niveles++;
            flag = 0;
        }
        cout << aux.valor1 << " ";
        paux = buscarNodo(parbol, aux.valor1);
        if(paux->hizq != NULL)   
        {
            if(paux->e.valor1 == cambNivel.valor1) 
            {
                cambNivel = paux->hizq->e;
                flag = 1;
            }
            aux = paux->hizq->e;
            encolar(cola, aux);
        }
        if(paux->hder != NULL)   
        {
            if(paux->e.valor1 == cambNivel.valor1 and paux->hizq == NULL)
            {
                cambNivel = paux->hder->e;
                flag = 1;
            }
            aux = paux->hder->e;
            encolar(cola, aux);
        }
    }
    return niveles;
}

int hallarCombsCumplen(AB parbol, int sum, int obj)
{
    if(parbol == NULL) return 0;
    int cont=0;
    sum += parbol->e.valor1 * parbol->e.valor2;
    if(parbol->hder == NULL and parbol->hizq == NULL)
    {
        if(sum == obj) return 1;
        else return 0;
    }
    else
    {
        cont += hallarCombsCumplen(parbol->hizq, sum, obj);
        cont += hallarCombsCumplen(parbol->hder, sum, obj);
    }
    return cont;
}