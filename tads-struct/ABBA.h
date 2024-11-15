/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ABBA.h
 * Author: piero
 *
 * Created on 27 de junio de 2023, 16:09
 */

#ifndef ABBA_H
#define ABBA_H

typedef struct nodoABBA{
    
    nodoABBA *hizq;
    nodoABBA *hder;
    nodoABBA *dent;
    Elemento e;
    nodoABBA *fuer;
    nodoABBA *back;
    
} NodoABBA;

typedef NodoABBA* ABBA;

void construir(ABBA &parbol);
NodoABBA *crearNodoABBA(Elemento e, NodoABBA *ant, NodoABBA *fuera);
void insertarRecursivo(ABBA &parbol, ABBA ant, ABBA fuera, Elemento *arrElem, int i, int n);
NodoABBA* buscarRecursivo(ABBA parbol, Elemento *arrElem, int i, int n);

#endif /* ABBA_H */

