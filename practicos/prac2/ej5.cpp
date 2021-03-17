#include <stdio.h>

typedef unsigned int uint;

void hanoiAux(uint n, char origen, char intermedia, char destino) {
    if (n > 0)
        if (n == 1)
            printf("Mover dico %d desde %c hasta %c \n", 1, origen, destino);
        else {
            hanoiAux(n-1, origen, destino, intermedia);
            printf("Mover dico %d desde %c hasta %c \n", n, origen, destino);
            hanoiAux(n-1, intermedia, origen, destino);
        }
}

void hanoi(uint n) {
    hanoiAux(n, 'A', 'B', 'C');
}

int main() {
    hanoi(2);
}