/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Colas.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:29
 */

#ifndef COLAS_H
#define COLAS_H

typedef struct nodoC{
    
    nodoC *sig;
    Elemento e;
    
} NodoC;

typedef struct{
    
    NodoC *ini;
    NodoC *fin;
    int longitud;
    
} Cola;

void construir(Cola &c);
NodoC *crearNodoC(Elemento e);
void encolar(Cola &c, Elemento e);
Elemento desencolar(Cola &c);
void mostrar(Cola c);

#endif /* COLAS_H */

