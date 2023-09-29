#include<iostream>

int print2largest(int arr[], int n)
{
	int largest, secondLargest;
    largest=secondLargest=-1;

    for(int i=0; i<n; i++)
    {
        if(largest<arr[i])
        {
            secondLargest=largest;
            largest=arr[i];
        }
        else if(secondLargest<arr[i])
        {
            secondLargest=arr[i];
        }
    }

    return secondLargest;
}