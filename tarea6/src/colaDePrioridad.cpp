/* 5469187 */

#include "../include/colaDePrioridad.h"
#include "../include/info.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct _rep_colaDePrioridad {
    nat *heap;
    double *prioridades;
    nat *posiciones;
    nat tamHeap, espUsadoHeap;
};

TColaDePrioridad crearCP(nat N) {
    TColaDePrioridad col = new _rep_colaDePrioridad;
    col->espUsadoHeap = 0;
    col->tamHeap = N;
    col->heap = new nat[N+1];
    col->prioridades = new double[N+1];
    col->posiciones = new nat[N+1];
    for (nat i = 0; i <= N; i++) {
        col->prioridades[i] = -1;
        col->posiciones[i] = 0;
    }
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

/*static void imprimirHeap(TColaDePrioridad cp) {
    for (nat i = 0; i <= cp->tamHeap; i++)
        printf("%d", cp->heap[i]);
    printf("\n");
}*/

TColaDePrioridad insertarEnCP(nat elem, double valor, TColaDePrioridad cp) {
    cp->prioridades[elem] = valor;
    cp->espUsadoHeap++;
    cp->posiciones[elem] = cp->espUsadoHeap;
    cp->heap[cp->espUsadoHeap] = elem;

    nat i = cp->espUsadoHeap;

    while (i/2 != 0 && prioridad(cp->heap[i/2], cp) > prioridad(cp->heap[i], cp)) {
        swap(cp->heap[i/2], cp->heap[i]);
        swap(cp->posiciones[cp->heap[i/2]], cp->posiciones[cp->heap[i]]);
        i = i/2;
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
    cp->prioridades[cp->heap[1]] = -1;
    cp->posiciones[cp->heap[1]] = 0;
    cp->heap[1] = 0;

    nat aColocar = cp->heap[cp->espUsadoHeap];
    cp->espUsadoHeap--;
    nat i = 1;
    bool colocado = false;
    while (i*2+1 <= cp->espUsadoHeap && !colocado) {
        nat hijoMin = prioridad(cp->heap[i*2], cp) >= prioridad(cp->heap[i*2+1], cp) ? i*2 : i*2+1;
        if (prioridad(aColocar, cp) <= prioridad(cp->heap[hijoMin], cp)) {
            cp->heap[i] = aColocar;
            cp->posiciones[aColocar] = i;
            colocado = true;
        } else {
            cp->heap[i] = cp->heap[hijoMin];
            cp->posiciones[cp->heap[hijoMin]] = i;
            i = hijoMin;
        }
    }
    if (!colocado && i*2 == cp->espUsadoHeap) {

        if (prioridad(aColocar, cp) <= prioridad(cp->heap[i*2], cp)) {
            cp->heap[i] = aColocar;
            cp->posiciones[aColocar] = i;
        } else {
            cp->heap[i] = cp->heap[i*2];
            cp->posiciones[cp->heap[i*2]] = i;
            cp->heap[i*2] = aColocar;
            cp->posiciones[aColocar] = i*2;
        }
    } else if (!colocado) {
        cp->heap[i] = aColocar;
        cp->posiciones[aColocar] = i;
    }

    
    return cp;
}

bool estaEnCP(nat elem, TColaDePrioridad cp) {
    return cp->prioridades[elem] != -1;
}

double prioridad(nat elem, TColaDePrioridad cp) {
    return cp->prioridades[elem];
}

TColaDePrioridad actualizarEnCP(nat elem, double valor, TColaDePrioridad cp) {
    bool aumentaPrioridad = valor > cp->prioridades[elem];
    cp->prioridades[elem] = valor;
    nat i = cp->posiciones[elem];

    if (aumentaPrioridad) {
        bool colocado = false;
        while(i*2 <= cp->espUsadoHeap && i*2+1 <= cp->espUsadoHeap && !colocado) {
            nat min = cp->prioridades[i*2] < cp->prioridades[i-2+1] ? i*2 : i*2+1;
            if (prioridad(elem, cp) <= prioridad(cp->heap[min], cp)) {
                cp->heap[i] = elem;
                cp->posiciones[elem] = i;
                colocado = true;
            } else {
                cp->heap[i] = cp->heap[min];
                cp->posiciones[cp->heap[min]] = i;
                i = min;
            }
        }
        if (!colocado && i*2 == cp->espUsadoHeap) {
            if (prioridad(elem, cp) <= prioridad(cp->heap[i*2], cp)) {
                cp->heap[i] = elem;
                cp->posiciones[elem] = i;
            } else {
                cp->heap[i] = cp->heap[i*2];
                cp->posiciones[cp->heap[i*2]] = i;
                cp->heap[i*2] = elem;
                cp->posiciones[elem] = i*2;
            }
        } else if (!colocado) {
            cp->heap[i] = elem;
            cp->posiciones[elem] = i;
        }
    } else {
        while (i/2 != 0 && prioridad(cp->heap[i/2], cp) > prioridad(cp->heap[i], cp)) {
            swap(cp->heap[i/2], cp->heap[i]);
            swap(cp->posiciones[cp->heap[i/2]], cp->posiciones[cp->heap[i]]);
            i = i/2;
        }
    }
    return cp;
}

void liberarCP(TColaDePrioridad cp) {
    delete[] cp->posiciones;
    delete[] cp->prioridades;
    delete[] cp->heap;
    delete cp;
}