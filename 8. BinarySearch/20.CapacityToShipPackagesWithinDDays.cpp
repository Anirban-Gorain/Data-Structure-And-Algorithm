#include<bits/stdc++.h>
using namespace std;

bool validate(vector<int> &weights, int d, int shipCapacity)
{
    int sum=0, days=0, n=weights.size();

    for(int i=0; i<n; i++)
    {
        int elem=weights[i];

        if(elem>shipCapacity)
            return false;

        sum=sum+elem;
        
        if(sum>shipCapacity)
        {
            days++;

            // Reseting the value of 'Sum'

            sum=elem;
        }
    }

    days++;

    return days<=d;
}

int shipWithinDays(vector<int> &weights, int d)
{
    // Finding the range of the answer

    int sum=0, maxi=INT_MIN;

    for(int elem : weights)
    {
        sum=sum+elem;
        maxi=max(elem, maxi);
    }

    int low=maxi, high=sum, ans=INT_MAX;

    // Binary search on the answer

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        bool isValid=validate(weights, d, mid);

        if(isValid==true)
        {
            ans=min(mid, ans);
            high=mid-1;
        }
        else
            low=mid+1;
    }

    return ans;
}