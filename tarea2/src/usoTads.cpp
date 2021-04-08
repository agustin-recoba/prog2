/* 5469187 */

#include "../include/usoTads.h"

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