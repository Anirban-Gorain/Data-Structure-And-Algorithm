#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:- O(n*rage), AS:- O(1)

// Optimal, TC:- O(n*log(n)), AS:- O(1)

bool validation(vector<int>& arr, int limit, int mid)
{
    int n=arr.size();
    int divisionSum=0;

    for(int i=0; i<n; i++)
    {
        int elem=arr[i];
        int ceiledQuotient=ceil((double)elem/(double)mid);
        divisionSum+=ceiledQuotient;
    }

    return divisionSum<=limit;
}


int smallestDivisor(vector<int>& arr, int limit)
{
	int low=1, high, maxi=INT_MIN, ans=INT_MAX;

    for(int elem : arr)
        maxi=max(maxi, elem);

    high=maxi+1;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        bool isValid=validation(arr, limit, mid);

        if(isValid==true)
        {
            ans=min(ans, mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }

    return ans;
}