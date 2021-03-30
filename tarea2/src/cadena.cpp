
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

bool esLocalizador(TLocalizador loc) { 
  return loc != NULL; 
}

TCadena crearCadena() {
  TCadena res = new _rep_cadena;
  res->inicio = NULL;
  res->final = NULL;
  return res;
}

void liberarCadena(TCadena cad) {
  TLocalizador p = cad->final;
  while (esLocalizador(p) && esLocalizador(p->anterior)) {
    p = p->anterior;
    liberarInfo(p->siguiente->dato);
    delete p->siguiente;
  }
  if (esLocalizador(p)) {
    liberarInfo(p->dato);
    delete p;
  }
  delete cad;
}

bool esVaciaCadena(TCadena cad) {
  return cad->inicio == NULL;
}

TLocalizador inicioCadena(TCadena cad) {
  return cad->inicio;
}

TLocalizador finalCadena(TCadena cad) {
  return esVaciaCadena(cad) ? NULL : cad->final;
}

TInfo infoCadena(TLocalizador loc, TCadena cad) {
  return loc->dato;
}

TLocalizador siguiente(TLocalizador loc, TCadena cad) {
  return esFinalCadena(loc, cad) ? NULL : loc->siguiente;
}

TLocalizador anterior(TLocalizador loc, TCadena cad) {
  return esInicioCadena(loc, cad) ? NULL : loc->anterior;
}

bool esFinalCadena(TLocalizador loc, TCadena cad) {
  return esVaciaCadena(cad) ? false : cad->final == loc;
}

bool esInicioCadena(TLocalizador loc, TCadena cad) {
  return esVaciaCadena(cad) ? false : cad->inicio == loc;
}

TCadena insertarAlFinal(TInfo i, TCadena cad) {
  TLocalizador nuevo = new nodoCadena;
  nuevo->dato = i;
  nuevo->siguiente = NULL;
  if(esVaciaCadena(cad)) {
    cad->inicio = nuevo;
    cad->final = nuevo;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
  } else {
    nuevo->anterior = cad->final;
    cad->final = nuevo;
    nuevo->anterior->siguiente = nuevo;
  }
  return cad;
}

TCadena insertarAntes(TInfo i, TLocalizador loc, TCadena cad) {
  TLocalizador nuevo = new nodoCadena;
  nuevo->dato = i;
  nuevo->siguiente = loc;
  nuevo->anterior = loc->anterior;
  if (!esLocalizador(loc->anterior)) {
    cad->inicio = nuevo;
  } else {
    loc->anterior->siguiente = nuevo;
  }
  loc->anterior = nuevo;
  return cad;
}

TCadena removerDeCadena(TLocalizador loc, TCadena cad) {
  if (esLocalizador(loc->anterior)) {
    loc->anterior->siguiente = loc->siguiente;
  } else {
    cad->inicio = loc->siguiente;
  }
  if (esLocalizador(loc->siguiente)) {
    loc->siguiente->anterior = loc->anterior;
  } else {
    cad->final = loc->anterior;
  }
  liberarInfo(loc->dato);
  delete loc;
  return cad;
}

void imprimirCadena(TCadena cad) {
  TLocalizador p = cad->inicio;
  while (esLocalizador(p)) {
    printf("%s", infoATexto(n));
    p = p->siguiente;
  }
  if (!esLocalizador(p))
    printf("\n");
  
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
  return true;
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
