#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int *v, int init, int end, int key)
{
    int mid;
    if (init > end)
        return -1;
    mid = (end + init) /2;

    if(v[mid] == key)
        return mid;
    
    if(key > v[mid])
        return binarySearch(v, mid+1, end, key);
    else
        return binarySearch(v, init, mid-1, key);
}

int main()
{
    srand(time(0));

    int vet[100];
    int numbers_to_find[2] = {10, 50};

    for(int i = 0; i < 100; i++)
        vet[i] = rand() % 100;

    for(int i = 0; i < 100; i++)
        printf("%d - %d\n", i, vet[i]);

    printf("\n");

    for(int i = numbers_to_find[0]; i <= numbers_to_find[1]; i++)
    {
        printf("%d -> %d\n", i, binarySearch(vet, 0, 100, i));
    }

    return 0;
}