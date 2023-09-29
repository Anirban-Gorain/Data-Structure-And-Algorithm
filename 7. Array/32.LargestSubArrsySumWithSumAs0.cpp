#include<bits/stdc++.h>
using namespace std;

// Brute-force, TC:-O(n^2) AS:-O(1)

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int len=arr.size();
    int subArrayLen=0;

	for(int i=0; i<len; i++)
    {
        int sum=0;

        for(int j=i; j<len; j++)
        {
            sum+=arr[j];

            if(sum==0)
            {
                subArrayLen=max(subArrayLen, j-i+1);
            }
        }
    }

    return subArrayLen;
}

// Better, TC:-O() AS:-O()

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int len=arr.size();
    int subArrayLen=0;
    int sum=0;

    unordered_map<int, int> prefix; // (PrefixSum, Index)

    for(int i=0; i<len; i++)
    {
        sum+=arr[i];

        if(sum==0)
        {
            subArrayLen=max(subArrayLen, i+1);
        }

        if(prefix.find(sum)!=prefix.end())
        {
            int index=prefix.find(sum)->second;
            subArrayLen=max(subArrayLen, i-index+1);
        }
        else
        {
            prefix[sum]=i;
        }
    }

    return subArrayLen;
}