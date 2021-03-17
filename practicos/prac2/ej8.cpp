#include <stdio.h>

typedef unsigned int uint;

uint combinaciones(uint m, uint n) {
    if (n == m) 
        return 1;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else {
        return combinaciones(m-1, n) + combinaciones(m-1, n-1);
    }
}

int main() {
    printf("%d \n", combinaciones(500, 499));
}