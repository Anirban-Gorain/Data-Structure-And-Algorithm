#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int n, int x)
{
    int left=0, right=n-1;
    int upperBound=-1;

    while(left<=right)
    {
        int mid=left-(left-right)/2;

        if(arr[mid]==x)
        {
            left=mid+1; 
        }
        else if(arr[mid]>x)
        {
            upperBound=mid;
            right=mid-1;
        }
        else
        {
            // arr[mid]<x

            left=mid+1;
        }
    }

	if(upperBound<0)
		return n;

    return upperBound;
}
