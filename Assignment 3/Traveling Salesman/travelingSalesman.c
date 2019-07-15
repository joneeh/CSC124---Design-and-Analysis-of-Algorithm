#include<stdio.h>

int c = 0,cost = 999;

int graph[4][4] = { {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void copy_array(int *a, int n)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++)
    {
        sum += graph[a[i % 4]][a[(i + 1) % 4]];
    }
    if (cost > sum)
    {
        cost = sum;
    }
}

void permute(int *a, int i, int n)
{
    int j, k;
    if (i == n)
    {
        copy_array(a, n);
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
}

int main(void)
{
    int i, j;
    int a[] = {0, 1, 2, 3};
    permute(a, 0, 3);

    printf("Traveling Salesman Implementation - Using Nearest Neighbor Algorithm\n");
    printf("CSC124 - Design and Analysis of Algorithm\n\n");

    printf("Matrix representation of graph:\n\n");
    for (i=0; i<4; i++)
     {
        for(j=0; j<4; j++)
            {printf("%4d", graph[i][j]);}
            printf("\n");
     }

    printf("\nMinimum Cost: %d\n", cost);
}
