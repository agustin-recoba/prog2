/* 5469187 */

#include "../include/colCadenas.h"
#include "../include/cadena.h"
#include "../include/usoTads.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _rep_colCadenas {
    TCadena *cadenas;
    nat tam;
};

TColCadenas crearColCadenas(nat M) {
    TColCadenas nueva = new _rep_colCadenas;
    nueva->cadenas = new TCadena[M];
    nueva->tam = M;
    for(nat i = 0; i < M; i++)
        nueva->cadenas[i] = crearCadena();
    
    return nueva;
}

TColCadenas insertarEnColCadenas(TInfo info, nat pos, TColCadenas col) {
    if (0 <= pos && pos < col->tam) {
        TCadena cad = col->cadenas[pos];
        TLocalizador loc = inicioCadena(cad);
        if (esLocalizador(loc))
            cad = insertarAntes(info, inicioCadena(cad), cad);
        else
            cad = insertarAlFinal(info, cad);
        col->cadenas[pos] = cad;
    }

    return col;
}

bool estaEnColCadenas(nat dato, nat pos, TColCadenas col) {
    if (0 <= pos && pos < col->tam)
        return pertenece(dato, col->cadenas[pos]);
    else
        return false;
}

TInfo infoEnColCadenas(nat dato, nat pos, TColCadenas col) {
    TCadena cad = col->cadenas[pos];
    TLocalizador locDato = siguienteClave(dato, inicioCadena(cad), cad);
    return infoCadena(locDato, cad);
}

TColCadenas removerDeColCadenas(nat dato, nat pos, TColCadenas col) {
    TCadena cad = col->cadenas[pos];
    TLocalizador locDato = siguienteClave(dato, inicioCadena(cad), cad);
    cad = removerDeCadena(locDato, cad);
    col->cadenas[pos] = cad;
    return col;
}

void liberarColCadenas(TColCadenas col) {
    for(nat i = 0; i < col->tam; i++)
        liberarCadena(col->cadenas[i]);
    delete[] col->cadenas;
    delete col;
}