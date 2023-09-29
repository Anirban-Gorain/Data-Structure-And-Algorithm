#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int> &arr, int maxSubArraySum)
{
    int sum=0, noOfSubArr=1, n=arr.size();

    for(int i=0; i<n; i++)
    {
        if(sum+arr[i]<=maxSubArraySum)
        {
            sum+=arr[i];
        }
        else
        {
            noOfSubArr++;
            sum=arr[i];
        }
    }

    return noOfSubArr;
}

// Optimal, TC:- O(n*log(range)) AS:- O(1)

int largestSubarraySumMinimized(vector<int> arr, int k)
{
    int maxi=*max_element(arr.begin(), arr.end());
    int sum=accumulate(arr.begin(), arr.end(), 0);

    int low=maxi, high=sum, ans;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        int noOfSubArr=countSubarray(arr, mid);

        if(noOfSubArr>k)
        {
            low=mid+1;
        }
        else
        {
            ans=mid;
            high=mid-1;
        }
    }

    return ans;
}