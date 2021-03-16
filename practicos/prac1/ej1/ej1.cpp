#include <stdio.h>
#include <cstring>

#include "Pila.cpp"

void imprimirPila(Pila p){
    Pila aux = crearPila();
    while (!esVacia(p)) {
        printf("> %d \n", cima(p));
        aux = apilar(cima(p), aux);
        p = desapilar(p); 
    }
    while (!esVacia(aux)) {
        p = apilar(cima(aux), p); 
        aux = desapilar(aux);        
    }
}

int cantidadPila (Pila p) {
    Pila aux = crearPila();
    int contador = 0;
    while (!esVacia(p)) {
        contador++;
        aux = apilar(cima(p), aux);
        p = desapilar(p); 
    }
    while (!esVacia(aux)) {
        p = apilar(cima(aux), p); 
        aux = desapilar(aux);        
    }
    return contador;
}

void cambiarXY (int x, int y, Pila &p) {
    Pila aux = crearPila();
    while (!esVacia(p)) {
        if (cima(p) == x) {
            p = desapilar(p);
            p = apilar(y, p);
        }
        aux = apilar(cima(p), aux);
        p = desapilar(p); 
    }
    while (!esVacia(aux)) {
        p = apilar(cima(aux), p); 
        aux = desapilar(aux);        
    }
}

bool iguales (Pila p1, Pila p2) {
    Pila aux1 = crearPila();
    Pila aux2 = crearPila();

    while ( ( !esVacia(p1) && !esVacia(p2) ) && cima(p1) == cima(p2) ) {
        aux1 = apilar(cima(p1), aux1);
        aux2 = apilar(cima(p2), aux2);
        p1 = desapilar(p1); 
        p2 = desapilar(p2);
    }
    bool sonIguales = esVacia(p1) && esVacia(p2);

    while (!esVacia(aux1)) {
        p1 = apilar(cima(aux1), p1);
        aux1 = desapilar(aux1);        
    }
    while (!esVacia(aux2)) {
        p2 = apilar(cima(aux2), p2);
        aux2 = desapilar(aux2);        
    }
    return sonIguales;
}

