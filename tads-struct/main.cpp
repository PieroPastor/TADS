/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: piero
 *
 * Created on 30 de mayo de 2023, 11:22
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "TADS.h"

int main(int argc, char** argv) {
    
    /*ListaO l;
    
    construir(l);
    
    crearColumna(l, 1);
    crearColumna(l, 3);
    
    crearFila(l, 2);
    
    crearColumna(l, 2);
    
    cout << l.longitudV << " " << l.longitudH << " " << l.cantNodos << endl;
    
    mostrar(l);
    
    l.cabezaH->sig->sig->ant->elem.valor1 = 2;
    
    mostrar(l);
    
    l.cabezaH->aba->aba->arr->elem.valor1 = 1;
    
    mostrar(l);
    
    l.cabezaV->aba->arr->elem.valor1 = 3;
    
    mostrar(l);
    
    insertaValor(l, 4, 6, 2);
    
    mostrar(l);
    
    insertaFuncion(l, "sumaFila", 4, 2, 1, 1, 3, 879);
    
    mostrar(l);*/
    
    /*ListaDC l;
    
    construir(l);
    
    crearColumna(l, 1); 
    
    crearColumna(l, 3);
    
    crearFila(l, 2);
    
    crearColumna(l, 2);
    
    cout << l.longitudV << " " << l.longitudH << " " << l.cantNodos << endl;
    
    mostrar(l);
    
    cout << endl << endl << endl;
    
    crearFondo(l, 3);
    
    cout << l.longitudV << " " << l.longitudH << " " << l.longitudZ << " " << l.cantNodos << endl;
    
    insertaValor(l, 2, 1, 1, 1); insertaValor(l, 3, 3, 2, 1); insertaValor(l, 2, 3, 3, 2); insertaValor(l, 2, 1, 1, 12);   
    insertaValor(l, 2, 6, 3, 4);
    mostrar(l);*/
    
    /*ABB arbol; Elemento e;
    
    construir(arbol);
    e.valor1 = 2;
    insertarRecursivo(arbol, e);
    e.valor1 = 4;
    insertarRecursivo(arbol, e);
    e.valor1 = 1;
    insertarRecursivo(arbol, e);
    e.valor1 = 3;
    insertarRecursivo(arbol, e);
    e.valor1 = 0;
    insertarRecursivo(arbol, e);
    e.valor1 = -5;
    insertarRecursivo(arbol, e);
    e.valor1 = -2;
    insertarRecursivo(arbol, e);
    e.valor1 = -6;
    insertarRecursivo(arbol, e);
    e.valor1 = 5;
    insertarRecursivo(arbol, e);
    
    mostrarEnOrden(arbol); cout << endl;
    
    eliminar(arbol, -6);
    //arbol=borraNodoRec(arbol, 1);
    
    mostrarEnOrden(arbol); cout << endl;
    mostrarEnOrdenIterativo(arbol); cout << endl;
    
    mostrarEnPostOrden(arbol); cout << endl;
    mostrarEnPostOrdenIterativo(arbol); cout << endl;
    
    mostrarEnPreOrden(arbol); cout << endl;
    mostrarEnPreOrdenIterativo(arbol); cout << endl;
    
    //mostrarEnAmplitud(arbol);
    
    int niveles=mostrarEnAmplitudReconoceNivel(arbol);
    cout << endl << "Niveles: " << niveles << endl;
    
    balanceABB(arbol);
    
    niveles=mostrarEnAmplitudReconoceNivel(arbol);
    cout << endl << "Niveles: " << niveles << endl;
    
    mostrarEnOrden(arbol);*/
    
    /*AB arbol; Elemento e; Pila pila;
    
    construir(arbol); construir(pila);
    
    e.valor1 = 10;
    insertarAB(arbol, e);
    e.valor1 = 50;
    insertarAB(arbol, e);
    e.valor1 = 20;
    insertarAB(arbol, e);
    e.valor1 = 30;
    insertarAB(arbol, e);
    e.valor1 = 40;
    insertarAB(arbol, e);
    
    mostrarEnAmplitudAB(arbol);
    
    int nivel=mostrarEnAmplitudReconoceNivel(arbol);
    
    cout << endl << nivel << endl;
    
    hallarCombs(arbol, pila);
    
    cout << "Cantidad: " << hallarCombsCumplen(arbol, 0, 70) << endl;
    
    ABBA parbol;
    Elemento valores[1];
    valores[0].valor1 = 1;
    construir(parbol);
    insertarRecursivo(parbol, NULL, NULL, valores, 0, 1);
    cout << parbol->e.valor1 << endl;
    
    valores[0].valor1 = 1;
    construir(parbol);
    insertarRecursivo(parbol, NULL, NULL, valores, 0, 1);
    
    Elemento valoresN[2];
    valoresN[0].valor1 = 1;
    valoresN[1].valor1 = -1;
    construir(parbol);
    insertarRecursivo(parbol, NULL, NULL, valoresN, 0, 2);
    cout << parbol->e.valor1 << " " << parbol->dent->e.valor1 << " " << parbol->dent->fuer->e.valor1 << endl;
    
    valoresN[0].valor1 = 1;
    cout << buscarRecursivo(parbol, valoresN, 0, 2)->e.valor1 << endl;*/
    
    ColaNP cola;
    Elemento elem;
    
    construir(cola);
    elem.valor1 = 1;
    encolar(cola, 1, elem);
    cout << cola.prioridades->primero->elem.valor1;
    elem.valor1 = 4;
    encolar(cola, 4, elem);
    cout << cola.prioridades->sig->primero->elem.valor1;
    elem.valor1 = 2;
    encolar(cola, 2, elem);
    cout << cola.prioridades->sig->primero->elem.valor1;
    cout << cola.prioridades->sig->sig->primero->elem.valor1 << endl;
    cout << cola.prioridades->primero->elem.valor1 << cola.prioridades->primero->sig->elem.valor1;
    cout << cola.prioridades->primero->sig->sig->elem.valor1 << endl;
    elem.valor1 = 2;
    encolar(cola, 2, elem);
    cout << cola.prioridades->primero->elem.valor1 << cola.prioridades->primero->sig->elem.valor1;
    cout << cola.prioridades->primero->sig->sig->elem.valor1 << 
            cola.prioridades->primero->sig->sig->sig->elem.valor1 << endl;
    elem.valor1 = 0;
    encolar(cola, 0, elem);
    cout << cola.prioridades->primero->elem.valor1 << cola.prioridades->primero->sig->elem.valor1;
    cout << cola.prioridades->primero->sig->sig->elem.valor1 << 
            cola.prioridades->primero->sig->sig->sig->elem.valor1 << 
            cola.prioridades->primero->sig->sig->sig->sig->elem.valor1 << endl;
    cout << cola.cantPrioridades;
    
    return 0;
}

