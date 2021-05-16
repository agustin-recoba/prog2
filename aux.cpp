TIterador recorridaPorNiveles(TBinario b) {
    TPila pila = crearPila(cantidadBinario(b));

    TColaBinarios cola = crearColaBinarios();

    if (b != NULL)
        cola = encolar(b, cola);
    while (!estaVaciaColaBinarios(cola)) {
        TBinario t = frente(cola);
        pila = apilar(natInfo(raiz(t)), pila);
        cola = desencolar(cola);

        if (derecho(t) != NULL)
            cola = encolar(derecho(t), cola);
        if (izquierdo(t) != NULL)
            cola = encolar(izquierdo(t), cola);
    }

    liberarColaBinarios(cola);
    
    int ultimoAgr = -1;

    
    TIterador nuevo = crearIterador();

    while (!estaVaciaPila(pila)) {
        nat porAgre = cima(pila);
        if ((int) porAgre > ultimoAgr + 1) {
            nuevo = agregarAIterador(porAgre, nuevo);
        } else {
            nuevo = agregarAIterador(UINT_MAX, nuevo);
            nuevo = agregarAIterador(porAgre, nuevo);
        }
        ultimoAgr = porAgre;
        pila = desapilar(pila);
    }
    liberarPila(pila);

    return nuevo;
}