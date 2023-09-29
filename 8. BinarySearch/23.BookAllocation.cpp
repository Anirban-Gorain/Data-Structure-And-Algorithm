#include<bits/stdc++.h>
using namespace std;

int countStu(vector<int>& arr, int n, int pages)
{
    int sum=0, stu=1;

    for(int i=0; i<n; i++)
    {
        if(sum+arr[i]<=pages)
        {
            sum+=arr[i];
        }
        else
        {
            stu++;
            sum=arr[i];
        }
    }

    return stu;
}

int findPages(vector<int> arr, int n, int m)
{
    if(m>n)
        return -1;

    int max=*max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int low=max, high=sum, ans;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        int noOfStu=countStu(arr, n, mid);

        if(noOfStu>m)
        {
            low=mid+1;
        }
        else
        {
            ans=mid;
            high=mid-1;
        }
    }

    return ans;
}

int main(void)
{
    cout << findPages({1, 17, 14, 9, 15, 9, 14}, 7, 7);
}