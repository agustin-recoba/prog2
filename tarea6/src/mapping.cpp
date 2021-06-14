/* 5469187 */

#include "../include/mapping.h"
#include "../include/colCadenas.h"

#include <stdio.h>
#include <stdlib.h>

struct _rep_mapping {
    TColCadenas colCads;
    nat M;
    nat asociaciones;
};

TMapping crearMap(nat M) {
    TMapping map = new _rep_mapping;
    map->colCads = crearColCadenas(M);
    map->M = M;
    map->asociaciones = 0;
    return map;
}

TMapping asociarEnMap(nat clave, double valor, TMapping map) {
    nat hash = clave % map->M;
    map->colCads = insertarEnColCadenas(crearInfo(clave, valor), hash, map->colCads);
    map->asociaciones++;
    return map;
}

TMapping desasociarEnMap(nat clave, TMapping map) {
    nat hash = clave % map->M;
    map->colCads = removerDeColCadenas(clave, hash, map->colCads);
    //bool apareceOtraVez = estaEnColCadenas(clave, hash, map->colCads);
    //if (!apareceOtraVez)
        map->asociaciones--;
    return map;
}

bool existeAsociacionEnMap(nat clave, TMapping map) {
    nat hash = clave % map->M;
    return estaEnColCadenas(clave, hash, map->colCads);
}

double valorEnMap(nat clave, TMapping map) {
    nat hash = clave % map->M;
    TInfo info = infoEnColCadenas(clave, hash, map->colCads);
    return realInfo(info);
}

bool estaLlenoMap(TMapping map) {
    return map->M == map->asociaciones;
}

void liberarMap(TMapping map) {
    liberarColCadenas(map->colCads);
    delete map;
}