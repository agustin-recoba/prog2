/* 5469187 */

#include "../include/grafo.h"
#include "../include/mapping.h"
#include "../include/avl.h"


#include <stdio.h>
#include <stdlib.h>

struct _rep_grafo {
    TMapping map;
    nat vertices;
    nat aristasRest;
    TAvl *vecinos;
};

TGrafo crearGrafo(nat N, nat M) {
    TGrafo graf = new _rep_grafo;
    graf->map = crearMap(M);
    graf->vertices = N;
    graf->aristasRest = M;
    graf->vecinos = new TAvl[N+1];
    for (nat i = 0; i <= N; i++)
        graf->vecinos[i] = NULL;
    return graf;
}

nat cantidadVertices(TGrafo g) {
    return g->vertices;
}

bool hayMParejas(TGrafo g) {
    return g->aristasRest == 0;
}

static nat hashGrafo(nat v1, nat v2, nat N) {
    nat min = v1 < v2 ? v1 : v2;
    nat max = v1 == min ? v2 : v1;
    return (min - 1) * N + max - 1;
}

TGrafo hacerVecinos(nat v1, nat v2, double d, TGrafo g)  {
    nat hash = hashGrafo(v1, v2, g->vertices);
    g->map = asociarEnMap(hash, d, g->map);
    g->aristasRest--;
    g->vecinos[v1] = insertarEnAvl(v2, g->vecinos[v1]);
    g->vecinos[v2] = insertarEnAvl(v1, g->vecinos[v2]);
    return g;
}

bool sonVecinos(nat v1, nat v2, TGrafo g) {
    nat hash = hashGrafo(v1, v2, g->vertices);
    return existeAsociacionEnMap(hash, g->map);
}

double distancia(nat v1, nat v2, TGrafo g) {
    nat hash = hashGrafo(v1, v2, g->vertices);
    return valorEnMap(hash, g->map);
}

TIterador vecinos(nat v, TGrafo g) {
    return enOrdenAvl(g->vecinos[v]);
}

/*
Libera la memoria asignada a 'g'.
El tiempo de ejecuión en el peor caso en O(N*N + M), siende 'N' y 'M' los
parámetros pasados en crearGrafo.
*/
void liberarGrafo(TGrafo g) {
    liberarMap(g->map);
    for (nat i = 0; i <= g->vertices; i++)
        liberarAvl(g->vecinos[i]);
    delete[] g->vecinos;
    delete g; 
}