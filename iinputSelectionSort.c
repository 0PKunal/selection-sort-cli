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


int main()
{
    int raw_data[20], n, i;

    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("\nEnter the elements to be sorted: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &raw_data[i]);
    }

    selectionsort(raw_data, n);

    printf("\nThe sorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%4d", raw_data[i]);
    }
    printf("\n");

    return 0;
}