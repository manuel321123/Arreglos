    #include <stdio.h>

void combina(int destino[], int fuente[], int inf, int sup, int mitad) {
    int i_inf = inf;
    int i_sup = mitad + 1;
    int i_destino = inf;

    // Combina las dos mitades ordenadas en un solo arreglo
    while (i_inf <= mitad && i_sup <= sup) {
        if (fuente[i_inf] < fuente[i_sup]) {
            destino[i_destino++] = fuente[i_inf++];
        } else {
            destino[i_destino++] = fuente[i_sup++];
        }
    }

    // Copia los elementos restantes de la mitad izquierda
    while (i_inf <= mitad) {
        destino[i_destino++] = fuente[i_inf++];
    }

    // Copia los elementos restantes de la mitad derecha
    while (i_sup <= sup) {
        destino[i_destino++] = fuente[i_sup++];
    }
}

void mergeSort(int datos[], int tmp[], int inf, int sup) {
    if (inf < sup) {
        int mitad = (inf + sup) / 2;

        // Ordena la primera mitad
        mergeSort(datos, tmp, inf, mitad);

        // Ordena la segunda mitad
        mergeSort(datos, tmp, mitad + 1, sup);

        // Combina ambas mitades ordenadas
        combina(tmp, datos, inf, sup, mitad);

        // Copia el arreglo ordenado desde tmp a datos
        for (int i = inf; i <= sup; i++) {
            datos[i] = tmp[i];
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int datos[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(datos) / sizeof(datos[0]);
    int tmp[n];

    printf("Array original: \n");
    printArray(datos, n);

    mergeSort(datos, tmp, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(datos, n);

    return 0;
}
