#include <cstddef>

typedef unsigned int uint;
struct nodoAB {
    uint elem;
    nodoAB * izq, * der;
};
typedef nodoAB * AB;

AB consArbol(uint info, AB a1, AB a2) {
    AB nuevo = new nodoAB;
    nuevo->elem = info;
    nuevo->izq = a1;
    nuevo->der = a2;
    return nuevo;
}

uint contarElems(AB ar) {
    return ar == NULL ? 0 : 1 + contarElems(ar->izq) + contarElems(ar->der);
}

uint max (uint a, uint b) {
    return a < b ? b : a;
}

uint altura(AB ar) {
    return ar == NULL ? 0 : 1 + max(altura(ar->izq), altura(ar->der));
}

uint contarHojas(AB ar) {
    if (ar == NULL)
        return 0;
    else if (ar->der == NULL && ar->izq == NULL)
        return 1;
    else
        return contarHojas(ar->der) + contarHojas(ar->izq);
}

AB copiar(AB ar) {
    if (ar == NULL) 
        return NULL;
    else {
        AB nuevo = new nodoAB;
        nuevo->elem = ar->elem;
        nuevo->izq = copiar(ar->izq);
        nuevo->der = copiar(ar->der);
        return nuevo;
    }
}

void liberarArbol(AB &ar) {
    if (ar != NULL) {
        liberarArbol(ar->izq);
        liberarArbol(ar->der);
        delete ar;
    }
}
