#include <stdio.h>
#include <stdlib.h>

void show(int* vet, int size);
void bubblesort(int* vet, int size);

int main(void)
{
    int vet[5] = {5,2,4,3,1};
    printf("\nantes do sort: ");
    show(vet,5);
    bubblesort(vet,5);
    printf("\ndepois do sort: ");
    show(vet,5);
    printf("\n");

    return 0;
}

void bubblesort(int* vet, int size)
{
    int i,j,temp;
    for(i=0; i<size; i++)
    {
        for(j=0;j<size;j++)
        {
            if(vet[j] > vet[j+1])
            {
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}

void show(int* vet, int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++)
        printf(" %d",vet[i]);
    printf("\n");
}