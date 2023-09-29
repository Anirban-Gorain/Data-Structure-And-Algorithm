#include<bits/stdc++.h>
using namespace std;


bool canWePlace(vector<int> &stalls, int k, int minDis)
{
    // After placing a cows at stalls[0]

    int placedCows=1, lastStall=stalls[0], n=stalls.size();

    for(int i=1; i<n; i++)
    {
        int distance=stalls[i]-lastStall;

        if(distance>=minDis)
        {
            placedCows++;
            lastStall=stalls[i];
        }

        if(placedCows>=k) return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int min=*min_element(stalls.begin(), stalls.end());
    int max=*max_element(stalls.begin(), stalls.end());

    int low=1, high=max-min;
    int ans;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        int isPossible=canWePlace(stalls, k, mid);

        if(isPossible==true)
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }

    return ans;
}