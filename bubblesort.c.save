#include <stdio.h>
#include <stdlib.h>
void fill(float* y,int n)
{
    int i;
    for(i=0; i<n; i++)
        {
            y[i] = i*i + 1;   /*Creating array for sorting*/
        }
    return;
}

/*Input  elements of array*/
void input_array(int* z,int n)
{
    printf("Enter the elements of the array:");
    int i;
    for(i=0; i<n; i++)
        {
            while (!scanf("%d", &z[i]))
                {
                    while (getchar() != '\n');
                    printf("Error enter again: ");
                }
        }
    return;
}
/*Output the array*/
void autput_array(int* w,int n)
{
    int i;
    for(i=0; i<n; i++)
        {
            printf("%d ", w[i]);
        }
    printf("\n");
    return;
}
/*Deleting same elements*/
void delit_same(int** x, int* n)
{
    int* y = (int *)malloc(100 * sizeof(int));
    int i,j;
    int k = 0;
    int flag=0;
    for(i=0; i<*n; i++)
        {
            for(j=0; j<k; j++)
                {
                    if ((*x)[i] == y[j])
                        {
                            flag = 1;
                        }
                }
            if (flag == 0)
                {
                    y[k] = (*x)[i];
                    k++;
                }
            flag=0;
        }
    *n = k;
    *x = y;
    return;

}
/*Hoar sorting function*/
void quicksort(int *x, int lo, int hi)
{
    int p;
    if (lo < hi)
        {
            p = partition(x, lo, hi);
            quicksort(x, lo, p);
            quicksort(x, p + 1, hi);
        }

}
/*Splitting for sort*/
int partition(int *x, int lo, int hi)
{
    int pivot;
    pivot = x[lo];
    int i,j;
    i = lo - 1;
    j = hi + 1;
    while(1)
        {
            do
                i = i + 1;
            while (x[i] < pivot);

            do
                j = j - 1;
            while (x[j] > pivot);

            if (i >= j)
                return j;
            int tmp;
            tmp = x[i];
            x[i] = x[j];
            x[j] = tmp;
        }
}
/*Bubblesort*/
int bubble_sort(int *x, int n)
{
    int i,j;
    for(i=0; i < n-1; i++)
        {
            for(j = i+1; j < n; j++)
                {
                    if (x[j] < x[i])
                        {
                            int tmp;
                            tmp = x[i];
                            x[i] = x[j];
                            x[j] = tmp;
                        }
                }
        }
}
/*Finding N-MAX*/
int find_N_max(int *x, int n, int MAX_N)
/*Checking for N-MAX being lower than array size*/
{
    int *y = (int *)malloc(100 * sizeof(int));
    int i;
    for (i=0; i < n; i++)
        {
            y[i] = x[i];
        }
    /*Deleting same eleements*/
    delit_same(&y,&n);
    /*Sort final array*/
    quicksort(y, 0, n-1);
    int result;
    result = y[n-MAX_N];
    return result;

}
/*Finding M-MIN*/
int find_M_min(int *x, int n, int MIN_M)
/*Checking for M-MIN being lower than array size*/
{
    int *y = (int *)malloc(100 * sizeof(int));
    int i;
    for (i=0; i < n; i++)
        {
            y[i] = x[i];
        }
    /*Deleting same elements*/
    delit_same(&y,&n);
    /*Sort finsl array*/
    quicksort(y, 0, n-1);
    int result;
    result = y[MIN_M-1]; /*MIN_M-1 is taken from 1 position of array*/
    return result;

}

int main(void)
{
    int* x = (int *)malloc(100 * sizeof(int));
    int n;
    /*Amount of elemets*/
    printf("Enter the size of the array:");
    while (!scanf("%d", &n))
        {
            while (getchar() != '\n');
            printf("Error enter again: ");
        }
    /*Array input from keyboard*/
    input_array(x,n);
    /*Deleting same elemets*/
    delit_same(&x, &n);
    /*Array sort*/
    quicksort(x,0,n-1);
    /*Array output*/
    autput_array(x,n);
    int N_MAX;
    printf("Enter the N-th maximum in the sorted array:");
    int a;
    while (!scanf("%d", &a))
        {
            while (getchar() != '\n');
            printf("Error enter again: ");
        }
    N_MAX = find_N_max(x, n, a);
    printf("%d\n", N_MAX);
    int M_MIN;
    printf("Enter the M-th minimum in the sorted array:");
    int b;
    while (!scanf("%d", &b))
        {
            while (getchar() != '\n');
            printf("Error enter again: ");
        }
    M_MIN = find_M_min(x, n, b);
    printf("%d\n", M_MIN);
    return 0;
}
