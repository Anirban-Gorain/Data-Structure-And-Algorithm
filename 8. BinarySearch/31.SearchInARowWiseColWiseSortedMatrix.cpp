#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(m*n), AS:-O(1)

// Better, TC:-O(m*log(m)), AS:-O(1)

// Optimal, TC:-O(m+n), AS:-O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row=matrix.size(), col=matrix[0].size();
    int iRow=row-1, iCol=0;

    while(iRow>=0 && iCol<col)
    {
        if(matrix[iRow][iCol]==target)
            return true;
        else if(matrix[iRow][iCol]>target)
            iRow--;
        else
            iCol++;
    }

    return false;
}