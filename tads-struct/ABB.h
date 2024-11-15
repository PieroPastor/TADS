/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ABB.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:30
 */

#ifndef ABB_H
#define ABB_H

typedef struct nodoABB{
    
    nodoABB *hizq;
    Elemento e;
    nodoABB *hder;
    
} NodoABB;

typedef NodoABB* ABB;

void construir(ABB &arbol);
NodoABB *crearNodoABB(Elemento e);
void insertarRecursivo(ABB &pR, Elemento e);
void mostrarEnOrden(ABB pR);
void mostrarEnPreOrden(ABB pR);
void mostrarEnPostOrden(ABB pR);
bool buscar(NodoABB* pR , int valor);
ABB buscarNodo(ABB parbol, int valor);
NodoABB *menorNodo(NodoABB *pR);
NodoABB *mayorNodo(NodoABB *pR);
NodoABB *buscarAnterior(NodoABB *pR, int valor);
int contarNodos(NodoABB *p);
int altura(NodoABB *p);
int eliminar(ABB &arbol, int valor);
ABB borraNodoRec(ABB parbol,int valor);

void mostrarEnOrdenIterativo(ABB parbol);
void mostrarEnPostOrdenIterativo(ABB parbol);
void mostrarEnPreOrdenIterativo(ABB parbol);

void mostrarEnAmplitud(ABB parbol);
int mostrarEnAmplitudReconoceNivel(ABB parbol);

void balanceABB(ABB &parbol);
void llenaColaABB(Cola &cola, ABB parbol);

#endif /* ABB_H */

