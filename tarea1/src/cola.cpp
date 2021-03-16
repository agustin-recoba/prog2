/* 5469187 */

#include "../include/cola.h"

#include "../include/lista.h"
#include "../include/utils.h"

struct _rep_cola {
  TLista lst;
};

TCola crearCola()
{
  TCola nueva = new _rep_cola;  // pido memoria para la cola
  nueva->lst = crearLista();    // le asigno una lista limpia
  return nueva;
}

bool esVaciaCola(TCola cola)
{
  return longitud(cola->lst) == 0;  // es vacia solamente si la lista tambien lo es
}

TCola encolar(info_t nuevo, TCola cola)
{
  if (longitud(cola->lst) < MAX)    // si hay lugar en la lista
  {
    cola->lst = insertar(1, nuevo, cola->lst);  // coloco en el primer lugar
  }
  return cola;
}

info_t frente(TCola cola) 
{
  info_t t = infoLista(longitud(cola->lst), cola->lst);  // tomo el ultimo elemento de la lista
  return t;
}

TCola desencolar(TCola c)
{
  if (!esVaciaCola(c))  // si la lista no es vacía
  {
    c->lst = remover(longitud(c->lst),  c->lst); // elimino el ultimo elemento de la lista
  }
  return c;
}


