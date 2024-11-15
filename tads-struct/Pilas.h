/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pilas.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:29
 */

#ifndef PILAS_H
#define PILAS_H

typedef struct nodoP{
    
    Elemento e;
    nodoP *sig;
    
} NodoP;

typedef struct{
    
    NodoP *cima;
    int longitud;
    
} Pila;

void construir(Pila &p);
NodoP* crearNodoP(Elemento e, NodoP *s);
void apilar(Pila &pila, Elemento e);
Elemento desapilar(Pila &pila);
void mostrar(Pila pila);

#endif /* PILAS_H */

