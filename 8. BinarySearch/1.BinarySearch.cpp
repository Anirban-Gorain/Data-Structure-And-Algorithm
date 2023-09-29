#include<bits/stdc++.h>
using namespace std;

// Iterative method, TC:-O(log(n)) AS:- O(1)

int search(vector<int> &nums, int target)
{
    int len=nums.size();
    int left=0, right=len-1;

    while(left<=right)
    {
        int mid=left-(left-right)/2;

        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            right=mid-1;
        else
            // nums[mid]<target
            left=mid+1;
    }

    return -1;
}

// Recursive method, TC:-O(log(n)) AS:-O(1)

int binarySearch(vector<int> &nums, int left, int right, int target)
{
    if(right>left)
        return -1;

    int mid=left-(left-right)/2;

    if(nums[mid]==target)
        return mid;
    else if(nums[mid]>target)
        right=mid-1;
    else
        // nums[mid]<target
        left=mid+1;
}

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size()-1, target);
}