#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&MATRIX)
{
    int cols=MATRIX[0].size();
    int rows=MATRIX.size();
    int top=0, bottom=rows-1, left=0, right=cols-1;
    vector<int> ans;

    while(left<=right && top<=bottom)
    {
        // Top
        for(int i=left; i<=right; i++)
        {
            ans.push_back(MATRIX[top][i]);
        }
        top++;
        // Right
        for(int i=top; i<=bottom; i++)
        {
            ans.push_back(MATRIX[i][right]);
        }
        right--;
        // Bottom
        if(top<=bottom)
        {
            
            for(int i=right; i>=left; i--)
            {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }
        // Left
        if(left<=right)
        {
            for(int i=bottom; i>=top; i--)
            {
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }

    return ans;
}