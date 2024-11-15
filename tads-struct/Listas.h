/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Listas.h
 * Author: Piero Pastor
 *
 * Created on 30 de mayo de 2023, 11:24
 */

#ifndef LISTAS_H
#define LISTAS_H

typedef struct nodoL{
    
    Elemento elem;
    nodoL *sig;
    
} NodoL;

typedef struct{
    
    NodoL *cabeza;
    NodoL *fin;
    int longitud;
    
} Lista;

void construir(Lista&);
bool esListaVacia(Lista);
NodoL *crearNodoL(Elemento, NodoL*);
void enlistar(Lista&, Elemento);
void mostrar(Lista);
void combinar(Lista&, Lista&, NodoL*);
NodoL* inserta(Lista&, Lista&, NodoL*);

#endif /* LISTAS_H */

