#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(m*n) AS:-O(1)
// Better, TC:-O(m*log(n)) AS:-O(1)

// Optimal, TC:-O(log(m*n)) AS:-O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int rows=matrix.size();
    int cols=matrix[0].size();

    int low=0, high=(rows*cols)-1;

    while(low<=high)
    {
        int mid=low-(low-high)/2;
        int indToRow=mid/cols;
        int IndToCol=mid%cols;

        if(matrix[indToRow][IndToCol]==target)
            return true;
        
        if(matrix[indToRow][IndToCol]>target)
            high=mid-1;
        else
            low=mid+1;
        
    }

    return false;
}