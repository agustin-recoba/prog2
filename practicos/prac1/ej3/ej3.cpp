#include "Lista.cpp"

Lista descartar (unsigned int i, Lista l) {
    Lista nueva = crearLista();
    int j = 1;
    while (estaDefinida(i + j, l)) {
        nueva = insertar(obtener(i + j, l), j, nueva);
        j++;
    }
    return nueva;
}

unsigned int largo (Lista l) {
    int i = 1;
    while (estaDefinida(i, l)) {
        i++;
    }
    return i - 1;
}

Lista insertarFinal (unsigned int x, Lista l) {
    return insertar(x, largo(l) + 1, l);
}

Lista unirListas (Lista p, Lista l) {
    Lista nueva = crearLista();
    int j = 1;
    while (estaDefinida(j, p)) {
        nueva = insertar(obtener(j, p), j, nueva);
        j++;
    }
    int i = j;
    j = 1;
    while (estaDefinida(j, l)) {
        nueva = insertar(obtener(j, l), j + i, nueva);
        j++;
    }
    return nueva;
}

Lista invertir (Lista l) {
    Lista nueva = crearLista();
    Lista aux = l;
    int i = 1;
    while (estaDefinida(1, aux)) {
        nueva = insertar(obtener(1, aux), 1, nueva);
        aux = descartar(1, aux);
    }
    return nueva;
}
