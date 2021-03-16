#include <stdio.h>
#include <cstring>

bool esPalindrome (char* frase) {
    int largo = strlen(frase);
    int i = 0;
    while (i < largo/2 && frase[i] == frase[largo-1-i]) {
        i++;
    }
    return i < largo/2;
}

int main () {
    printf("Ingrese largo: \n");
    int larg;
    scanf("%d", &larg);
    printf("Ingrese frase: \n");
    char* fras = new char[larg];
    scanf("%s", fras);
    printf("%d \n", esPalindrome(fras)); // 0 es true, 1 es false
    return 0;
}