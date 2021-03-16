#include <stdio.h>
#include <math.h> 

bool esPrimo(int n) {
    if (n == 1) return false;
    int i = 2;
    while (i <= sqrt(n) && n % i != 0) {
        i++;
    }
    return ! (i <= sqrt(n));
}

int main () {
    int a, b;
    printf("Ingrese 2 enteros: ");
    scanf("%d %d", &a, &b);
    printf("\n");
    for (int i = a; i <= b; i++) {
        if (esPrimo(i)) {
            printf("%d \n", i);
        }
    }
    return 0;
}