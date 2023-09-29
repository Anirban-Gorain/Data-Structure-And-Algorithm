#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int m)
{
	int len=arr.size();
	int left=0;
	int right=len-1;
	int position=-1;

	while(left<=right)
	{
		int mid=left-(left-right)/2;

		if(arr[mid]==m)
		{
			return mid;
		}
		else if(arr[mid]>m)
		{
			position=mid;
			right=mid-1;
		}
		else
		{
			// arr[mid]>right

			left=mid+1;
		}
	}

	if(position<0)
		return len;

	return position;
}