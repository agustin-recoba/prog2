#include "Cola.cpp"

unsigned int maximoCola (Cola c) {
    int max = -1;
    Cola aux = crearCola();
    while (!esVacia(c)) {
        if (frente(c) > max) {
            max = frente(c);
        }
        aux = encolar(frente(c), aux);
        c = desencolar(c);
    }
    while (!esVacia(aux)) {
        c = encolar(frente(aux), c);
        aux = desencolar(aux);
    }
    return max;
}

bool estaOdenada (Cola c) {
    Cola aux = crearCola();
    int prev = frente(c);
    aux = encolar(frente(c), aux);
    c = desencolar(c);

    while (!esVacia(c) && frente(c) <= prev) {
        prev = frente(c);
        aux = encolar(frente(c), aux);
        c = desencolar(c);
    }
    bool ord = esVacia(c);

    while (!esVacia(aux)) {
        c = encolar(frente(aux), c);
        aux = desencolar(aux);
    }
    return ord;
}

Cola cambiarXY (unsigned int x, unsigned int y, Cola c) {
    Cola aux = crearCola();
    while (!esVacia(c)) {
        if (frente(c) == x) {
            c = desencolar(c);
            c = encolar(y, c);
        }
        aux = encolar(frente(c), aux);
        c = desencolar(c);
    }
    while (!esVacia(aux)) {
        c = encolar(frente(aux), c);
        aux = desencolar(aux);
    }
    return c;
}

Cola mergeColas (Cola c1, Cola c2) {
    Cola ret = crearCola();
    Cola aux1 = crearCola();
    Cola aux2 = crearCola();
    while (!esVacia(c1) && !esVacia(c2)) {
        if (frente(c1) >= frente(c2)) {
            ret = encolar(frente(c1), ret);
            aux1 = encolar(frente(c1), aux1);
            c1 = desencolar(c1);
        } else {
            ret = encolar(frente(c2), ret);
            aux2 = encolar(frente(c2), aux2);
            c2 = desencolar(c2);
        }
    }
    while (!esVacia(c1)) {
        ret = encolar(frente(c1), ret);
        aux1 = encolar(frente(c1), aux1);
        c1 = desencolar(c1);
    }
    while (!esVacia(c2)){
        ret = encolar(frente(c2), ret);
        aux2 = encolar(frente(c2), aux2);
        c2 = desencolar(c2);
    }

    while (!esVacia(aux1)) {
        c1 = encolar(frente(aux1), c1);
        aux1 = desencolar(aux1);
        
    }
    while (!esVacia(aux2)){
        c2 = encolar(frente(aux2), c2);
        aux2 = desencolar(aux2);
    }
    return ret;
}

