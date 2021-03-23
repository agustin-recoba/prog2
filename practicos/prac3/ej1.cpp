#include <cstddef>
#include <cstdio>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo *lista;

int last(lista l) {
    while(l->sig != NULL) {
        l = l->sig;
    }
    return l->elem;
}

double average(lista l) {
    int i = 0;
    int sum = 0;
    while(l->sig != NULL) {
        i++;
        sum += l->elem;
        l = l->sig;
    }
    return (sum*1.0)/i;
}

void insOrd(lista &l, int x) {
    lista p;
    if (l == NULL || l->elem >= x) {
        p = new nodo;
        p->sig = NULL;
        p->elem = x;
    } else {
        p = l;
        lista p2 = p->sig;
        while (p2 != NULL && p2->elem <= x) {
            p = p2;
            p2 = p2->sig;
        } 
        p2 = new nodo;
        p2->sig = p->sig;
        p2->elem = x;
        p->sig = p2;
    }
}

void snoc(lista &l, int x) {
    lista p;
    if (l == NULL) {
        p = new nodo;
        p->sig = NULL;
        p->elem = x;
    } else {
        p = l;
        lista p2 = p->sig;
        while (p2 != NULL) {
            p = p2;
            p2 = p2->sig;
        } 
        p2 = new nodo;
        p2->sig = p->sig;
        p2->elem = x;
        p->sig = p2;
    }
}

void removeAll(lista &l, int x) {
    if (l != NULL) {
        lista ant = l;
        lista lPos = ant->sig;
        while (lPos != NULL) {
            if (lPos->elem == x) {
                ant->sig = lPos->sig;
                delete lPos;
                lPos = ant->sig;
            } else {
                ant = lPos;
                lPos = lPos->sig;
            }
        }
    }
}

bool isIncluded(lista l, lista p) {
    if (l == NULL)
        return true;
    else if (p == NULL)
        return false;
    lista l2 = l;
    lista p2 = p;
    while (p2 != NULL)
    {
        if (p2->elem == l2->elem) {
            p = p2;
            while (p2 != NULL && l2 != NULL && p2->elem == l2->elem) {
                p2 = p2->sig;
                l2 = l2->sig;
            }
            if (p2 == NULL && l2 == NULL)
                return true;
            p2 = p;
            l2 = l;
        }
        p2 = p2->sig; 
    }
    return false;
}

int main () {
}