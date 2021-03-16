#include <stdio.h>
#include <math.h> 

int ocurrencias(char frase[100], char let, int largo) {
    int count = 0;
    for(int i = 0; i < largo; i++) {
        if (frase[i] == let) {
            count++;
        } 
    }
    return count;
}

int main () {
    char b[] = {'a', 'n', 'b', 'a', 'p', 'a'};
    int a = ocurrencias(b, 'a', 6);
    printf("%d \n", a );
    return 0;
}