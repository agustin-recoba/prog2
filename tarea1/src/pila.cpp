/* 5469187 */

#include "../include/pila.h"

#include "../include/lista.h"
#include "../include/utils.h"

struct _rep_pila {
  TLista lst;
};

TPila crearPila()
{
    TPila res = new _rep_pila;   // pido memoria para una pila nueva
    (*res).lst = crearLista();   // le asigno una lista limpia
    return res;
}

bool esVaciaPila(TPila pila)
{
    return longitud(pila->lst) == 0;   // es vacia solo si la lista no contiene elementos
}

TPila apilar(info_t nuevo, TPila pila)
{
    if (longitud(pila->lst) < MAX)    // apilo solo si la lista no esta llena
    {
        nat n = longitud(pila->lst) + 1; 
        pila->lst = insertar(n, nuevo, pila->lst);  // inserto en la posicion tope+1
    }
    return pila;
}

info_t cima(TPila pila)
{
    return infoLista(longitud(pila->lst), pila->lst);  // tomo el ultimo elemento, la pre-condicion se encarga de que la lista no este vacia
}

TPila desapilar(TPila pila)
{
    pila->lst = remover(longitud(pila->lst), pila->lst);  // saco el ultimo elemento, la pre-condicion se encarga de que la lista no este vacia
    return pila;
}