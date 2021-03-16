#include "ej1/ej1.cpp"

#include "ej2/ej2.cpp"

#include "ej3/ej3.cpp"

Pila invertirPila(Pila p) {
    return crearPila();
}

bool mismosElementos(Pila p, Cola c) {
    p = invertirPila(p);
    while(!esVacia(p) && !esVacia(c) && frente(c) == cima(p)) {
        c = desencolar(c);
        p = desapilar(p);
    }
    return esVacia(p) && esVacia(c);
}
int main () {

}