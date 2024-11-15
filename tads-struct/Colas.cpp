/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "TADS.h"
#include "Colas.h"

using namespace std;

void construir(Cola &c)
{
    c.fin = NULL; c.ini = NULL; c.longitud = 0;
}

NodoC *crearNodoC(Elemento e)
{
    NodoC *p;
    p = new NodoC;
    p->e = e;
    p->sig = NULL;
    return p;
}

void encolar(Cola &c, Elemento e)
{
    NodoC *p;
    p = crearNodoC(e);
    if(c.ini == NULL)
    {
        c.ini = p;
        c.fin = p;
    }
    else
    {
        c.fin->sig = p;
        c.fin = p;
    }
    c.longitud++;
}

Elemento desencolar(Cola &c)
{
    NodoC *p;
    p = c.ini;
    c.ini = p->sig;
    Elemento x;
    x = p->e;
    delete p;
    c.longitud--;
    return x;
}

void mostrar(Cola c)
{
    NodoC *p;
    p = c.ini;
    
    for(int i=1; i <= c.longitud; i++)
    {
        cout << p->e.valor1 << " ";
        p = p->sig;
    }
    cout << endl;
}
