#include<bits/stdc++.h>
using namespace std;

// Brute-force generate all the sub-arrays, there are two versions n^3 and n^2.

// Better
int solve(int arr[], int n, int k)
{
    // Prefix sum <sum, index>

    unordered_map<int, int> prefixSum;
    int maxSubArray=0;

    int sum=0;
    
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum==k)
            maxSubArray=max(maxSubArray, i+1);

        int diff=sum-k;

        if(prefixSum.find(diff)!=prefixSum.end())
        {
            int lenOfSubArray=i-prefixSum[diff];
            maxSubArray=max(maxSubArray, lenOfSubArray);
        }

        if(prefixSum.find(sum)==prefixSum.end())
            prefixSum[sum]=i;
    }
    return maxSubArray;
}

// Optimal

int solve(int arr[], int n, int k)
{
    int left, right, sum, maxSubArray;
    left=right=sum=maxSubArray=0;

    while(right<n)
    {
        // Cal
        sum=sum+arr[right];
        // Result
        if(sum==k)
        {
            maxSubArray=max(maxSubArray, right-left+1);
            right++;
        }
        // Adjusting the window size
        else if (sum<k)
        {
            right++;
        }
        else if (sum>k)
        {
            while(sum>k)
            {
                sum=sum-arr[left];
                left++;
            }
            if(sum==k)
            {
                maxSubArray=max(maxSubArray, right-left+1);
            }
            right++;
        }
    }

    return maxSubArray;
}

int main(void)
{   

    return 0;
}