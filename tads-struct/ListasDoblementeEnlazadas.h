/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListasDoblementeEnlazadas.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:29
 */

#ifndef LISTASDOBLEMENTEENLAZADAS_H
#define LISTASDOBLEMENTEENLAZADAS_H

typedef struct nodoLD{
    
    nodoLD *sig;
    Elemento elem;
    nodoLD *ant;
    
} NodoLD;

typedef struct{
    
    NodoLD cabeza;
    NodoLD fin;
    int longitud;
    
} ListaD;

#endif /* LISTASDOBLEMENTEENLAZADAS_H */

