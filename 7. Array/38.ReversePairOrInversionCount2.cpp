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
            if(arr[i]>2*arr[j])
                cnt++;
        }
    }

    return cnt;
}

// Better, TC:-O(n*log(n)) AS:-O(n)

vector<int> merge(vector<int>&arr, int start, int mid, int end)
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

int countPairs(vector<int> &arr, int start, int mid, int end)
{
    int cnt=0;
    int left=start;
    int right=mid+1;

    for(int i=left; i<=mid; i++)
    {
        while(right<=end && arr[i]>2*arr[right]) right++;
        cnt+=right-(mid+1);
    }

    return cnt;
}

void mergeSort(vector<int>&arr, int start, int end, int *cntPairs)
{
    if(start==end)
        return;
        
    int mid=(start+end)/2;
    
    // Hypothesis
    mergeSort(arr, start, mid, cntPairs);
    mergeSort(arr, mid+1, end, cntPairs);

    // Count pairs

    int cnt=countPairs(arr, start, mid, end);

    (*cntPairs)=(*cntPairs)+cnt;
    
    // Have to merge the two sorted halves
    vector<int> temp=merge(arr, start, mid, end);

    
    for(int i=start; i<=end; i++)
        arr[i]=temp[i-start];
}

int team(vector<int>&arr, int n)
{
    int cntPairs=0;

    mergeSort(arr, 0, n-1, &cntPairs);

    return cntPairs;
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}