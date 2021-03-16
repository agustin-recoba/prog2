struct Cola {
};

Cola crearCola () {
    Cola c;
    return c;
}

Cola encolar (unsigned int x, Cola c) {
    return c;
}

bool esVacia (Cola c) {
    return true;
}

unsigned int frente (Cola c) {
    return 1;
}

Cola desencolar (Cola c) {
    return c;
}