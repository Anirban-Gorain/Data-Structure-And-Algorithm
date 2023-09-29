#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int target)
{
    int low=0; int mid; int high=n-1;

    while(low<=high)
    {
        mid=low-(low-high)/2;

        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low++;
            high--;
            continue;
        }

        if(arr[mid]==target)
            return mid;


        if(arr[low]<arr[mid])
        {
            // Is the left part is sorted

            if(arr[low]<=target && target<arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else
        {
            // Is the right part is sorted

            if(arr[mid]<target && target<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }

    return -1;
}
