#include <stdio.h>

void bubbleSort (int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }        
    }    
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    return 0;
    

}