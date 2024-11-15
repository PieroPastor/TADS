/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "TADS.h"
#include "Listas.h"

using namespace std;

void construir(Lista &l)
{
    l.fin = NULL; l.cabeza = NULL; l.longitud = 0;
}

bool esListaVacia(Lista l)
{
    return l.longitud == 0;
}

NodoL *crearNodoL(Elemento elem, NodoL *s)
{
    NodoL *p;
    p = new NodoL;
    p->elem = elem;
    p->sig = s;
    return p;
}

void enlistar(Lista &l, Elemento elem)
{
    NodoL *p;
    p = crearNodoL(elem, NULL);
    if(l.longitud == 0)
    {
        l.fin = p;
        l.cabeza = p;
    }
    else
    {
        l.fin->sig = p;
        l.fin = p;
    }
    l.longitud++;
}

void mostrar(Lista l)
{
    NodoL *p;
    p = l.cabeza;
    for(int i=1; i <= l.longitud; i++)
    {
        cout << p->elem.valor1 << " ";
        p = p->sig;
    }
    cout << endl;
}

void combinar(Lista &l1, Lista &l2, NodoL *p) //Combina dos listas ordenadas
{
    if(l2.longitud == 0) return;
    if(l1.longitud == 0) l1 = l2;
    if(l2.cabeza->elem.valor1 <= l1.fin->elem.valor1)
    {
        l1.fin->sig = l2.cabeza;
        l1.fin = l2.fin;
        l1.longitud += l2.longitud;
        l2.longitud = 0;
        return;
    }
    else if(l2.fin->elem.valor1 >= l1.cabeza->elem.valor1)
    {
        l2.fin->sig = l1.cabeza;
        l1.cabeza = l2.cabeza;
        l1.longitud += l2.longitud;
        l2.longitud = 0;
        return;
    }
    else p = inserta(l1, l2, p);
    combinar(l1, l2, p);
}

NodoL* inserta(Lista &l1, Lista &l2, NodoL *p)
{
    NodoL *pS, *pAux;
    
    if(l2.cabeza->elem.valor1 > l1.cabeza->elem.valor1)
    {
        l1.cabeza = l2.cabeza;
        l2.cabeza = l2.cabeza->sig;
        l1.cabeza->sig = p;
        l2.longitud--;
        l1.longitud++;
        return p;
    }
    
    while(p != NULL)
    {
        if(l2.cabeza->elem.valor1 <= p->elem.valor1)
        {
            if(l2.fin->elem.valor1 > p->sig->elem.valor1)
            {
                pS = p->sig;
                p->sig = l2.cabeza;
                l2.fin->sig = pS;
                l1.longitud += l2.longitud;
                l2.longitud = 0;
                return p;
            }
            else if(p->sig->elem.valor1 < l2.cabeza->elem.valor1)
            {
                pS = p->sig;
                pAux = l2.cabeza;
                p->sig = pAux;
                l2.cabeza = pAux->sig;
                pAux->sig = pS;
                l2.longitud--;
                l1.longitud++;
                return p;
            }
        }
        p = p->sig;
    }
}
