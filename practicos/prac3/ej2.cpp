#include <cstddef>
#include <cstdio>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo *lista;

lista take(lista ptr, int i) {
    lista nueva = NULL;    // principio de la lista nueva
    lista ultimo = NULL;       // final de la lista nueva
 
    while (ptr != NULL && i > 1) {
        // primer caso
        if (nueva == NULL) {
            nueva = new nodo;
            nueva->elem = ptr->elem;
            nueva->sig = NULL;
            ultimo = nueva;
        } //resto
        else {
            ultimo->sig = new nodo;
            ultimo = ultimo->sig;
            ultimo->elem = ptr->elem;
            ultimo->sig = NULL;
        }
        ptr = ptr->sig;
        i--;
    }
    return nueva;
}

lista drop(int i, lista l) {
    lista ptr = l;
    lista nueva = NULL;
    lista ult = NULL;
    while (ptr != NULL && i > 0) {
        ptr = ptr->sig;
        i--;
    }
    while (ptr != NULL) {
        if (nueva == NULL) {
            nueva = new nodo;
            nueva->elem = ptr->elem;
            nueva->sig = NULL;
            ult = nueva;
        } else {
            ult->sig = new nodo;
            ult = ult->sig;
            ult->elem = ptr->elem;
            ult->sig = NULL;
        }
        ptr = ptr->sig;
    }
    return nueva;
}

lista mergeSort(lista l1, lista l2) {
    lista nueva = NULL;    // principio de la lista nueva
    lista ultimo = NULL;       // final de la lista nueva
 
    while (l1 != NULL && l2 != NULL) {
        // primer caso
        if (nueva == NULL) {
            nueva = new nodo;
            if (l1->elem <= l1->elem) {
                nueva->elem = l1->elem;
                l1 = l1->sig;
            } else {
                nueva->elem = l2->elem;
                l2 = l2->sig;
            }
            nueva->sig = NULL;
            ultimo = nueva;
        } //resto
        else {
            ultimo->sig = new nodo;
            ultimo = ultimo->sig;
            if (l1->elem <= l1->elem) {
                ultimo->elem = l1->elem;
                l1 = l1->sig;
            } else {
                ultimo->elem = l2->elem;
                l2 = l2->sig;
            }
            ultimo->sig = NULL;
        }
    }
    
    lista l3 = l1 == NULL ? l2 : l1;

    while (l3 != NULL) {
        // primer caso
        if (nueva == NULL) {
            nueva = new nodo;
            nueva->elem = l3->elem;    
            nueva->sig = NULL;
            ultimo = nueva;
        } //resto
        else {
            ultimo->sig = new nodo;
            ultimo = ultimo->sig;
            ultimo->elem = l3->elem;
            ultimo->sig = NULL;
        }
        l3 = l3->sig;      
    }
    return nueva;
}

lista concat (lista l1, lista l2) {

    lista nueva = NULL;    // principio de la lista nueva
    lista ultimo = NULL;       // final de la lista nueva

    while (l1 != NULL) {
        // primer caso
        if (nueva == NULL) {
            nueva = new nodo;
            nueva->elem = l1->elem;    
            nueva->sig = NULL;
            ultimo = nueva;
        } //resto
        else {
            ultimo->sig = new nodo;
            ultimo = ultimo->sig;
            ultimo->elem = l1->elem;
            ultimo->sig = NULL;
        }
        l1 = l1->sig == NULL ? l2: l1->sig;     
    }
    return nueva;
}

int main() {

}