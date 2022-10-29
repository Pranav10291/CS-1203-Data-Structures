// Write a program to perform selection sort on array
#include <stdio.h>
int main()
{
    int a[100], i, j, n, temp;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)    // i < n-1 because last element will automatically be sorted
    {
        for (j = i + 1; j < n; j++)   // j = i+1 because we don't need to compare the element with itself
        {
            if (a[i] > a[j])      //swapping the elements to arrange in ascending order
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}