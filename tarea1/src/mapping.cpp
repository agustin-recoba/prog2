/* 5469187 */

#include "../include/mapping.h"

#include "../include/lista.h"
#include "../include/utils.h"

struct _rep_mapping {
  TLista lst;
};

TMapping crearMapping()
{
  TMapping nuevo = new _rep_mapping;
  nuevo->lst = crearLista();
  return nuevo;
}

TMapping asociar(nat clave, double valor, TMapping map)
{
  if (longitud(map->lst) < MAX && !esClave(clave, map) ) // si la lista no esta llena y "clave" no es clave
  {
    info_t nuevo;             
    nuevo.natural = clave;
    nuevo.real = valor;
    map->lst = insertar(longitud(map->lst) + 1, nuevo, map->lst); // agrego el par (clave, valor) en la ultima pos. de la lista
  }
  return map;
}

bool esClave(nat clave, TMapping map)
{
  return posNat(clave, map->lst) != 0;  // por def. de posNat, si clave no pertenece a la lista, se devuelve 0
}

double valor(nat clave, TMapping map)
{
  nat indice = posNat(clave, map->lst);             // pido posicion de clave dentro de la lista
  double val = infoLista(indice, map->lst).real;    // y a esa posicion le pido la parte real de info_t
  return val;
}

TMapping desasociar(nat clave, TMapping map)
{
  nat indice = posNat(clave, map->lst);     // pido posicion de clave dentro de la lista
  if (indice != 0)    // si es clave
  {    
    map->lst = remover(indice, map->lst);
  }
  return map;
}