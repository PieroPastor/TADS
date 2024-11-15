/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   TADS.h
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:26
 */

#ifndef TADS_H
#define TADS_H

#include <cstring>

#define TAMFUNCS 20

typedef struct{
    
    int valor1;
    int valor2;
    char *valor3;
    
} Elemento; //Se hace una estructura para un uso más general

#include "Listas.h"
#include "ListasDeListas.h"
#include "ListasDoblementeEnlazadas.h"
#include "ListasOctalmenteEnlazadas.h"
#include "ListasDodecalmenteEnlazadas.h"
#include "ListasCirculares.h"
#include "Pilas.h"
#include "Colas.h"
#include "ColasNPrioridades.h"
#include "ABBA.h"
#include "ABB.h"
#include "ABAVL.h"
#include "AB.h"
#include "Grafos.h"

#endif /* TADS_H */

