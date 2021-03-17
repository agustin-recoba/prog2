#include <stdio.h>

typedef unsigned int uint;

int fibo(uint n, int & count) {
    if (n==0 || n==1) {
        return 1;
        
    } else {
        count = count + 2;
        return fibo(n-1, count) + fibo(n-2, count);
    }
}

int countFibo(uint n) {
    int c = 0;
    int f = fibo(n, c);
    return c;
}

int main() {
    printf("%d \n", countFibo(10));
}