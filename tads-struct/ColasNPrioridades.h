/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColasNPrioridades.h
 * Author: piero
 *
 * Created on 12 de julio de 2023, 22:48
 */

#ifndef COLASNPRIORIDADES_H
#define COLASNPRIORIDADES_H

typedef struct nodoCNP{
    
    Elemento elem;
    int prioridad;
    nodoCNP *sig;
    
} NodoCNP;

typedef struct colaPrioridad{
       
    int prioridad;
    NodoCNP *primero;
    NodoCNP *ultimo;
    colaPrioridad *sig;
    
} ColaPrioridad;

typedef struct{
    
    int longitud;
    int cantPrioridades;
    ColaPrioridad *prioridades;
    
} ColaNP;

void construir(ColaNP &cola);
ColaPrioridad* crearPrioridad(int priori, ColaPrioridad *s);
NodoCNP* crearNodoCNP(Elemento e, int priori);
void encolar(ColaNP &cola, int priori, Elemento elem);

#endif /* COLASNPRIORIDADES_H */

