#include<bits/stdc++.h>
using namespace std;

int time(vector<int> arr, int mid)
{
    int takenTime=0;
    int n=arr.size();

    for(int i=0; i<n; i++)
    {
        int elem=arr[i];
        int temp=ceil((double) elem/(double) mid);
        takenTime=takenTime+temp;
    }

    return takenTime;
}

int minimumRateToEatBananas(vector<int> arr, int h)
{
    // int totalBananas=0;
    int maxi=INT_MIN;
    
    for(int elem : arr)
        maxi=max(maxi, elem);

    int low=1, high=maxi;
    int ans=INT_MAX;

    while(low<=high)
    {
        int mid=low-(low-high)/2; // == k
        int takenTime=time(arr, mid);

        if(takenTime>h)
            low=mid+1;
        else
        {
            high=mid-1;
            ans=min(ans, mid);
        }
    }

    return ans;
}

int main(void)
{
    vector<int> arr={312884470};
    int h=312884469;

    cout << minimumRateToEatBananas(arr, h);
}