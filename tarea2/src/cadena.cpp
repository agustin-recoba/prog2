
#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct nodoCadena {
  TInfo dato;
  TLocalizador anterior;
  TLocalizador siguiente;
};

struct _rep_cadena {
  TLocalizador inicio;
  TLocalizador final;
};

bool esLocalizador(TLocalizador loc) { return loc != NULL; }

TCadena crearCadena() {
  TCadena res = new _rep_cadena;
  res->inicio = res->final = NULL;
  return res;
}

void liberarCadena(TCadena cad) {
}

bool esVaciaCadena(TCadena cad) {
}

TLocalizador inicioCadena(TCadena cad) {
  /*
  // versión que sigue la especificación
    TLocalizador res;
    if (esVaciaCadena(cad)) {
      res = NULL;
    } else {
      res = cad->inicio;
    }
    return res;
  */
  
  // versión conociendo la implementación:
  // esVaciaCadena(cad) => cad->inicio == NUL
  assert(!esVaciaCadena(cad) || cad->inicio == NULL);
  return cad->inicio;
}

TLocalizador finalCadena(TCadena cad) {
  return NULL;
}

TInfo infoCadena(TLocalizador loc, TCadena cad) {
  return NULL;
}

TLocalizador siguiente(TLocalizador loc, TCadena cad) {
  return NULL;
}

TLocalizador anterior(TLocalizador loc, TCadena cad) {
  return NULL;
}

bool esFinalCadena(TLocalizador loc, TCadena cad) {
  return false;
}

bool esInicioCadena(TLocalizador loc, TCadena cad) {
  return false;
}

TCadena insertarAlFinal(TInfo i, TCadena cad) {
  return NULL;
}

TCadena insertarAntes(TInfo i, TLocalizador loc, TCadena cad) {
  return NULL;
}

TCadena removerDeCadena(TLocalizador loc, TCadena cad) {
  return NULL;
}

void imprimirCadena(TCadena cad) {
}

TLocalizador kesimo(nat k, TCadena cad) {
  return NULL;
}

TCadena insertarSegmentoDespues(TCadena sgm, TLocalizador loc, TCadena cad) {
  return NULL;
}

TCadena copiarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {
  return NULL;
}

TCadena borrarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {
  return NULL;
}

TCadena cambiarEnCadena(TInfo i, TLocalizador loc, TCadena cad) {
  return NULL;
}

TCadena intercambiar(TLocalizador loc1, TLocalizador loc2, TCadena cad) {
  return NULL;
}

bool localizadorEnCadena(TLocalizador loc, TCadena cad) {
  return false;
}

bool precedeEnCadena(TLocalizador loc1, TLocalizador loc2, TCadena cad) {
  return false;
}

TLocalizador siguienteClave(nat clave, TLocalizador loc, TCadena cad) {
  return NULL;
}

TLocalizador anteriorClave(nat clave, TLocalizador loc, TCadena cad) {
  return NULL;
}

TLocalizador menorEnCadena(TLocalizador loc, TCadena cad) {
  return NULL;
}
