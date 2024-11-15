/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


#include "TADS.h"
#include "ListasOctalmenteEnlazadas.h"

void construir(ListaO &l)
{
    l.cabezaH = NULL; l.cabezaV = NULL; l.finH = NULL; l.finV = NULL;
    l.longitudH = 0; l.longitudV = 0; l.cantNodos = 0;
}

NodoO* crearNodoO(Elemento e, NodoO *u, NodoO *d, NodoO *l, NodoO *r)
{
    NodoO *p;
    p = new NodoO;
    p->aba = d;
    p->ant = l;
    p->arr = u;
    p->sig = r;
    p->elem = e;
    return p;
}

void crearInicio(ListaO &malla)
{
    NodoO *p; Elemento e; 
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    p = crearNodoO(e, NULL, NULL, NULL, NULL);
    malla.cabezaH = p;
    malla.cabezaV = p;
    malla.finH = p;
    malla.finV = p;
    malla.longitudV++;
    malla.longitudH++;
}

void creaVer(NodoO *pU, int longi, int i, NodoO *u)
{
    if(i > longi or pU == NULL) return;
    NodoO *p; Elemento e;
    
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    
    p = crearNodoO(e, u, NULL, pU, NULL);
    pU->sig = p;
    if(u != NULL) u->aba = p;
    
    creaVer(pU->aba, longi, i+1, p);
}

void creaHor(NodoO *pU, int longi, int i, NodoO *l)
{
    if(i > longi or pU == NULL) return;
    NodoO *p; Elemento e;
    
    e.valor1 = e.valor2 = 0; e.valor3 = new char[TAMFUNCS];
    for(int i=0; i < TAMFUNCS; i++)e.valor3[i] = '\0';
    
    p = crearNodoO(e, pU, NULL, l, NULL);
    pU->aba = p;
    if(l != NULL) l->sig = p;
    
    creaHor(pU->sig, longi, i+1, p);
}

void crearColumna(ListaO &malla, int n)
{
    NodoO *pU;
    
    for(int i=1; i <= n; i++)
    {
        if(malla.cantNodos == 0) crearInicio(malla);
        else
        {
            pU = malla.finH;
            creaVer(pU, malla.longitudV, 1, NULL);
            malla.finH = pU->sig;
            malla.longitudH++;
        }
        malla.cantNodos = malla.longitudH * malla.longitudV;
    }
}

void crearFila(ListaO &malla, int n)
{
    NodoO *pU;
    
    for(int i=1; i <= n; i++)
    {
        if(malla.cantNodos == 0) crearInicio(malla);
        else
        {
            pU = malla.finV;
            creaHor(pU, malla.longitudH, 1, NULL);
            malla.finV = pU->aba;
            malla.longitudV++;
        }
        malla.cantNodos = malla.longitudH * malla.longitudV;
    }
}

NodoO* encontrarNodoO(ListaO &malla, int coordX, int coordY)
{
    //No se revisa porque si se llamó es porque las coordenadas son correctas y existen
    NodoO *p;
    p = malla.cabezaH;
    for(int i=1; i <= coordX-1; i++) p = p->sig; //Se resta 1 porque si mandas a la celda final te bota el NULL
    for(int i=1; i <= coordY-1; i++) p = p->aba;
    return p;
}

void insertaValor(ListaO &malla, int valor, int coordX, int coordY)
{
    if(coordX > malla.longitudH or coordY > malla.longitudV) return;
    NodoO *p;
    p = encontrarNodoO(malla, coordX, coordY);
    p->elem.valor1 = valor;
}

void insertaFuncion(ListaO &malla, const char *func, int coordX, int coordY, int x, int y, int finX, int finY)
{
    if(coordX > malla.longitudH or coordY > malla.longitudV or strlen(func) > TAMFUNCS) return;
    NodoO *p;
    p = encontrarNodoO(malla, coordX, coordY);
    strcpy(p->elem.valor3, func);
    if(strcmp(p->elem.valor3, "sumaFila") == 0)
    {
        if(!(x <= 0 or y <= 0 or finX > malla.longitudH or x > finX)) p->elem.valor1 = sumaFila(malla, x, finX, y);
    }
}
    
int sumaFila(ListaO malla, int iniX, int finX, int fila)
{
    NodoO *p; int sum=0;
    p = malla.cabezaH;
    for(int i=1; i <= fila-1; i++) p = p->aba;
    for(int i=1; i <= iniX-1; i++) p = p->sig;
    for(int i=iniX; i <= finX; i++)
    {
        sum += p->elem.valor1;
        p = p->sig;
    }
    return sum;
}

int sumaCol()
{
    
}


//insertar(valor[0 si es funcion], funcion[caracter que la indiquee, si no habra funcion y el valor es 0 seria char '\0'],
//         ListaO, coordenad X, coordenada Y) [Ambas coordenadas deben existir]    

void mostrar(ListaO l)
{
    NodoO *p, *pM;
    p = l.cabezaH;
    if(p == NULL) return;
    for(int i=1; i <= l.longitudV; i++)
    {
        pM = p;
        for(int j=1; j <= l.longitudH; j++)
        {
            cout << pM->elem.valor1 << " | ";
            pM = pM->sig;
        }
        p = p->aba;
        cout << endl;
    }
    cout << endl;
}