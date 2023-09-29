#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^2) AS:-O(1)

int numberOfInversions(vector<int>&arr, int n)
{
    int cnt=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n ; j++)
        {
            if(arr[i]>arr[j])
                cnt++;
        }
    }

    return cnt;
}

// Better, TC:-O(n*log(n)) AS:-O(n)

vector<int> merge(vector<int>&arr, int start, int mid, int end, int *inversion)
{
    int left=start;
    int right=mid+1;
    
    vector<int> temp;
    
    while(left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            // arr[left]>arr[right]

            *inversion=mid-left+1;

            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left<=mid)
    {
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=end)
    {
        temp.push_back(arr[right]);
            right++;
    }
    
    return temp;
}

void mergeSort(vector<int>&arr, int start, int end, int *inversion)
{
    if(start==end)
        return;
        
    int mid=(start+end)/2;
    
    // Hypothesis
    mergeSort(arr, start, mid, inversion);
    mergeSort(arr, mid+1, end, inversion);
    
    // Have to merge the two sorted halves
    vector<int> temp=merge(arr, start, mid, end, inversion);
    
    for(int i=start; i<=end; i++)
        arr[i]=temp[i-start];
}

int numberOfInversions(vector<int>&arr, int n)
{
    int inversion=0;

    mergeSort(arr, 0, n-1, &inversion);

    return inversion;
}