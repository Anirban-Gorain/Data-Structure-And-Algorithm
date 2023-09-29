#include<bits/stdc++.h>
using namespace std;

// Brute

int solveMaxConOnes(int arr[], int n)
{
    int i,j,maxConOnes;
    i=j=0;
    maxConOnes=-1;

    while(i<n && j<n)
    {
        // Where is the first one?
        while(i<n)
        {
            if(arr[i]==1)
                break;
            i++;
        }
        // When all are zeros.
        if(i>=n)
            return -1;

        // Where is the first zero one the right side of i?
        j=i+1;
        while(j<n)
        {
            if(arr[j]==0)
                break;
            j++;
        }

        maxConOnes=max(maxConOnes, j-i);
        i=j+1;
    }
    return maxConOnes;       
}

// Optimal
int solve1MaxConOnes(int arr[], int n)
{
    int maxConOnes=0;
    int count=0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxConOnes=max(maxConOnes, count);
        }
        else
            count=0;
    }

    return maxConOnes;
}