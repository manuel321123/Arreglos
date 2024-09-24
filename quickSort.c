#include <stdio.h>

// Función para intercambiar dos elementos
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para dividir el arreglo según el pivote
int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto]; // Elige el último elemento como pivote
    int i = bajo - 1; // Índice del menor elemento

    for (int j = bajo; j < alto; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Función recursiva de Quick Sort
void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto); // Índice de partición

        // Ordena los elementos antes y después de la partición
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: \n");
    imprimirArreglo(arr, n);

    // Llama a Quick Sort
    quickSort(arr, 0, n - 1);

    printf("Arreglo ordenado: \n");
    imprimirArreglo(arr, n);

    return 0;
}
