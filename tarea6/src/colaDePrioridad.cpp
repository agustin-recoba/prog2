/* 5469187 */

#include "../include/colaDePrioridad.h"
#include "../include/info.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double* prioridades;

struct _rep_colaDePrioridad {
    nat *heap;
    prioridades *elementos;
    nat tamHeap, espUsadoHeap;
};

TColaDePrioridad crearCP(nat N) {

    TColaDePrioridad col = new _rep_colaDePrioridad;
    col->espUsadoHeap = 0;
    col->tamHeap = N;
    col->heap = new nat[N+1];
    col->elementos = new prioridades[N];
    for (nat i = 0; i < N; i++)
        col->elementos[i] = NULL;

    return col;
}

nat rangoCP(TColaDePrioridad cp) {
    return cp->tamHeap;
}

static void swap(nat &i1, nat &i2) {
    nat aux = i2;
    i2 = i1;
    i1 = aux;
}

TColaDePrioridad insertarEnCP(nat elem, double valor, TColaDePrioridad cp) {
    cp->elementos[elem-1] = new double;
    *(cp->elementos[elem-1]) = valor;

    cp->espUsadoHeap++;
    nat espLibre = cp->espUsadoHeap;

    cp->heap[espLibre] = elem;

    while (espLibre/2 != 0 && prioridad(cp->heap[espLibre/2], cp) > prioridad(cp->heap[espLibre], cp)) {
        swap(cp->heap[espLibre/2], cp->heap[espLibre]);
        espLibre = espLibre/2;
    }

    return cp;
}

bool estaVaciaCP(TColaDePrioridad cp) {
    return cp->espUsadoHeap == 0;    
}

nat prioritario(TColaDePrioridad cp) {
    return cp->heap[1];
}

TColaDePrioridad eliminarPrioritario(TColaDePrioridad cp) {
    delete cp->elementos[cp->heap[1]];
    cp->elementos[cp->heap[1]] = NULL;

    nat aColocar = cp->espUsadoHeap;
    cp->espUsadoHeap--;
    nat i = 1;
    bool colocado = false;

    while (i*2 <= cp->espUsadoHeap && i*2+1 <= cp->espUsadoHeap && !colocado) {
        nat min = prioridad(cp->heap[i*2], cp) < prioridad(cp->heap[i*2+1], cp) ? i*2 : i*2 + 1;
        if (prioridad(aColocar, cp) <= prioridad(cp->heap[min], cp)) {
            cp->heap[i] = aColocar;
            colocado = true;
        } else {
            cp->heap[i] = cp->heap[min];
            i = min;
        }
    }
    if (!colocado) {
        cp->heap[i] = aColocar;
    } 
    return cp;
}

bool estaEnCP(nat elem, TColaDePrioridad cp) {
    return cp->elementos[elem] != NULL;
}

double prioridad(nat elem, TColaDePrioridad cp) {
    return *cp->elementos[elem];
}


/*
  Modifica el valor de la propiedad asociada a 'elem'; pasa a ser 'valor'.
  Precondición: estaEnCp(elem, cp).
  Devuelve 'cp'.
  El tiempo de ejecución en el peor caso es O(log N), siendo 'N' el parámetro
  pasado en crearCP.
 */
TColaDePrioridad actualizarEnCP(nat elem, double valor, TColaDePrioridad cp) {
    *(cp->elementos[elem]) = valor;
    return cp;
}


/*
  Libera la menoria asignada a 'cp'.
  El tiempo de ejecución en el peor caso es O(N), siendo 'N' el parámetro
  pasado en crearCP.
 */
void liberarCP(TColaDePrioridad cp) {
    for (nat i = 1; i <= cp->espUsadoHeap; i++)
        delete cp->elementos[i];
    delete[] cp->elementos;
    delete[] cp->heap;
    delete cp;
}