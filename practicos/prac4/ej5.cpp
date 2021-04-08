#include <cstddef>

typedef unsigned int uint;

struct nodoAG {
    int dato;
    nodoAG *pH, *sH;
};
typedef nodoAG* AG;

struct nodoLista {
    int elem;
    nodoLista * sig;
};
typedef nodoLista * Lista;

AG arbolHoja(int a) {
    AG ar = new nodoAG;
    ar->dato = a;
    ar->pH = ar->sH = NULL;
    return ar;
}

/* Precondición: h no pertenece al arbol */
void insertar(AG &ar, int p, int h) {
    if (ar != NULL) {
        if (ar->dato == p) {
            AG aux = new nodoAG;
            aux->dato = h;
            aux->pH = NULL;
            aux->sH = ar->pH;
            ar->pH = aux;
        } else {
            insertar(ar->pH, p, h);
            insertar(ar->sH, p, h);
        }
    }
}

bool pertenece(AG ar, int x) {
    if (ar == NULL)
        return false;
    else if (ar->dato == x)
        return true;
    else
        return pertenece(ar->pH, x) || pertenece(ar->sH, x);
}

AG buscar (int x, AG ar) {
    if(ar == NULL)
        return NULL;
    else if (ar->dato == x)
        return ar;
    else {
        AG buscarHijos = buscar(x, ar->pH);
        AG buscarHermanos = buscar(x, ar->sH);
        return buscarHijos == NULL ? buscarHermanos : buscarHijos;
    }
}

void insertarConBuscar (AG &ar, int p, int h) {
    AG nodoP = buscar(p, ar);
    AG nodoH = buscar(h, ar);

    if (nodoP != NULL && nodoH == NULL) {
        AG nodoH = new nodoAG;
        nodoH->dato = p;
        nodoH->pH = NULL;
        nodoH->sH = nodoH->pH;
        nodoH->pH = nodoP;
    }
}

bool esArbolHoja (AG ar) {
    return (ar != NULL) && (ar->pH == NULL);
}

AG buscarPadre(AG ar, int x) {
    if (ar == NULL) 
        return NULL;
    else if (ar->pH != NULL && ar->pH->dato == x)
        return ar;
    else {
        AG buscarEnHijos = buscarPadre(ar->pH, x);
        AG buscarEnHermanos = buscarPadre(ar->sH, x);
        return buscarEnHijos == NULL ? buscarEnHermanos : buscarEnHijos;
    }
}

AG buscarAnteriorHermano(AG ar, int x) {
    if (ar == NULL) 
        return NULL;
    else if (ar->sH != NULL && ar->sH->dato == x)
        return ar;
    else {
        AG buscarEnHijos = buscarAnteriorHermano(ar->pH, x);
        AG buscarEnHermanos = buscarAnteriorHermano(ar->sH, x);
        return buscarEnHijos == NULL ? buscarEnHermanos : buscarEnHijos;
    }
}

void borrar(AG &ar, int x) {
    AG nodoPardreX = buscarPadre(ar, x);
    AG nodoHermanoX = buscarAnteriorHermano(ar, x);

    if(nodoPardreX != NULL && nodoPardreX->pH->pH == NULL) {
        delete nodoPardreX->pH;
        nodoPardreX->pH = NULL;
    } else if (nodoHermanoX != NULL && nodoHermanoX->sH->pH == NULL) {
        delete nodoHermanoX->sH;
        nodoHermanoX->sH = NULL;
    }
}

void liberarArbol(AG &ar) {
    if (ar != NULL) {
        liberarArbol(ar->pH);
        liberarArbol(ar->sH);
        delete ar;
    } 
}

void borrarSub(AG ar, int x) {
    AG nodoPardreX = buscarPadre(ar, x);
    AG nodoHermanoX = buscarAnteriorHermano(ar, x);

    if(nodoPardreX != NULL && nodoPardreX->pH->pH == NULL) {
        liberarArbol(nodoPardreX->pH);
        nodoPardreX->pH = NULL;
    } else if (nodoHermanoX != NULL && nodoHermanoX->sH->pH == NULL) {
        liberarArbol(nodoHermanoX->sH);
        nodoHermanoX->sH = NULL;
    }
}

AG copiaParcialAux(AG ar, int k, int i) {
    if(ar == NULL || k < i) 
        return NULL;
    else {
        if (i <= k) {
            AG aux = arbolHoja(ar->dato);
            aux->pH = copiaParcialAux(ar->pH, k, i);
            aux->sH = copiaParcialAux(ar->pH, k, i+1);
            return aux;            
        }
    } 
}

AG copiaParcial (AG ar, unsigned int k) {
    return copiaParcialAux(ar, k, 1);
}

bool esPrefijo (Lista l, AG ar){
    if (l == NULL) 
        return true;
    else if (ar != NULL){
        return (l->elem == ar->dato) && 
                (esPrefijo(l->sig, ar->pH) || esPrefijo(l->sig, ar->sH));
    } else
        return false;
}

