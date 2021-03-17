#include <stdio.h>

typedef unsigned int uint;

int factAcum(uint n,uint acum) {
    if (n <= 1)
        return acum;
    else
        return factAcum(n - 1, n*acum);
}

int fact(uint n) {
    return factAcum(n, 1);
}

int main() {
    printf("%d \n", fact(0));
}