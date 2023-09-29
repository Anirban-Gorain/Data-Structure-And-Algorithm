#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    int left=0, right=n-1;
    int lowerBound=-1;;

    while(left<=right)
    {
        int mid=left-(left-right)/2;

        if(arr[mid]==x)
        {
            // It can be my answer but, Should look on the left side
            lowerBound=mid;
            right=mid-1; 
        }
        else if(arr[mid]>x)
        {
            lowerBound=mid;
            right=mid-1;
        }
        else
        {
            // arr[mid]<x

            left=mid+1;
        }
    }

	if(lowerBound<0)
		return n;

    return lowerBound;
}
