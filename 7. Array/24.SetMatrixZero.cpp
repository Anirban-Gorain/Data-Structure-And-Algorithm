#include<bits/stdc++.h>
using namespace std;

//Brute-Force, TC:- O(m*n*(m+n)) AS:- O(1)

void markRow(vector<vector<int>> &matrix, int i, int cols)
{
    for(int j=0; j<cols; j++)
    {
        if(matrix[i][j]!=0)
        {
            matrix[i][j]=-1;
        }
    }

    return;
}

void markCol(vector<vector<int>> &matrix, int j, int rows)
{
    for(int i=0; i<rows; i++)
    {
        if(matrix[i][j]!=0)
        {
            matrix[i][j]=-1;
        }
    }

    return;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
	int rows=matrix.size();
	int cols=matrix[0].size();

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j]==0)
            {
                markRow(matrix, i, cols);
                markCol(matrix, j, rows);
            }
        }
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j]==-1)
            {
                matrix[i][j]=0;
            }
        }
    }

    return matrix;
}

//Better, TC:- O(2mn) AS:- O(m+n)

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int rows=matrix.size();
	int cols=matrix[0].size();
    vector<int> markRows(rows, 0);
    vector<int> markCols(cols, 0);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j]==0)
            {
                markRows[i]=INT_MIN;
                markCols[j]=INT_MIN;
            }
        }
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(markCols[j] || markRows[i])
            {
                matrix[i][j]=0;
            }
        }
    }

    return matrix;
}

//Optimal, TC:- O(mn) AS:- O(1)

#include<bits/stdc++.h>

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int row=matrix.size();
    int col=matrix[0].size();
    int row0Col0=0;

    // Marking the first row for the first row.

    for(int j=0; j<col; j++)
    {
        if(matrix[0][j]==0)
        {
            matrix[0][j]=-1;
            matrix[0][0]=-1;
        }
    }

    // Marking the first col for the first col.

    for(int i=0; i<row; i++)
    {
        if(matrix[i][0]==0)
        {
            matrix[i][0]=-1;
            row0Col0=-1;
        }
    }

    // From (1, 1) to rest of the part.

    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=-1;
                matrix[i][0]=-1;
            }
        }
    }
    
    // Looking and marking form (1, 1) to rest of the part

    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            if(matrix[0][j]==-1 || matrix[i][0]==-1)
            {
                matrix[i][j]=0;
            }
        }
    }

    // Looking from last col of the first row

    for(int j=col-1; j>=0; j--)
    {
        if(matrix[0][0]==-1 || matrix[0][j]==-1)
            matrix[0][j]=0;
    }

    // Looking first col

    for(int i=0; i<row; i++)
    {
        if(row0Col0==-1 || matrix[i][0]==-1)
            matrix[i][0]=0;
    }

    return matrix;
}
