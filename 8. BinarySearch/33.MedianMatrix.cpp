#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(m*n), AS:-O(m*n)

// Optimal, TC:-O(log(10^9)*rows*log(cols), AS:-O(1)

int howManyLessThanOrEqual(vector<vector<int>> &matrix, int rows, int cols, int num)
{
    int ans=0;

    for(int i=0; i<rows; i++)
    {
        int low=0, high=cols-1, cal=0;

        while(low<=high)
        {
            int mid=low-(low-high)/2;

            if(matrix[i][mid]<=num)
            {
                cal=mid+1;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        ans=ans+cal;
    }

    return ans;
}

int median(vector<vector<int>> matrix, int m, int n)
{
    int rows=m, cols=n;
    int medianElementNum=(rows*cols)/2+1;
    int low=1, high=1e9;

    while(low<=high)
    {
        int mid=low-(low-high)/2;
        int howManyLessThanOrEqualToMid=howManyLessThanOrEqual(matrix, rows, cols, mid);

        if(howManyLessThanOrEqualToMid==medianElementNum)
            high=mid-1;
        else if(howManyLessThanOrEqualToMid>medianElementNum)
            high=mid-1;
        else
            low=mid+1;

    }

    return low;
}