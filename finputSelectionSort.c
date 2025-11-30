#include <stdio.h>

void selectionsort(float data[], int n){
    for (int i = 0; i < n-1; i++){
        int si = i;
        for (int j = i+1; j < n; j++){
            if (data[j] < data[si]){
                si = j;
            }
        }
        float temp = data[i];
        data[i] = data[si];
        data[si] = temp;
    }
}


int main()
{
    float raw_data[20];
    int n, i;

    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("\nEnter the elements to be sorted: ");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &raw_data[i]);
    }

    selectionsort(raw_data, n);

    printf("\nThe sorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%4.2f ", raw_data[i]);
    }
    printf("\n");

    return 0;
}