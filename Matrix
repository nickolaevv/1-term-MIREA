#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
    int m,n,i,j ;                                   /*Variable for columns and strings*/
    srand (time(NULL));
    m = 4 + rand()%6;                         /*Setting random number of columns*/
    n = 5 + rand()%6;                          /*Setting random number of strings */

    printf("\n\n LINES = %d\n\n ",m);
    printf("COLUMNS = %d\n\n",n);

    int massive [m][n];                      /*Creating massive (matrix)*/

    /*CREATING AND FEELING IN THE MASSIVE*/

    for (i = 0; i<m; i++)
        {
            for (j = 0; j<n; j++)
                {
                    massive [i][j] = -50 + rand()%99 ;  /*Filin' in the massive*/
                    printf ("%5d",massive [i][j]);
                }
            printf ("\n");
        }

    /*END OF TASK 1*/

    /*SWAPPING AND REVERSING THE LINES */
    printf("\n SWAPPING AND REVERSING THE LINES");
    for( j = 0; j < n; j++)
        {
            int temp = massive[0][j];
            massive[0][j] = massive[m - 1][j];
            massive[m - 1][j] = temp;
        }

    for ( i = 0; i < n/2; i++)
        {
            int temp;
            temp = massive[0][i];
            massive[0][i] = massive[0][n - 1 - i];
            massive[0][n - 1 - i] = temp;

            temp = massive[m - 1][i];
            massive[m - 1][i] = massive[m - 1][n - 1 - i];
            massive[m - 1][n - 1 - i] = temp;

        }

    printf("\n \n");

    for ( i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                {
                    printf("%5d ",massive[i][j]);
                }
            printf("\n");
        }
    /*END OF TASK 2*/

    /*DELETING COLUMNS AND STRINGS*/
    int min = massive [0][0];  /*Variable for checking massive elements*/
    int mini,minj;                   /*Variaables for idenrifying the string and column of minimum element*/
    int delmassive [m-1][n-1];  /*Creating new massive without string and column of minimum element*/

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(massive[i][j]<=min)
                {
                    min = massive[i][j];
                    mini = i;
                    minj = j;
                }
    printf("\n MINIMUM ELEMENT = %d\n", min);
    printf("\n DELETING COLUMN AND LINE OF THIS ELEMENT \n\n");

    int delI = 0, delJ = 0;
    for (i = 0; i<m - 1; i++)
        {
            for (j = 0; j<n - 1; j++)
                {
                    if (i >= mini) delI = 1;
                    if (j >= minj) delJ = 1;
                    delmassive[i][j] = massive[i+delI][j+delJ];      /*Fillin' in the new massive*/
                    printf ("%5.0d",delmassive [i][j]);
                }
            printf ("\n");
        }
    printf("\n");

    m--;
    n--;

    /*End TASK 3*/

    /*CREATING NEW MATRIX*/
    printf(" CREATING NEW MATRIX\n\n");
    printf("( . ) IS FINISHING INPUT\n");
    printf("( , ) IS FINISHING THE LINE\n");
    printf("( SPACE ) IS FINISHING ELEMENT INPUT\n\n");
    printf("WARNING!!!ENTER MATRIX ACCURATE OR IT WON'T WORK\n\n");
    printf("ENTER NEW MATRIX WITH %d LINES\n\n", n );
    char N;
    i = 0;
    j = 0;
    int a = 0;
    int umassive[10][10];               /*Creating user massive*/
    while((N=getchar())!='.')     /*Making input settings for dot*/
        {
            if(N>='0' && N<='9')
                a = a*10 + N - '0';               /*Making input settings for space*/
            if(N==' ')
                {
                    umassive[i][j] = a;
                    a = 0;
                    j++;
                }
            if(N==',')                               /*Making input settings for comma*/
                {
                    umassive[i][j] = a;
                    a = 0;
                    i++;
                    j = 0;
                }
        }
    umassive[i][j] = a;
    j++;
    int p = j;
    i++;
    if(i!=n)
        {
            printf("WRONG AMOUNT OF LINES.ENTERED %d INSTEAD OF %d.\n\n", i, n);
            return 0;
        }
    printf("\n");

    int Z;
    int gmassive[m][p];           /*New massive .that is the result of multiplying*/
    printf("MULTIPLING MATRIX\n\n");
    for(i=0; i<m; i++)
        {
            for(j=0; j<p; j++)
                {
                    gmassive[i][j] = 0;
                    for(Z=0; Z<n; Z++)
                        gmassive[i][j] += delmassive[i][Z] * umassive[Z][j];
                    printf(" %5d ", gmassive[i][j]);
                }
            printf("\n");
        }

    return 0;
    printf("\n");

    return 0;
}
