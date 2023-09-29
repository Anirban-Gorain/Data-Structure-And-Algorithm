#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:- O(n) AS:- O(1)

// Optimal, TC:- O(log(n)) AS:- O(1)

int floorSqrt(int n)
{
    long long low=1, high=n;
    long long ans=1;

    while(low<=high)
    {
        long long mid=low-(low-high)/2;
        long long sq=mid*mid;

        if(sq==(long long)n)
            return mid;
        else if(sq<n)
        {
            ans=max(ans, mid);
            low=mid+1;
        }
        else
            high=mid-1;
    }

    return ans;
}
