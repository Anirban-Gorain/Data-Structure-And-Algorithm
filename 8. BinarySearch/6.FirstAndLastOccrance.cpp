#include <bits/stdc++.h> 
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int left=0;
    int right=n-1;
    int firstOcc=-1;
    int lastOcc=-1;

    // Left Occurrence

    while(left<=right)
    {
        int mid=left-(left-right)/2;

        if(arr[mid]==k)
        {
            firstOcc=mid;
            right=mid-1;
        }
        else if(arr[mid]>k)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }

    // Right occurrence

    left=0;
    right=n-1;

    while(left<=right)
    {
        int mid=left-(left-right)/2;

        if(arr[mid]==k)
        {
            lastOcc=mid;
            left=mid+1;
        }
        else if(arr[mid]>k)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }

    return {firstOcc, lastOcc};
}