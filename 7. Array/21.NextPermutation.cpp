#include<bits/stdc++.h>
using namespace std;

// Brute-force, generate all the possible permutation in a sorted order

// Optimal O(n)

vector<int> nextGreaterPermutation(vector<int> &arr)
{
    int len=arr.size();

    if(len==1)
        return arr;

    int criticalPoint=-1;

    for(int i=len-2; i>=0; i--)
    {
        if(arr[i]<arr[i+1])
        {

            criticalPoint=i;
            break;
        }
    }

    if(criticalPoint==-1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=len-1; i>=0; i--)
    {
        if(arr[i]>arr[criticalPoint])
        {
            swap(arr[i], arr[criticalPoint]);
            reverse(arr.begin()+criticalPoint+1, arr.end());
            break;
        }
    }
    return arr;
}