/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListasDeListas.h
 * Author: piero
 *
 * Created on 12 de julio de 2023, 22:49
 */

#ifndef LISTASDELISTAS_H
#define LISTASDELISTAS_H

typedef struct nodoLL{
    
    nodoLL *sig;
    Elemento elem;
    int longitud;
    nodoLL *ant;
    nodoLL *cabeza;
    nodoLL *fin;
    
} NodoLL;

typedef struct {
    
    int longitud;
    NodoLL *cabeza;
    NodoLL *fin;
    
} ListaDeListas;

#endif /* LISTASDELISTAS_H */

