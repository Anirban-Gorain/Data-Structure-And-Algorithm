#include<bits/stdc++.h>
using namespace std;

// Bute-Force

void sort1(int arr[], int n)
{
    sort(arr, arr+n);
}

// Better

void sort2(int arr[], int n)
{
    int zeros, ones, twos;
    zeros=ones=twos=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            zeros++;
        else if(arr[i]==1)
            ones++;
        else
            twos++;
    }

    for(int i=0; i<n; i++)
    {
        if(i<=zeros-1)
            arr[i]=0;
        else if(i>=zeros && i<= ones-1)
            arr[i]=1;
        else
            arr[i]=2;

    }
}

// Optimal

void sort3(int arr[], int n)
{
    int low=0, mid=0, high=n-1;

    while(mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else if (arr[mid]==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(void)
{

    return 0;
}