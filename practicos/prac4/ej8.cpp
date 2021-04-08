#include <cstddef>

struct nodoArchivo{
    char *nombreArchivo;
    char *contenidoArchivo;
    nodoArchivo * sig;
};
typedef nodoArchivo * Archivos;

struct nodoDirectorio{
    char *nombreDirectorio;
    Archivos listaArchivos;
    nodoDirectorio *pH, *sH;
};
typedef nodoDirectorio * Directorios;


/* Dada una lista de enteros y un árbol general de enteros, retorna true si
y sólo si la lista es un prefijo de algún camino del árbol general, comenzando 
desde la raíz. La lista vacía es prefijo de cualquier camino (incluso del 
camino vacío, si el árbol es vacío). No se permite usar funciones o procedimientos 
auxiliares en este ejercicio. Utilice la definición de lista presentada en 
el ejercicio 2. */

bool strEq(char * str1, char * str2);

void borrar(Directorios &d, char *nomDir) {
    if (d != NULL) {
        if (d->sH != NULL && d->sH->pH == NULL && strEq(d->sH->nombreDirectorio, nomDir)) { 
            // (si siguiente hermano de d es el directorio buscado)
            Directorios aBorrar = d->sH;
            // borro lista de archivos:
            Archivos archBorrar = aBorrar->listaArchivos;
            bool todoBorrado = archBorrar == NULL;
            while (!todoBorrado) {
                Archivos aux = archBorrar;
                if (aux->sig != NULL) {
                    delete [] aux->contenidoArchivo;
                    delete [] aux->nombreArchivo;
                    delete aux;
                    todoBorrado = true;
                } else {
                    while (aux->sig->sig != NULL) {
                        aux = aux->sig;
                    }
                    delete [] aux->sig->contenidoArchivo;
                    delete [] aux->sig->nombreArchivo;
                    delete aux->sig;
                    aux->sig = NULL;
                }
            }
            // reasigno a d->sH:
            d->sH = aBorrar->sH;

            // libero memoria aBorrar:
            delete [] aBorrar->nombreDirectorio;
            delete aBorrar;

        } else if (d->pH != NULL && d->pH->pH == NULL && strEq(d->pH->nombreDirectorio, nomDir)) {
            // (primer hijo de d es el directorio buscado)
            Directorios aBorrar = d->sH;
            // borro lista de archivos:
            Archivos archBorrar = aBorrar->listaArchivos;
            bool todoBorrado = archBorrar == NULL;
            while (!todoBorrado) {
                Archivos aux = archBorrar;
                if (aux->sig != NULL) {
                    delete [] aux->contenidoArchivo;
                    delete [] aux->nombreArchivo;
                    delete aux;
                    todoBorrado = true;
                } else {
                    while (aux->sig->sig != NULL) {
                        aux = aux->sig;
                    }
                    delete [] aux->sig->contenidoArchivo;
                    delete [] aux->sig->nombreArchivo;
                    delete aux->sig;
                    aux->sig = NULL;
                }
            }
            // reasigno a d->pH:
            d->pH = aBorrar->pH;

            // libero memoria aBorrar:
            delete [] aBorrar->nombreDirectorio;
            delete aBorrar;
        }
    }
}