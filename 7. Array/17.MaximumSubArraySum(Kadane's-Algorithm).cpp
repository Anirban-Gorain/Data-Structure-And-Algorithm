#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum=LONG_LONG_MIN;
    long long sum;

    for(int i=0; i<n; i++) 
    {
        sum=sum+arr[i];
        maxSum=max(maxSum, sum);

        if(sum<0)
        {
            sum=0;
        }
    }   

    return maxSum;
}