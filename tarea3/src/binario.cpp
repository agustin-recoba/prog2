/* 5469187 */

#include "../include/binario.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _rep_binario {
    TInfo elem;
    TBinario izq, der;
};

TBinario crearBinario() {
    return NULL;
}

TBinario insertarEnBinario(TInfo i, TBinario b) {
    if(b == NULL) {
        b = new _rep_binario;
        b->elem = i;
        b->izq = b->der = NULL;
    } else if (natInfo(i) < natInfo(b->elem))
        b->izq = insertarEnBinario(i, b->izq);
    else if(natInfo(i) > natInfo(b->elem))
        b->der = insertarEnBinario(i, b->der);
    return b;
}

TInfo mayor(TBinario b) {
    while(b->der != NULL)
        b = b->der;
    return b->elem;
}

TBinario removerMayor(TBinario b){
    if(b->der == NULL) {
        TBinario aux = b;
        b = b->izq;
        delete aux;
    } else {
        b->der = removerMayor(b->der);
    }
    return b;
}

TInfo raiz(TBinario b) {
    return b->elem;
}

TBinario izquierdo(TBinario b) {
    return b->izq;
}

TBinario derecho(TBinario b) {
    return b->der;
}

TBinario buscarSubarbol(nat elem, TBinario b) {
    if(b == NULL) 
        return NULL;
    else if (natInfo(b->elem) == elem) 
        return b;
    else if (natInfo(b->elem) > elem) 
        return buscarSubarbol(elem, b->izq);
    else
        return buscarSubarbol(elem, b->der);
}

static TBinario AUXpadre(nat elem, TBinario b) {
    if (b == NULL)
        return NULL;
    else if ((b->der != NULL && elem == natInfo(b->der->elem)) || (b->izq != NULL && elem == natInfo(b->izq->elem)))
        return b;
    else if (elem > natInfo(b->elem))
        return AUXpadre(elem, b->der);
    else
        return AUXpadre(elem, b->izq);
}

TBinario removerDeBinario(nat elem, TBinario b) {
    if (natInfo(b->elem) == elem) {
        
        if(b->der != NULL && b->izq != NULL) {
            TInfo maxIzq = mayor(b->izq);
            b->izq = removerMayor(b->izq);
            liberarInfo(b->elem);
            b->elem = maxIzq;
        } else {
            TBinario aux = b->izq == NULL ? (b->der == NULL ? NULL : b->der) : b->izq;
            liberarInfo(b->elem);
            delete b;
            return aux;
        }

    } else {
        // ubico al padre del nodo que contiene a elem
        TBinario padre = AUXpadre(elem, b);

        // me paro en el nodo que contiene a elem
        TBinario arElem = elem < natInfo(padre->elem) ? padre->izq : padre->der;

        if (arElem->der != NULL && arElem->izq != NULL) { //ambas ramas no nulas
            TInfo maxIzq = mayor(arElem->izq);
            arElem->izq = removerMayor(arElem->izq);
            liberarInfo(arElem->elem);
            arElem->elem = maxIzq;
        } else {
            TBinario aux = arElem->der == NULL ? (arElem->izq == NULL ? NULL : arElem->izq) : arElem->der;
            if (natInfo(padre->elem) > elem) {
                liberarInfo(padre->izq->elem);
                delete padre->izq;
                padre->izq = aux;
            } else {
                liberarInfo(padre->der->elem);
                delete padre->der;
                padre->der = aux;
            }
        }
    }
    return b;
}

void liberarBinario(TBinario b){
    if (b != NULL) {
        liberarBinario(b->izq);
        liberarBinario(b->der);
        liberarInfo(b->elem);
        delete b;
    }
}

bool esVacioBinario(TBinario b){
    return b == NULL;
}

static nat AUXabs(int a) {
    return a < 0 ? -a : a;
}

static nat AUXmax (nat a, nat b) {
    return a < b ? b : a;
}

static bool AUXavl(TBinario b, nat *profNodo) { 
    if (b == NULL)
        return true;
    else {
        nat *profI = new nat;
        nat *profD = new nat;
        *profI = *profD = 0;

        bool avlIzq = AUXavl(b->izq, profI);
        bool avlDer = AUXavl(b->der, profD);
        
        bool esAVL = (avlDer && avlIzq) && (AUXabs(*profD - *profI) < 2);
        *profNodo = 1 + AUXmax(*profD, *profI);

        delete profD;
        delete profI;        
        return esAVL;
    }
}

bool esAvl(TBinario b){
    nat * alt = new nat;
    *alt = 0;
    bool res = AUXavl(b, alt);
    delete alt;
    return res;
}

nat alturaBinario(TBinario b){
    if (b == NULL) 
        return 0;
    else
        return 1 + AUXmax(alturaBinario(b->der), alturaBinario(b->izq));
}

nat cantidadBinario(TBinario b) {
    if (b == NULL) 
        return 0;
    else
        return 1 + cantidadBinario(b->izq) + cantidadBinario(b->der);
}

static double AUXsumaUltimosPositivos(nat i, TBinario b, nat &contador) {
    if (b == NULL)
        return 0.0;
    else{
        double suma = i >= contador ? AUXsumaUltimosPositivos(i, b->der, contador) : 0.0;

        if (realInfo(b->elem) > 0)
            suma += i >= contador++ ? realInfo(b->elem) : 0.0;

        suma += i >= contador ?AUXsumaUltimosPositivos(i, b->izq, contador) : 0.0;
        return suma;
    }
}

double sumaUltimosPositivos(nat i, TBinario b){
    nat cont = 1;
    return AUXsumaUltimosPositivos(i, b, cont);
}

static void AUXlinealizacion(TBinario b, TCadena &cad) {
    if (b != NULL) {
        AUXlinealizacion(b->izq, cad);
        insertarAlFinal(copiaInfo(b->elem), cad);
        AUXlinealizacion(b->der, cad);
    }
}

TCadena linealizacion(TBinario b) {
    TCadena res = crearCadena();
    AUXlinealizacion(b, res);
    return res;
}

TBinario menores(double cota, TBinario b) {
    TBinario nuevo;
    if (b == NULL)
        nuevo = NULL;
    else {
        TBinario nIzq = menores(cota, b->izq);
        TBinario nDer = menores(cota, b->der);
        if (realInfo(b->elem) < cota) {
            nuevo = new _rep_binario;
            nuevo->elem = copiaInfo(b->elem);
            nuevo->izq = nIzq;
            nuevo->der = nDer;
        } else if (nIzq != NULL && nDer != NULL) {
            TInfo maxIzq = mayor(nIzq);
            nIzq = removerMayor(nIzq);
            nuevo = new _rep_binario;
            nuevo->izq = nIzq;
            nuevo->der = nDer;
            nuevo->elem = maxIzq;
        } else if (nIzq != NULL && nDer == NULL)
            nuevo = nIzq;
        else if (nIzq == NULL && nDer != NULL) 
            nuevo = nDer;
        else 
            nuevo = NULL;
    }
    return nuevo;
}

void AUXimprimirBinario(TBinario b, nat alt) {
    if (b != NULL) {
        AUXimprimirBinario(b->der, alt+1);
        char* frase = infoATexto(b->elem);
        for (nat i = 0; i < alt; i++) 
            printf("-");        
        printf("%s\n", frase);
        AUXimprimirBinario(b->izq, alt+1);
        delete[] frase;
    }
}

void imprimirBinario(TBinario b) {
    printf("\n");
    AUXimprimirBinario(b, 0);
    
}