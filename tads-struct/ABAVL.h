/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ABAVL.h
 * Author: piero
 *
 * Created on 12 de julio de 2023, 22:48
 */

#ifndef ABAVL_H
#define ABAVL_H

typedef struct nodoABAVL{
    
    nodoABAVL *hizq;
    Elemento elem;
    nodoABAVL *hder;
    
} NodoABAVL;

typedef NodoABAVL* ABVL;

#endif /* ABAVL_H */

