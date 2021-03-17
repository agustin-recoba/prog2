#include <stdio.h>

typedef unsigned int uint;

int mcd(uint a, uint b) {
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if(a < b) {
        int aux = a;
        a = b;
        b = aux;
    } 

    return mcd(b, a % b);
}

int main() {
    printf("%d \n", mcd(9, 0));
}