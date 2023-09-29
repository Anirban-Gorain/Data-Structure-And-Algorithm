#include<bits/stdc++.h>
using namespace std;

// Brute-force, TC:-(n^2), AS:-(n^2)

void rotateMatrix(vector<vector<int>> &mat)
{
    int row=mat.size();
    int col=mat[0].size();
    int ansMatrix[row][col];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            ansMatrix[i][j]=mat[col-1-j][i];
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            mat[i][j]=ansMatrix[i][j];
        }
    }
}

// Optimal, TC:-(n^2), AS:-(1)

void rotateMatrix(vector<vector<int>> &mat)
{
    int n=mat.size();

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Now have to reverse every row, mat[i]

    for(int i=0; i<n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}