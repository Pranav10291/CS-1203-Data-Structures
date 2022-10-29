// Write a program to perform insertion sort on array
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
    for (i = 1; i < n; i++)           //insertion sort starts from second element
    {
        temp = a[i];                  //storing the value of second element in temp
        j = i - 1;                    //j is the index of previous element
        while (j >= 0 && a[j] > temp) //loop will run till j becomes 0 and previous element is greater than temp
        {
            a[j + 1] = a[j];          //shifting the element to one position ahead
            j--;                      //decrementing j
        }
        a[j + 1] = temp;              //inserting the element at proper position
    }
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
