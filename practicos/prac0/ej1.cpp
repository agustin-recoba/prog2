#include <stdio.h>

float promClase (float n1, float n2, float n3, float n4, float n5) {
    return (n1 + n2 + n3 + n4 + n5)/5.0;
}

int main() {
    float d1, d2, d3, d4, d5;
    scanf("%f %f %f %f %f", &d1, &d2, &d3 , &d4, &d5);
    float resultado = promClase(d1, d2, d3, d4, d5);
    printf("%f \n", resultado);
    return 0;
}