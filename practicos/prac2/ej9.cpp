#include <stdio.h>

typedef unsigned int uint;

void vasosAux(bool *V, uint n, uint deep) {
    if (deep < n/2) {
        if (deep % 2 == 0) {
            V[n-deep] = true;
            V[1+deep] = false;
        } else {
            V[n-deep] = false;
            V[1+deep] = true;
        }
        vasosAux(V, n, deep + 1);
    }      
}

void vasos(bool *V, uint n) {
    vasosAux(V, n, 0);
}

int main () {
    int n = 10;
    bool * vas = new bool[n + 1];
    for(int i = 1; i <= n/2 +1; i++)
        vas[i] = true;
    for(int i = n/2 +1; i <= n ; i++)
        vas[i] = false;
    
    vasos(vas, n);  

    for(int i = 1; i <= n; i++)
        printf("%d ", vas[i]);    
}