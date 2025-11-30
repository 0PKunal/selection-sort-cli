#include <stdio.h>

void selectionsort(int data[], int n){
    for (int i = 0; i < n-1; i++){
        int si = i;
        for (int j = i+1; j < n; j++){
            if (data[j] < data[si]){
                si = j;
            }
        }
        int temp = data[i];
        data[i] = data[si];
        data[si] = temp;
    }
}


int main(){
    
    int raw_data[] = {
        73, 2, 89, 45, 10, 56, 99, 3, 67, 24, 
        91, 12, 37, 84, 1, 60, 48, 28, 77, 8, 
        94, 16, 33, 81, 6, 52, 42, 20, 69, 100, 
        15, 30, 97, 54, 4, 85, 26, 64, 39, 0, 
        93, 22, 58, 78, 9, 46, 31, 14, 50, 75
    };
    

    int n = sizeof(raw_data) / sizeof(raw_data[0]);

    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++)
        printf("%d, ", raw_data[i]);
    printf("\n");

    selectionsort(raw_data, n);

    printf("\nSorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d, ", raw_data[i]);
    printf("\n");

    return 0;

}