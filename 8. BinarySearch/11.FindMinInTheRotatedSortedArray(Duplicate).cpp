#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:- O(n) AS:- O(1)

// Optimal 1, TC:- O(log(n)) AS:- O(1)

int findMin(vector<int>& arr)
{
    int n=arr.size();
    
    if(n==1)
        return arr[0];

    int low=0, high=n-1;
    int ans=INT_MAX;

    while(low<=high)
    {
        int mid=low-(low-high);

        if(arr[mid]==arr[low] && arr[mid]==arr[high])
        {
            ans=min(ans, arr[mid]);

            low++;
            high--;
            continue;
        }

        // Have to identify the sorted part

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