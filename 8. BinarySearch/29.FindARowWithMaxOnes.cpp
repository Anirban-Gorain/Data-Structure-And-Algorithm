#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int len)
{
    int low=0, high=len-1, lowerBound=-1;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        if(arr[mid]==1)
        {
            lowerBound=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return lowerBound;
}


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int rows=n, cols=m, maxOnes=0, ind=-1;

    for(int i=0; i<rows; i++)
    {
        int len=matrix[i].size();
        int lowerB=lowerBound(matrix[i], len);

        if(lowerB==-1)
            continue;

        int cal=len-lowerB;

        if(maxOnes<cal)
        {
            maxOnes=cal;
            ind=i;
        }
    }

    return ind;
}