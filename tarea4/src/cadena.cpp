/* 5469187 */

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
  while (p != NULL && p->anterior != NULL) {
    p = p->anterior;
    liberarInfo(p->siguiente->dato);
    delete p->siguiente;
  }
  if (p != NULL) {
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
  return cad->final;
}

TInfo infoCadena(TLocalizador loc, TCadena cad) {
  return loc->dato;
}

TLocalizador siguiente(TLocalizador loc, TCadena cad) {
  return loc->siguiente;
}

TLocalizador anterior(TLocalizador loc, TCadena cad) {
  return loc->anterior;
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
  if (loc->anterior == NULL) {
    cad->inicio = nuevo;
  } else {
    loc->anterior->siguiente = nuevo;
  }
  loc->anterior = nuevo;
  return cad;
}

TCadena removerDeCadena(TLocalizador loc, TCadena cad) {
  if (loc->anterior != NULL) {
    loc->anterior->siguiente = loc->siguiente;
  } else {
    cad->inicio = loc->siguiente;
  }
  if (loc->siguiente != NULL) {
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
  while (p != NULL) {
    ArregloChars arr;
    arr = infoATexto(p->dato);
    printf("%s", arr);
    delete[] arr;
    p = siguiente(p, cad);
  }
  if (p == NULL)
    printf("\n");
  
}

TLocalizador kesimo(nat k, TCadena cad) {

  if (k == 0 || esVaciaCadena(cad)) 
    return NULL;

  TLocalizador p = cad->inicio;
  nat i = 1;

  while (p != NULL && i < k) {
    p = p->siguiente;
    i++;
  }
  return i == k ? p : NULL;
}

TCadena insertarSegmentoDespues(TCadena sgm, TLocalizador loc, TCadena cad) {
  if(!esVaciaCadena(sgm)) {
    if(esVaciaCadena(cad)) {
      cad->inicio = sgm->inicio;
      cad->final = sgm->final;
    } else {
      if(esFinalCadena(loc, cad)) {
        loc->siguiente = sgm->inicio;
        cad->final = sgm->final;
        sgm->inicio->anterior = loc;
      } else {
        sgm->final->siguiente = loc->siguiente;
        loc->siguiente->anterior = sgm->final;
        loc->siguiente = sgm->inicio;
        sgm->inicio->anterior = loc;
      }
    }
  }
  delete sgm;
  return cad;
}

TCadena copiarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {
  TCadena nueva = new _rep_cadena;
  if(esVaciaCadena(cad)) {
    nueva->inicio = NULL;
    nueva->final = NULL;
    return nueva;
  }

  nueva->inicio = new nodoCadena;
  TLocalizador aux = nueva->inicio;
  aux->anterior = NULL;
  aux->dato = copiaInfo(infoCadena(desde, cad));
  desde = desde->siguiente;

  while (desde != NULL && desde->anterior != hasta) {
    aux->siguiente = new nodoCadena;
    aux->siguiente->anterior = aux;
    aux = aux->siguiente;
    aux->dato = copiaInfo(infoCadena(desde, cad));
    desde = desde->siguiente;
  }
  aux->siguiente = NULL;
  nueva->final = aux;
  
  return nueva;
}

TCadena borrarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {
  if (!esVaciaCadena(cad)) {
    //enlazar
    if(esInicioCadena(desde, cad) && esFinalCadena(hasta, cad)) {
      cad->inicio = NULL;
      cad->final = NULL;
    } else if (esInicioCadena(desde, cad)) {
      cad->inicio = hasta->siguiente;
      cad->inicio->anterior = NULL;
    } else if (esFinalCadena(hasta, cad)) {
      cad->final = desde->anterior;
      cad->final->siguiente = NULL;
    } else {
      desde->anterior->siguiente = hasta->siguiente;
      hasta->siguiente->anterior = desde->anterior;
    }
    //liberar
    desde->anterior = NULL;
    hasta->siguiente = NULL;
    TCadena aux = new _rep_cadena;
    aux->inicio = desde;
    aux->final = hasta;
    liberarCadena(aux);
  }
  return cad;
}

TCadena cambiarEnCadena(TInfo i, TLocalizador loc, TCadena cad) {
  loc->dato = i;
  return cad;
}

TCadena intercambiar(TLocalizador loc1, TLocalizador loc2, TCadena cad) {
  TInfo aux = loc1->dato;
  loc1->dato = loc2->dato;
  loc2->dato = aux;
  return cad;
}

bool localizadorEnCadena(TLocalizador loc, TCadena cad) {
  TLocalizador p = cad->inicio;
  while (p != NULL && p != loc) {
    p = p->siguiente;
  }
  return p != NULL && p == loc;
}

bool precedeEnCadena(TLocalizador loc1, TLocalizador loc2, TCadena cad) {
  if(esVaciaCadena(cad) || loc2 == NULL || loc1 == NULL) 
    return false;
  else if (loc1 == loc2 && localizadorEnCadena(loc1, cad))
    return true;
  while (loc1 != NULL && loc1 != loc2) {
    loc1 = loc1->siguiente;
  }
  return loc1 == loc2;
}

TLocalizador siguienteClave(nat clave, TLocalizador loc, TCadena cad) {
  if (esVaciaCadena(cad)) {
    return NULL;
  } 
  while(loc != NULL && natInfo(loc->dato) != clave)
    loc = loc->siguiente;
  
  return loc;
}

TLocalizador anteriorClave(nat clave, TLocalizador loc, TCadena cad) {
  if (esVaciaCadena(cad)) {
    return NULL;
  } 
  while(loc != NULL && natInfo(loc->dato) != clave)
    loc = loc->anterior;
  
  return loc;
}

TLocalizador menorEnCadena(TLocalizador loc, TCadena cad) {
  nat min = natInfo(loc->dato);
  TLocalizador pMin = loc;
  loc = loc->siguiente;
  while(loc != NULL) {
    if (natInfo(loc->dato) < min) {
      min = natInfo(loc->dato);
      pMin = loc;
    }
    loc = loc->siguiente;
  }
  return pMin;
}
