#include <cstddef>

typedef unsigned int uint;
struct EstInfo {
    uint nota;
    int ci;
};

struct nodoABB {
    EstInfo dato;
    nodoABB *izq, *der;
};

typedef nodoABB * ABB;

EstInfo maxABB(ABB ar) {
    return ar->der == NULL ? ar->dato : maxABB(ar->der);
}

void removerMaxABB(ABB &ar) {
    if (ar->der == NULL) {
        ABB aux = ar;
        ar = ar->izq;
        delete aux;
    } else
        removerMaxABB(ar->der);
}

ABB filtrado (ABB &ar, uint cota) {
    if (ar == NULL)
        return NULL;
    else {
        if (ar->dato.nota <= cota) {
            ar->dato = maxABB(ar->izq);
            removerMaxABB(ar->izq);
            return filtrado(ar, cota);
        } else {
            ar->izq = filtrado(ar->izq, cota);
            ar->der = filtrado(ar->der, cota);
            return ar;
        }
    }
}

