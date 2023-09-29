#include<bits/stdc++.h>
using namespace std;


// Optimal, TC:- O(log(n)) AS:- O(1)

int findMin(vector<int>& arr)
{
	int n=arr.size();
    int ans=INT_MAX;
    int low=0, high=n-1;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        if(arr[low]<=arr[mid])
        {
            ans=min(ans, arr[low]);
            low=mid+1;
        }
        else
        {
            ans=min(ans, arr[mid]);
            high=mid-1;
        }
    }

    return ans;
}

//

int findMin(vector<int>& arr)
{
	int n=arr.size();
    int low=0, high=n-1;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        if(arr[mid]<=arr[(mid-1+n)%n] && arr[mid]<=arr[(mid+1)%n])
            return arr[mid];

        if(arr[low]<=arr[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return -1;
}