/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListasDodecalmenteEnlazadas.h
 * Author: piero
 *
 * Created on 1 de junio de 2023, 19:18
 */

#ifndef LISTASDODECALMENTEENLAZADAS_H
#define LISTASDODECALMENTEENLAZADAS_H

typedef struct nodoDC{
    
    nodoDC *arr;
    nodoDC *aba;
    Elemento elem;
    nodoDC *der;
    nodoDC *izq;
    nodoDC *dentro;
    nodoDC *fuera;
    
} NodoDC;

typedef struct{
    
    NodoDC *cabeza;
    NodoDC *finH;
    NodoDC *finV;
    NodoDC *finZ;
    int longitudH;
    int longitudV;
    int longitudZ;
    int cantNodos;
    
}ListaDC;

void construir(ListaDC &l);
NodoDC* crearNodoDC(Elemento e, NodoDC *u, NodoDC *d, NodoDC *l, NodoDC *r, NodoDC *den, NodoDC *fue);

void crearInicio(ListaDC &malla);
void creaVer(NodoDC *pU, int longiV, int longiZ, int i, int j, NodoDC *u, NodoDC *fue);
void crearColumna(ListaDC &malla, int n);
void creaHor(NodoDC *pU, int longiH, int longiZ, int i, int j, NodoDC *l, NodoDC *fue);
void crearFila(ListaDC &malla, int n);
void creaDen(NodoDC *pU, int longiH, int longiV, int i, int j, NodoDC *l, NodoDC *u);
void crearFondo(ListaDC &malla, int n);

NodoDC *encontrarNodoDC(ListaDC &malla, int x, int y, int z);
void insertaValor(ListaDC &malla, int valor, int coordX, int coordY, int coordZ);

void mostrar(ListaDC l);

#endif /* LISTASDODECALMENTEENLAZADAS_H */

