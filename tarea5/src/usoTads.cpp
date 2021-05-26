/* 5469187 */

#include "../include/usoTads.h"
#include "../include/colaBinarios.h"
#include "../include/pila.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

TConjunto interseccionDeConjuntos(TConjunto c1, TConjunto c2) {
    return c1;
}

nat cantidadEnIterador(TIterador it) {
    it = reiniciarIterador(it);
    int cont = 0;
    while(estaDefinidaActual(it)) {
        cont++;
        it = avanzarIterador(it);
    }

    return cont;
}

TIterador enAlguno(TIterador a, TIterador b) {
    
    TIterador nuevo = crearIterador();
    a = reiniciarIterador(a);
    b = reiniciarIterador(b);

    int actNuevo = -1;

    while (estaDefinidaActual(a) && estaDefinidaActual(b)) {
        int actA = actualEnIterador(a);
        int actB = actualEnIterador(b);
        if (actA == actNuevo)
            a = avanzarIterador(a);
        else if (actB == actNuevo)
            b = avanzarIterador(b);
        else if (actA < actB) {
            nuevo = agregarAIterador(actA, nuevo);
            actNuevo = actA;
            a = avanzarIterador(a);
        } else if (actB < actA) {
            nuevo = agregarAIterador(actB, nuevo);
            actNuevo = actB;
            b = avanzarIterador(b);
        } else {
            nuevo = agregarAIterador(actA, nuevo);
            actNuevo = actA;
            a = avanzarIterador(a);
            b = avanzarIterador(b);
        }
    }

    bool primero = true;

    while(estaDefinidaActual(a)) {
        int actA = actualEnIterador(a);
        if (primero && actA == actNuevo)
            primero = false;
        else if (primero) {
            nuevo = agregarAIterador(actA, nuevo);
            primero = false;
        } else 
            nuevo = agregarAIterador(actA, nuevo);
        a = avanzarIterador(a);
    }

    while(estaDefinidaActual(b)) {
        int actB = actualEnIterador(b);
        if (primero && actB == actNuevo)
            primero = false;
        else if (primero) {
            nuevo = agregarAIterador(actB, nuevo);
            primero = false;
        } else 
            nuevo = agregarAIterador(actB, nuevo);
        b = avanzarIterador(b);
    }
    
    return nuevo;

}

TIterador soloEnA(TIterador a, TIterador b) {
    TIterador nuevo = crearIterador();
    a = reiniciarIterador(a);
    b = reiniciarIterador(b);


    while (estaDefinidaActual(a) && estaDefinidaActual(b)) {
        int actA = actualEnIterador(a);
        int actB = actualEnIterador(b);
        if (actA < actB) {
            nuevo = agregarAIterador(actA, nuevo);
            a = avanzarIterador(a);
        } else if (actB < actA) {
            b = avanzarIterador(b);
        } else {
            a = avanzarIterador(a);
            b = avanzarIterador(b);
        }
    }

    while(estaDefinidaActual(a)) {
        int actA = actualEnIterador(a);
        nuevo = agregarAIterador(actA, nuevo);
        a = avanzarIterador(a);
    }

    
    return nuevo;
}

TIterador recorridaPorNiveles(TBinario b) {
    TPila pila = crearPila(cantidadBinario(b)*2 + 1); //cantidad de nodos + separadores maxima, en caso de arbol degenerado

    TColaBinarios colaActual = crearColaBinarios();
    TColaBinarios colaSig = crearColaBinarios();

    if (b != NULL)
        colaActual = encolar(b, colaActual);
    while (!estaVaciaColaBinarios(colaActual)) { // sale cuando la colaActual y colaSig estan vacias
        TBinario nodoActual = frente(colaActual);
        colaActual = desencolar(colaActual);
        pila = apilar(natInfo(raiz(nodoActual)), pila);

        if (derecho(nodoActual) != NULL)
            colaSig = encolar(derecho(nodoActual), colaSig);
        if (izquierdo(nodoActual) != NULL)
            colaSig = encolar(izquierdo(nodoActual), colaSig);
        
        if (estaVaciaColaBinarios(colaActual)) {  //colaActual queda vacia cada vez que se termina un nivel
            if (!estaVaciaColaBinarios(colaSig))  //agrego separador cada vez que termino un nivel, excepto en el ultimo
                pila = apilar(UINT_MAX, pila);
            TColaBinarios swap = colaSig;
            colaSig = colaActual;
            colaActual = swap;
        }

    }

    liberarColaBinarios(colaActual);
    liberarColaBinarios(colaSig);
    
    
    TIterador nuevo = crearIterador();

    while (!estaVaciaPila(pila)) {
        nat porAgre = cima(pila);
        nuevo = agregarAIterador(porAgre, nuevo);
        pila = desapilar(pila);
    }
    liberarPila(pila);

    return nuevo;
}

static void AUXnivelEnBinario(nat l, TBinario b, nat act, TCadena &cad) {
    if (b != NULL) {
        if (l == act) {
            cad = insertarAlFinal(copiaInfo(raiz(b)), cad);
        } else if (l > act) {
            AUXnivelEnBinario(l, izquierdo(b), act+1, cad);
            AUXnivelEnBinario(l, derecho(b), act+1, cad);
        }
    }
}

TCadena nivelEnBinario(nat l, TBinario b){
    TCadena cad = crearCadena();
    AUXnivelEnBinario(l, b, 1, cad);
    return cad;
}

static bool AUXesCamino(TCadena cad, TLocalizador loc, TBinario b) {
    if (loc == NULL && b == NULL)
        return true;
    else if (loc != NULL && b != NULL) {
        nat list = natInfo(infoCadena(loc, cad));
        nat arr = natInfo(raiz(b));
        if (arr == list) {
            if (izquierdo(b) == NULL)
                return AUXesCamino(cad, siguiente(loc, cad), derecho(b));
            else if (derecho(b) == NULL)
                return AUXesCamino(cad, siguiente(loc, cad), izquierdo(b));
            else return AUXesCamino(cad, siguiente(loc, cad), derecho(b)) || AUXesCamino(cad, siguiente(loc, cad), izquierdo(b));
        } else
            return false;
    } else 
        return false;
}

bool esCamino(TCadena cad, TBinario b) {
    return (cad == NULL && b == NULL) || AUXesCamino(cad, inicioCadena(cad), b);
}

bool pertenece(nat elem, TCadena cad) {
    return esLocalizador(siguienteClave(elem, inicioCadena(cad), cad));
}

nat longitud(TCadena cad) {
    nat largo = 0;
    TLocalizador p = inicioCadena(cad);
    while(esLocalizador(p)) {
        largo++;
        p = siguiente(p, cad);
    }
    return largo;
}

bool estaOrdenadaPorNaturales(TCadena cad) {
    if (esVaciaCadena(cad))
        return true;
    TLocalizador p = inicioCadena(cad);
    nat ant = natInfo(infoCadena(p, cad));
    p = siguiente(p, cad);

    while(esLocalizador(p) && natInfo(infoCadena(p, cad)) >= ant) {
        ant = natInfo(infoCadena(p, cad));
        p = siguiente(p, cad);
    }
    return !esLocalizador(p);
}

bool hayNatsRepetidos(TCadena cad) {
    // Cadena vacia o unitaria:
    if (esVaciaCadena(cad) || inicioCadena(cad) == finalCadena(cad))
        return false;

    TLocalizador p = inicioCadena(cad);
    bool encontrado = false;
    while (esLocalizador(p) && esLocalizador(siguiente(p, cad)) && !encontrado) {
        nat num = natInfo(infoCadena(p,cad));
        TLocalizador r = siguiente(p, cad);
        
        while (esLocalizador(r) && !encontrado) {
            encontrado = natInfo(infoCadena(r,cad)) == num;
            r = siguiente(r, cad);
        }
        p = siguiente(p, cad);
    }
    return encontrado;
}

bool sonIgualesCadena(TCadena c1, TCadena c2) {
    TLocalizador p1 = inicioCadena(c1);
    TLocalizador p2 = inicioCadena(c2);
    while (esLocalizador(p1) && esLocalizador(p2) && sonIgualesInfo(infoCadena(p1, c1), infoCadena(p2, c2))) {
        p1 = siguiente(p1, c1);
        p2 = siguiente(p2, c2);
    }
    return !esLocalizador(p1) && !esLocalizador(p2);
}

TCadena concatenar(TCadena c1, TCadena c2) {
    TCadena nueva = copiarSegmento(inicioCadena(c1), finalCadena(c1), c1);
    TLocalizador p = inicioCadena(c2);
    while (esLocalizador(p)) {
        nueva = insertarAlFinal(copiaInfo(infoCadena(p, c2)), nueva);
        p = siguiente(p, c2);
    }
    return nueva;
}

TCadena ordenar(TCadena cad) {
    if(!esVaciaCadena(cad)) {
        TLocalizador p = inicioCadena(cad);
        while (esLocalizador(p)) {
            TLocalizador min = menorEnCadena(p, cad);
            cad = intercambiar(p, min, cad);
            p = siguiente(p, cad);
        }
    }
    return cad;
}

TCadena cambiarTodos(nat original, nat nuevo, TCadena cad) {
    TLocalizador p = inicioCadena(cad);
    while (esLocalizador(p)) {
        if(natInfo(infoCadena(p, cad)) == original) {
            TInfo inf = crearInfo(nuevo, realInfo(infoCadena(p, cad)));
            TInfo aux = infoCadena(p, cad);
            liberarInfo(aux);
            cambiarEnCadena(inf, p, cad);
        }
        p = siguiente(p, cad);
    }
    return cad;
}

TCadena subCadena(nat menor, nat mayor, TCadena cad) {
    TLocalizador desde = siguienteClave(menor, inicioCadena(cad), cad);
    TLocalizador hasta = anteriorClave(mayor, finalCadena(cad), cad);
    TCadena nueva = copiarSegmento(desde, hasta, cad);
    return nueva;
}