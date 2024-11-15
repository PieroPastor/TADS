/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Grafos.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:33
 */

#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct nodoH{
    
    nodoH *sig;
    Elemento e;
    
} NodoH;

typedef struct nodoV{
    
    nodoV *sig;
    nodoH *ady;
    Elemento e;
    
} NodoV;

typedef struct{
    
    NodoV *cabeza;
    int longitud;
    
} Grafo;

#endif /* GRAFOS_H */

