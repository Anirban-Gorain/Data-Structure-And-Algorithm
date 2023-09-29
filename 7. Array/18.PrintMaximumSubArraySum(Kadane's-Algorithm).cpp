#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum=LONG_LONG_MIN;
    long long sum;
    int start, startAns, endAns;

    for(int i=0; i<n; i++) 
    {
        if(sum==0)
            start=i;

        sum=sum+arr[i];

        if(sum<maxSum)
        {
            maxSum=sum;
            startAns=start;
            endAns=i;
        }

        if(sum<0)
        {
            sum=0;
        }
    }

    while(startAns<=endAns)
    {
        cout<<arr[startAns];
        startAns++;
    }

    return maxSum;
}


