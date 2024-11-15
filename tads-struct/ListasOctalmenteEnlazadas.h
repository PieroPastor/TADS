/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListasOctalmenteEnlazadas.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:29
 */

#ifndef LISTASOCTALMENTEENLAZADAS_H
#define LISTASOCTALMENTEENLAZADAS_H

typedef struct nodoO{
    
    nodoO *sig;
    nodoO *ant;
    Elemento elem;
    nodoO *arr;
    nodoO *aba;
    
} NodoO;

typedef struct{
    
    NodoO *cabezaH;
    NodoO *cabezaV;
    NodoO *finH;
    NodoO *finV;
    int longitudH;
    int longitudV;
    int cantNodos;
    
} ListaO;

void construir(ListaO &l);
NodoO* crearNodoO(Elemento e, NodoO *u, NodoO *d, NodoO *l, NodoO *r);

void crearInicio(ListaO &malla);

void creaVer(NodoO *pU, int longi, int i, NodoO *u);
void creaHor(NodoO *pU, int longi, int i, NodoO *l);
void crearColumna(ListaO &malla, int n);
void crearFila(ListaO &malla, int n);

NodoO* encontrarNodoO(ListaO &malla, int coordX, int coordY);
void insertaValor(ListaO &malla, int valor, int coordX, int coordY);
void insertaFuncion(ListaO &malla, const char *func, int coordX, int coordY, int iniX, int iniY, int finX, int finY);

int sumaFila(ListaO malla, int iniX, int finX, int fila);

void mostrar(ListaO l);

#endif /* LISTASOCTALMENTEENLAZADAS_H */

