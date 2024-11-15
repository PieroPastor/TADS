/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "TADS.h"
#include "ABB.h"

void construir(ABB &arbol)
{
    arbol = NULL;
}

NodoABB *crearNodoABB(Elemento e)
{
    NodoABB *p;
    p = new NodoABB;
    p->e = e;
    p->hder = NULL;
    p->hizq = NULL;
    return p;
}

void insertarRecursivo(ABB &pR, Elemento e)
{
    if (pR == NULL) pR=crearNodoABB(e);
    else if (e.valor1 < pR->e.valor1) insertarRecursivo(pR->hizq, e);
    else insertarRecursivo(pR->hder, e); 
}

void mostrarEnOrden(ABB pR)  
{
    if ( pR == NULL ) return;
    mostrarEnOrden(pR->hizq); 
    cout << pR->e.valor1 << " ";  
    mostrarEnOrden(pR->hder); 
}

void mostrarEnPreOrden(ABB pR)  
{
    if ( pR == NULL ) return;
    cout << pR->e.valor1 << " ";  
    mostrarEnPreOrden(pR->hizq); 
    mostrarEnPreOrden(pR->hder); 
}

void mostrarEnPostOrden(ABB pR)  
{
    if ( pR == NULL ) return; 
    mostrarEnPostOrden(pR->hizq); 
    mostrarEnPostOrden(pR->hder); 
    cout << pR->e.valor1 << " "; 
}

bool buscar(NodoABB* pR , int valor)
{
    NodoABB* p;
    p=pR;//asignamos el puntero a la raiz del árbol a un puntero aux.

    while (p!=NULL)
    {
        if (valor==p->e.valor1) return true;
	else//Si no encontramos el elemento en la raiz, buscamos en sus hijos
            if (valor < p->e.valor1)//si es menor a la raiz, vamos a la izquierda
                p=p->hizq;
            else
		p=p->hder;//si es mayor, vamos a la derecha
    }
    return false;//No se encontró el elemento.
}

ABB buscarNodo(ABB parbol, int valor)
{
    if(parbol == NULL or parbol->e.valor1 == valor) return parbol;
    if(valor < parbol->e.valor1) buscarNodo(parbol->hizq, valor);
    else buscarNodo(parbol->hder, valor);
}

NodoABB *menorNodo(NodoABB *pR)
{
	NodoABB *p;
	p = pR;
        if(p == NULL) return NULL;
	while(p->hizq != NULL) p = p->hizq;
	return p;
}

NodoABB *mayorNodo(NodoABB *pR)
{
	NodoABB *p;
	p = pR;
        if(p == NULL) return NULL;
	while(p->hder != NULL) p = p->hder;
	return p;
}

NodoABB *buscarAnterior(NodoABB *pR, int valor)
{
    if(pR == NULL) return NULL;
    if(pR->hder != NULL and pR->hder->e.valor1 == valor) return pR;
    if(pR->hizq != NULL and pR->hizq->e.valor1 == valor) return pR;
    if(valor < pR->e.valor1) buscarAnterior(pR->hizq, valor);
    else buscarAnterior(pR->hder, valor);
}

int contarNodos(NodoABB *p)
{
    if(p == NULL) return 0;
    return 1 + contarNodos(p->hizq) + contarNodos(p->hder);
}

int altura(NodoABB *p)
{
    if(p == NULL) return 0;
    int izq=0, der=0;
    izq += 1 + altura(p->hizq);
    der += 1 + altura(p->hder);
    if(izq > der) return izq;
    else return der;
}

int eliminar(ABB &arbol, int valor)
{
    NodoABB *p, *pA, *pAux, *pIzq, *pDer;
    p = buscarNodo(arbol, valor);
	
    if(p == NULL) return 0;
    else
    {
	if(p->e.valor1 == arbol->e.valor1)
	{
            arbol = p->hder;
            pAux = menorNodo(p->hder);
            if(pAux == NULL) arbol = p->hizq;
            else
            {
                pAux->hizq = p->hizq;
                p->hizq = NULL;
            } 
        }
        else
        {
            pA = buscarAnterior(arbol, valor);
            pIzq = p->hizq;
            pDer = p->hder;
            
            if(pDer == NULL and pIzq == NULL) 
            {
                if(p->e.valor1 < pA->e.valor1) pA->hizq = NULL;
                else pA->hder = NULL;
            }
            else if(pDer == NULL and pIzq != NULL)
            {
                if(p->e.valor1 < pA->e.valor1) pA->hizq = pIzq;
                else pA->hder = pIzq;
            }
            else if(pDer != NULL and pIzq == NULL)
            {
                if(p->e.valor1 < pA->e.valor1) pA->hizq = pIzq;
                else pA->hder = pIzq;
            }
            else
            {
                pAux = menorNodo(p->hder);
                pAux->hizq = p->hizq;
                if(p->e.valor1 < pA->e.valor1) pA->hizq = pDer;
                else pA->hder = pDer;
            }
        }
        delete p;
	return valor;
    }
}

ABB borraNodoRec(ABB parbol,int valor) //Se debe igualar a un arbol
{
    if(parbol==NULL) return parbol;
    
    if(valor < parbol->e.valor1) parbol->hizq = borraNodoRec(parbol->hizq,valor);
    else if(valor > parbol->e.valor1) parbol->hder = borraNodoRec(parbol->hder,valor);
    else //Es igual
    {
        if(parbol->hizq==NULL)
        {
            ABB temp = parbol->hder;
            delete parbol;
            return temp;
        }
        else if(parbol->hder==NULL)
        {
            ABB temp = parbol->hizq;
            delete parbol;
            return temp;    
        }
        ABB temp = menorNodo(parbol->hder);
        parbol->e = temp->e;
        parbol->hder = borraNodoRec(parbol->hder,temp->e.valor1); 
        return parbol;
    }
}

//Iterativos

void mostrarEnOrdenIterativo(ABB parbol)
{
    Pila aux; NodoABB *p; Elemento cima;
    construir(aux);
    p = parbol;
    do{
        while(p)
        {
            apilar(aux, p->e);
            p = p->hizq;
        }
        cima = desapilar(aux);
        p = buscarNodo(parbol, cima.valor1);
        cout << cima.valor1 << " ";
        p = p->hder;                
    } while(aux.longitud != 0 or p != NULL);
}

void mostrarEnPostOrdenIterativo(ABB parbol)
{
    Pila stack;
    NodoABB *prec;
    Elemento alto, aux;
    int cont=0, n=contarNodos(parbol);
    
    if(parbol == NULL) return;
    prec = parbol;
    construir(stack);
    do{
        while(prec)
        {
            apilar(stack, prec->e);
            prec = prec->hizq;
        }
        alto = stack.cima->e;
        prec=buscarNodo(parbol, alto.valor1);
        if(prec->hder and prec->hder->e.valor1 != aux.valor1) prec = prec->hder;
        else
        {
            alto = desapilar(stack);
            aux = alto;
            cout << alto.valor1 << " ";
            prec = NULL;
            cont++;
            if(cont == n) break;
        }
    } while(stack.longitud != 0);
}

void mostrarEnPreOrdenIterativo(ABB parbol)
{
    Pila aux;
    NodoABB *p;
    Elemento cima;
    
    if(parbol == NULL) return;
    p = parbol;
    construir(aux);
    
    do{
        while(p)
        {
            cout << p->e.valor1 << " ";
            apilar(aux, p->e);
            p = p->hizq;
        }
        cima = desapilar(aux);
        p = buscarNodo(parbol, cima.valor1);
        p = p->hder;    
    } while(aux.longitud != 0 or p != NULL);
}

void mostrarEnAmplitud(ABB parbol)
{
    ABB paux; Cola cola; Elemento aux;
    
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

int mostrarEnAmplitudReconoceNivel(ABB parbol)
{
    ABB paux; Cola cola; Elemento aux, cambNivel;
    int niveles=1, flag=0;
    
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
        if(paux->hder == NULL and paux->hizq == NULL and paux->e.valor1 == cambNivel.valor1 and cola.longitud != 0) cambNivel = cola.ini->e;
    }
    return niveles;
}

//Balanceo

void balanceABB(ABB &parbol)
{
    Cola aux, colaAux; NodoABB *p = parbol; ABB pAux;
    construir(aux); construir(colaAux); construir(pAux);
    llenaColaABB(aux, p);
    for(int i=0 ; i<2 ; i++) encolar(colaAux,  desencolar(aux));
    insertarRecursivo(pAux, desencolar(aux));    
    for(int i=0 ; i<2 ; i++) insertarRecursivo(pAux, desencolar(colaAux));
    while(aux.longitud != 0) insertarRecursivo(pAux, desencolar(aux));
    parbol = pAux;
}

void llenaColaABB(Cola &cola, ABB parbol)
{
    if ( parbol != NULL ){  
        Elemento e = parbol->e;
        encolar(cola, e);
        llenaColaABB( cola, parbol->hizq);  // se recorre en preorden el subarbol izquierdo
        llenaColaABB( cola, parbol->hder);  // se recorre en preorden el subarbol derecho
    }
}

