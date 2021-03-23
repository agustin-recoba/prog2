#include <cstddef>
#include <cstdio>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo *lista;

void insOrd(lista &l, int x) {
    if (l == NULL) {
        l = new nodo;
        l->sig = NULL;
        l->elem = x;
    } else {
        if (l->elem < x){
            insOrd(l->sig, x);
        } else {
            lista aux = new nodo;
            aux->elem = l->elem;
            aux->sig = l->sig;
            l->elem = x;
        }
    }        
}

void snoc(lista &l, int x) {
    if (l == NULL){
        l = new nodo;
        l->elem = x;
        l->sig = NULL;
    } else {
        snoc(l->sig, x);
    }
}

void removeAll(lista &l, int x) {
    
}