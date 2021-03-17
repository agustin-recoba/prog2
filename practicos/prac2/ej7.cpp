#include <stdio.h>

typedef unsigned int uint;


float hornerAux(float *P, uint n, float x, uint i) {
    if (n == i)
        return P[i];
    else
        return P[i] + x*hornerAux(P, n, x, i+1);
}

float horner(float *P, uint n, float x) {
    return hornerAux(P, n, x, 0);
}

int main() {
    float *pol = new float[3];
    pol[0] = -6.0;
    pol[1] = 6.0;
    pol[2] = 3.0;
    printf("%f \n", horner(pol, 3, 3.0));
}


