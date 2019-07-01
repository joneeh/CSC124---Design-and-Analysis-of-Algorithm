#include<stdio.h>
#include <time.h>

int main()
{
    int a[2][2], b[2][2], c[2][2], i, j;
    int m1, m2, m3, m4, m5, m6, m7;
    clock_t t;

    printf("Matrix Calculator Using Strassen's Algorithm\n");
    printf("CSC124 - Design and Analysis of Algorithm\n\n");
    printf("Fixed 2x2 Matrix\n\n");

    printf("\n[Enter elements of first matrix]\n\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);

    printf("\n[Enter elements of second matrix]\n\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);

    t = clock();
    m1= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2= (a[1][0] + a[1][1]) * b[0][0];
    m3= a[0][0] * (b[0][1] - b[1][1]);
    m4= a[1][1] * (b[1][0] - b[0][0]);
    m5= (a[0][0] + a[0][1]) * b[1][1];
    m6= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
    m7= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);

    c[0][0] = m1 + m4- m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    printf("\nProduct of the matrices using Strassen's Algorithm: \n");
    for(i = 0; i < 2 ; i++)
    {
        printf("\n");
        for(j = 0; j < 2; j++)
            printf("%d\t", c[i][j]);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n\n Calculation Time: %f\n\n", time_taken);
    return 0;
}
