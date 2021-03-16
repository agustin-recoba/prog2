#include <stdio.h>



void ordenarArreglo(int arr[], int len) {
    int aux;
    for(int i = 0; i < len-1; i++)
        for(int j = 0; j < len-1-i; j++) 
            if (arr[j] > arr[j+1]) {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
}

void imprimirArreglo(int arr[], int len) {
    printf("Arreglo: ");
    for(int i = 0; i < len; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Ingrese largo: \n");
    int larg;
    scanf("%d", &larg);
    int arr[larg];
    printf("Ingrese arreglo: \n");
    for (int i = 0; i < larg; i++) {
        scanf("%d", &arr[i]);
    }
    imprimirArreglo(arr, larg);  
    ordenarArreglo(arr, larg);
    imprimirArreglo(arr, larg);  

}