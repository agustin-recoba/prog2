#include <stdio.h>
int rayuela(int n) {
    if (n <= 3)
        return n;
    else
        return 2 + rayuela(n-1);
}

int main() {
    for (int i = 0; i <= 10; i++) 
        printf("n = %d, %d \n", i, rayuela(i));
}