/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AB.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:30
 */

#ifndef AB_H
#define AB_H

typedef struct nodoAB{
    
    nodoAB *hizq;
    Elemento e;
    nodoAB *hder;
    
} NodoAB;

typedef NodoAB* AB;

void construir(AB &parbol);
NodoAB* crearNodoAB(Elemento e);
AB h_der(AB parbol);
AB h_izq(AB parbol);
void insertarAB(AB &parbol, Elemento e);
void hallarCombs(AB parbol, Pila &aux);
AB buscarNodo(AB parbol, int valor);
void mostrarEnAmplitudAB(AB parbol);
int mostrarEnAmplitudReconoceNivel(AB parbol);
int hallarCombsCumplen(AB parbol, int sum, int obj);

#endif /* AB_H */

