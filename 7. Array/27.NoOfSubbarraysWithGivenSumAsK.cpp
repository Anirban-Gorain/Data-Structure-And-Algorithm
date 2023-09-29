#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k)
{
    int count=0, sum=0;
    unordered_map<int, int> prefix;
    int len=arr.size();

    for(int i=0; i<len; i++)
    {
        sum+=arr[i];
        if(sum==k)
            count++;
        count=count+prefix[sum];
        prefix[sum]++;
    }

    return count;
}