/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "TADS.h"
#include "ColasNPrioridades.h"

void construir(ColaNP &cola)
{
    cola.longitud = 0;
    cola.cantPrioridades = 0;
    cola.prioridades = NULL;
}

ColaPrioridad* crearPrioridad(int priori, ColaPrioridad *s)
{
    ColaPrioridad *p;
    p = new ColaPrioridad;
    p->primero = NULL;
    p->prioridad = priori;
    p->sig = s;
    p->ultimo = NULL;
    return p;
}

NodoCNP* crearNodoCNP(Elemento e, int priori)
{
    NodoCNP *p;
    p = new NodoCNP;
    p->elem = e;
    p->prioridad = priori;
    p->sig = NULL;
    return p;
}

void encolar(ColaNP &cola, int priori, Elemento elem)
{
    NodoCNP* p;
    ColaPrioridad *prioridad, *nP, *pA;
    bool flag=0;
    p = crearNodoCNP(elem, priori);
    prioridad = cola.prioridades;
    pA = NULL;
    
    for(int i=1; i <= cola.cantPrioridades; i++)
    {
        if(priori <= prioridad->prioridad and i == 1)
        {
            flag = 1;
            break;
        }
        pA = prioridad;
        if(prioridad->sig != NULL)
            if(prioridad->prioridad <= priori and priori <= prioridad->sig->prioridad) break;
        prioridad = prioridad->sig;
    }
    
    if(prioridad == NULL)
    {
        nP = crearPrioridad(priori, NULL);
        if(cola.cantPrioridades == 0) cola.prioridades = nP;
        else pA->sig = nP;
        cola.cantPrioridades++; 
    }
    else if(prioridad->prioridad != priori)
    {
        if(!flag)
        {
            nP = crearPrioridad(priori, prioridad->sig);
            prioridad->sig = nP;
        }
        else
        {
            nP = crearPrioridad(priori, prioridad);
            cola.prioridades = nP;
        }
        cola.cantPrioridades++; 
    }
    else nP = prioridad;
    
    if(nP->primero == NULL)
    {
        nP->primero = p;
        nP->ultimo = p;
    }
    else
    {
        nP->ultimo->sig = p;
        nP->ultimo = p;
    }
    
    if(nP->sig != NULL) p->sig = nP->sig->primero;
    if(pA != NULL) pA->ultimo->sig = nP->primero;
    
    cola.longitud++;
}