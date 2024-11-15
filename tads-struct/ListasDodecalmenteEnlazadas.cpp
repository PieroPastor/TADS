/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "TADS.h"
#include "ListasDodecalmenteEnlazadas.h"

void construir(ListaDC &l)
{
    l.cabeza = NULL; l.finH = NULL; l.finZ = NULL; l.finV = NULL;
    l.longitudH = 0; l.longitudV = 0; l.longitudZ = 0; l.cantNodos = 0;
}

NodoDC* crearNodoDC(Elemento e, NodoDC *u, NodoDC *d, NodoDC *l, NodoDC *r, NodoDC *den, NodoDC *fue)
{
    NodoDC *p;
    p = new NodoDC;
    p->aba = d;
    p->arr = u;
    p->dentro = den;
    p->der = r;
    p->elem = e;
    p->fuera = fue;
    p->izq = l;
    return p;
}

void crearInicio(ListaDC &malla)
{
    NodoDC *p; Elemento e; 
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    p = crearNodoDC(e, NULL, NULL, NULL, NULL, NULL, NULL);
    malla.cabeza = p;
    malla.finH = p;
    malla.finV = p;
    malla.finZ = p;
    malla.longitudV++;
    malla.longitudH++;
    malla.longitudZ++;
}

void creaVer(NodoDC *pU, int longiV, int longiZ, int i, int j, NodoDC *u, NodoDC *fue)
{
    if(i > longiV or j > longiZ or pU == NULL) return;
    NodoDC *p; Elemento e;
    
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    
    p = crearNodoDC(e, u, NULL, pU, NULL, NULL, fue);
    pU->der = p;
    if(u != NULL) u->aba = p;
    if(fue != NULL) 
    {
        fue->dentro = p;
        fue = fue->aba;
    }
    
    creaVer(pU->aba, longiV, longiZ, i+1, j, p, fue);
    if(i == 1)creaVer(pU->dentro, longiV, longiZ, i, j+1, u, p);
}

void crearColumna(ListaDC &malla, int n)
{
    NodoDC *pU;
    
    for(int i=1; i <= n; i++)
    {
        if(malla.cantNodos == 0) crearInicio(malla);
        else
        {
            pU = malla.finH;
            creaVer(pU, malla.longitudV, malla.longitudZ, 1, 1, NULL, NULL);
            malla.finH = pU->der;
            malla.longitudH++;
        }
        malla.cantNodos = malla.longitudH * malla.longitudV * malla.longitudZ;
    }
}

void creaHor(NodoDC *pU, int longiH, int longiZ, int i, int j, NodoDC *l, NodoDC *fue)
{
    if(i > longiH or j > longiZ or pU == NULL) return;
    NodoDC *p; Elemento e;
    
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    
    p = crearNodoDC(e, pU, NULL, l, NULL, NULL, fue);
    pU->aba = p;
    if(l != NULL) l->der = p;
    if(fue != NULL)
    {
        fue->dentro = p;
        fue = fue->der;
    }
    creaHor(pU->der, longiH, longiZ, i+1, j, p, fue);
    if(i == 1) creaHor(pU->dentro, longiH, longiZ, i, j+1, l, p);
}

void crearFila(ListaDC &malla, int n)
{
    NodoDC *pU;
    
    for(int i=1; i <= n; i++)
    {
        if(malla.cantNodos == 0) crearInicio(malla);
        else
        {
            pU = malla.finV;
            creaHor(pU, malla.longitudH, malla.longitudZ, 1, 1, NULL, NULL);
            malla.finV = pU->aba;
            malla.longitudV++;
        }
    }
}

void creaDen(NodoDC *pU, int longiH, int longiV, int i, int j, NodoDC *l, NodoDC *u)
{
    if(i > longiV or j > longiH or pU == NULL) return;
    NodoDC *p; Elemento e;
    
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    
    p = crearNodoDC(e, u, NULL, l, NULL, NULL, pU);
    pU->dentro = p;
    if(u != NULL) u->aba = p;
    if(l != NULL)
    {
        l->der = p;
        l = l->aba;
    }
    creaDen(pU->aba, longiH, longiV, i+1, j, l, p);
    if(i == 1) creaDen(pU->der, longiH, longiV, i, j+1, p, u);
}

void crearFondo(ListaDC &malla, int n)
{
    NodoDC *pU;
    
    for(int i=1; i <= n; i++)
    {
        if(malla.cantNodos == 0) crearInicio(malla);
        else
        {
            pU = malla.finZ;
            creaDen(pU, malla.longitudH, malla.longitudV, 1, 1, NULL, NULL);
            malla.finZ = pU->dentro;
            malla.longitudZ++;
        }
        malla.cantNodos = malla.longitudH * malla.longitudV * malla.longitudZ;
    }
}

NodoDC* encontrarNodoDC(ListaDC &malla, int x, int y, int z)
{
    NodoDC *p;
    p = malla.cabeza;
    for(int i=1; i <= x-1; i++) p = p->der; //Se resta 1 porque si mandas a la celda final te bota el NULL
    for(int i=1; i <= y-1; i++) p = p->aba;
    for(int i=1; i <= z-1; i++) p = p->dentro;
    return p;
}

void insertaValor(ListaDC &malla, int valor, int coordX, int coordY, int coordZ)
{
    if(coordX > malla.longitudH or coordY > malla.longitudV or coordZ > malla.longitudZ) return;
    NodoDC *p;
    p = encontrarNodoDC(malla, coordX, coordY, coordZ);
    p->elem.valor1 = valor;
}

void mostrar(ListaDC l)
{
    NodoDC *p, *pD, *pA;
    p = l.cabeza;
    
    for(int k=1; k <= l.longitudZ; k++)
    {
        pA = p;
        for(int j=1; j <= l.longitudV; j++)
        {
            pD = pA;
            for(int i=1; i <= l.longitudH; i++)
            {
                cout << pD->elem.valor1 << " | ";
                pD = pD->der;
            }
            pA = pA->aba;
            cout << endl;
        }
        p = p->dentro;
        cout << "---------------------------------" << endl;
    }
}