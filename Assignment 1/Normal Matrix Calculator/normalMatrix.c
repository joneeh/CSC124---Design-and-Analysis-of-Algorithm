#include <stdio.h>
#include <time.h>

int main()
{
    char operator;
    int m, n, p, q, c, d, k, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];
    clock_t t;

    printf("Matrix Calculator\n");
    printf("CSC124 - Design and Analysis of Algorithm\n\n");

    printf("Choose Between (A)fixed 2x2 matrix or (B)flexible matrix size: \n");
    scanf("%c", &operator);

    switch(operator)
    {
    case 'A':
        m=2;
        n=2;
        p=2;
        q=2;

        printf("\n\n");
        printf("Fixed 2x2 Matrix\n\n");

        printf("\n//Add space for new Column and enter for new Row//");
        printf("\n[Enter elements of first matrix]\n\n");

        for (c = 0; c < m; c++)
            for (d = 0; d < n; d++)
                scanf("%d", &first[c][d]);

        if (n != p)
            printf("The matrices can't be multiplied with each other.\n");
        else
        {
            printf("\n//Add space for new Column and enter for new Row//");
            printf("\n[Enter elements of second matrix]\n\n");

            for (c = 0; c < p; c++)
                for (d = 0; d < q; d++)
                    scanf("%d", &second[c][d]);

            t = clock();
            for (c = 0; c < m; c++)
            {
                for (d = 0; d < q; d++)
                {
                    for (k = 0; k < p; k++)
                    {
                        sum = sum + first[c][k]*second[k][d];
                    }
                    multiply[c][d] = sum;
                    sum = 0;
                }
            }

            printf("\nProduct of the matrices:\n\n");

            for (c = 0; c < m; c++)
            {
                for (d = 0; d < q; d++)
                    printf("%d\t", multiply[c][d]);
                printf("\n");
            }
        }

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        printf("\n Calculation Time: %f\n\n", time_taken);
        return 0;

        break;

    case 'B':

        printf("Fluent array size Matrix\n\n");

        printf("Enter the number of rows and colums for the first Matrix: \n");
        printf("Columns: ");
        scanf("%d", &m);
        printf("Rows: ");
        scanf("%d", &n);
        printf("\n//Add space for new Column and enter for new Row//");
        printf("\n[Enter elements of first matrix]\n\n");

        for (c = 0; c < m; c++)
            for (d = 0; d < n; d++)
                scanf("%d", &first[c][d]);

        printf("\n\nNote: The numbers of first matrix's row and and second matrix's column should be the same!!\n");
        printf("Enter the number of rows and colums for the first Matrix: \n");
        printf("Columns: ");
        scanf("%d", &p);
        printf("Rows: ");
        scanf("%d", &q);

        if (n != p)
            printf("The matrices can't be multiplied with each other.\n");
        else
        {
            printf("\n//Add space for new Column and enter for new Row//");
            printf("\n[Enter elements of second matrix]\n\n");

            for (c = 0; c < p; c++)
                for (d = 0; d < q; d++)
                    scanf("%d", &second[c][d]);

            t = clock();
            for (c = 0; c < m; c++)
            {
                for (d = 0; d < q; d++)
                {
                    for (k = 0; k < p; k++)
                    {
                        sum = sum + first[c][k]*second[k][d];
                    }
                    multiply[c][d] = sum;
                    sum = 0;
                }
            }

            printf("\nProduct of the matrices:\n\n");

            for (c = 0; c < m; c++)
            {
                for (d = 0; d < q; d++)
                    printf("%d\t", multiply[c][d]);
                printf("\n");
            }
        }

        t = clock() - t;

        double time_taken2 = ((double)t)/CLOCKS_PER_SEC;
        printf("\n Calculation Time: %f\n\n", time_taken2);
        return 0;

        break;
    }

    return 0;
}
