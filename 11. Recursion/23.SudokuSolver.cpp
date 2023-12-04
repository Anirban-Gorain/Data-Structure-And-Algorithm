#include<bits/stdc++.h>
using namespace std;

#define N 9

bool isValid(int board[N][N], int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(int grid[N][N])
{        
    for(int r=0; r<9; r++)
    {
        for(int c=0; c<9; c++)
        {
            if(grid[r][c]!=0)
                continue;
                
            for(int num=1; num<=9; num++)
            {
                bool status=isValid(grid, r, c, num);
                
                if(status)
                {
                    grid[r][c]=num;
                    
                    if(solve(grid))
                        return true;
                        
                    grid[r][c]=0;
                }
            }
            
            return false;
        }
    }
    
    return true;
}

bool SolveSudoku(int grid[N][N])  
{ 
    return solve(grid);
}

void printGrid (int grid[N][N]) 
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<grid[i][j]<<" ";
        }
    }
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}