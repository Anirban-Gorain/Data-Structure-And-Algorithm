#include<bits/stdc++.h>
using namespace std;

// Optimal, TC:- O(log(n)) AS:- O(1)

int findKRotation(vector<int> &arr){
    int n=arr.size();
    
    if(n==1)
        return 0;

    int low=0, high=n-1;
    int ans=INT_MAX;
    int indOfMin;

    while(low<=high)
    {
        int mid=low-(low-high);

        if(arr[mid]==arr[low] && arr[mid]==arr[high])
        {
            if(arr[mid]<ans)
            {
                ans=arr[mid];
                indOfMin=mid;
            }

            low++;
            high--;
            continue;
        }

        // Have to identify the sorted part

        if(arr[low]<=arr[mid])
        {
            if(arr[low]<ans)
            {
                ans=arr[low];
                indOfMin=low;
            }
            low=mid+1;
        }
        else
        {
            if(arr[mid]<ans)
            {
                ans=arr[mid];
                indOfMin=mid;
            }
            high=mid-1;
        }
    }

    return indOfMin;
}