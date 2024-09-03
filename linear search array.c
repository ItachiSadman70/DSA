#include<stdio.h>

int linearSearch(int arr[],int size,int element)
{
    for (int i =0; i<size; i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,3,4,5,6,78,83,9,33,42,65,7,8,55};
    int size = 14;
    int element =54;
    int searchIndex = linearSearch( arr, size,element);
    printf("The element %d was found at index %d\n", element, searchIndex);
    return 0;
}
