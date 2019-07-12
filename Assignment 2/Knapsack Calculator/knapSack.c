#include<stdio.h>

int main(void)
{
    int val[4] = {-1, 100, 20, 60, 40};
    int wt[4] = {-1, 3, 2, 4, 1};
    int i;

    int n = 4;
    int W = 5;

    printf("Knapsack Calculator\n");
    printf("CSC124 - Design and Analysis of Algorithm\n\n");

    knapSack(W, n, val, wt);

    return 0;
}

int getMax(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void knapSack(int W, int n, int val[], int wt[])
{
    int i, w;
    int V[n+1][W+1];
    for(w = 0; w <= W; w++)
    {
        V[0][w] = 0;
    }
    for(i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }
    for(i = 1; i <= n; i++)
    {
        for(w = 1; w <= W; w++)
        {
            if(wt[i] <= w)
            {
                V[i][w] = getMax(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
            }
            else
            {
                V[i][w] = V[i-1][w];
            }
        }
    }
    printf("Value:  ");
    for(i=1; i < 4; i++)
    {
        printf("%3d", val[i]);
    }
    printf("\n");
    printf("Weight: ");
    for(i=1; i < 4; i++)
    {
        printf("%3d", wt[i]);
    }
    printf("\n\n");
    printf("Max Value: %d\n", V[n][W]);
}
