#include<iostream>
#include<vector>

int largest(vector<int> &arr, int n)
{
    int maxElem=arr[0];
    for(int i=1; i<n; i++)
        maxElem=max(maxElem, arr[i]);

    return maxElem;
}