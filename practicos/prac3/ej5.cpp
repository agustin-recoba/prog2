#include <cstddef>
#include <cstdio>

struct  nodo_doble {
    int  elem;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef  nodo_doble *lista;

