#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:- O(n^2) AS:- O(1)

// Optimal, TC:- O(n*log(n)) AS:- O(1)

bool validate(vector<int> arr, int k, int m, int day)
{
    int n=arr.size();
    int con=0;
    int noOfB=0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=day)
        {
            con++;
        }
        else
        {
            noOfB=noOfB+con/k;

            if(noOfB>=m)
                return true;

            con=0;
        }
    }
    noOfB=noOfB+con/k;

    return (noOfB>=m);
}

int roseGarden(vector<int> arr, int k, int m)
{
    int n=arr.size();

    if(k*m>n)
        return -1;

	int mini=INT_MAX, maxi=INT_MIN;

    for(int elem : arr)
    {
        mini=min(mini, elem);
        maxi=max(maxi, elem);
    }

    int low=mini, high=maxi, ans=INT_MAX;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        bool isPossible=validate(arr, k, m, mid);

        if(isPossible==true)
        {
            ans=min(ans, mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }

    return (ans==INT_MAX)?-1:ans;
}

int main(void)
{
    vector<int> arr={1, 2, 1, 2, 7, 2, 2, 3, 1,};
    int k=3; int m=2;

    cout<<roseGarden(arr, 3, 2);
}