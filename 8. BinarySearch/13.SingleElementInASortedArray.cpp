#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:- O(n^2) AS:- O(1)

// Better, TC:- O(n) AS:- O(1)

// Optimal, TC:- O(log(n)) AS:- O(1)

int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();

	if(n==1)
		return arr[0];
	if(arr[0]!=arr[1])
		return arr[0];
	if(arr[n-1]!=arr[n-2])
		return arr[n-1];

	int low=1, high=n-2;

	while(low<=high)
	{
		int mid=low-(low-high)/2;

		if((arr[mid]!=arr[mid-1]) && arr[mid]!=arr[mid+1])
			return arr[mid];

		if((mid%2==0 && arr[mid+1]==arr[mid]) || (mid%2!=0 && arr[mid-1]==arr[mid]))
			low=mid+1;
		else
			high=mid-1;
	}
}