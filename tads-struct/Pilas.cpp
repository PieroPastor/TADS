/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "TADS.h"
#include "Pilas.h"

using namespace std;

void construir(Pila &p)
{
    p.cima = NULL;
    p.longitud = 0;
}

NodoP* crearNodoP(Elemento e, NodoP *s)
{
    NodoP *p;
    p = new NodoP; 
    p->e = e;
    p->sig = s;
    return p;
}

void apilar(Pila &pila, Elemento e)
{
    NodoP *p;
    p = crearNodoP(e, pila.cima);
    pila.cima = p;
    pila.longitud++;
}

Elemento desapilar(Pila &pila)
{
    NodoP *p; Elemento x;
    p = pila.cima;
    x = p->e;
    pila.cima = p->sig;
    delete p;
    pila.longitud--;
    return x;
}

void mostrar(Pila pila)
{
    NodoP *p;
    p = pila.cima;
    for(int i=1; i <= pila.longitud; i++)
    {
        cout << p->e.valor1 << " ";
        p = p->sig;
    }
    cout << endl;
}

void hanoi(Pila &pila, Pila &pivot, Pila &fin, int n)
{
    if(n == 0) return;
    if(n == 1) apilar(fin, desapilar(pila));
    hanoi(pila, fin, pivot, n-1);
    apilar(fin, desapilar(pila));
    hanoi(pivot, pila, fin, n-1);
}