#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    

    // BruteForce

    bool isValid(vector<vector<int>> &board, int row, int col, int n)
    {
        int rc=row;
        int cc=col;
        
        // Left
        
        while(cc>=0)
        {
            if(board[rc][cc]==1)
                return false;
                
            cc--;
        }
        
        // Upper diagonal
        
        rc=row;
        cc=col;
        
        while(cc>=0 && rc>=0)
        {
            if(board[rc][cc]==1)
                return false;
                
            rc--; cc--;
        }
        
        // Lower diagonal
        
        rc=row;
        cc=col;
        
        while(cc>=0 && rc<n)
        {
            if(board[rc][cc]==1)
                return false;
                
            rc++; cc--;
        }
        
        return true;
    }

    void solve(vector<vector<int>> &board, int n, vector<int> path, vector<vector<int>> &ans, int col)
    {
        if(col==n)
        {
            ans.push_back(path);
            return;
        }
            
        for(int row=0; row<n; row++)
        {
            if(isValid(board, row, col, n))
            {
                path.push_back(row+1);
                board[row][col]=1;
                solve(board, n, path, ans, col+1);
                path.pop_back();
            }
        }
        
        return;
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        
        solve(board, n, {}, ans, 0);
        
        return ans;
    }

    // Optimal

    unordered_map<int, bool> upd;
    unordered_map<int, bool> lod;
    unordered_map<int, bool> r;

    void solve(vector<vector<int>> &board, int n, vector<int> path, vector<vector<int>> &ans, int col)
    {
        if(col==n)
        {
            ans.push_back(path);
            return;
        }
            
        for(int row=0; row<n; row++)
        {
            if(upd[row+col]==false && lod[n-1+col-row]==false && r[row]==false)
            {
                upd[row+col]=true;
                lod[n-1+col-row]=true;
                r[row]=true;
                
                path.push_back(row+1);
                board[row][col]=1;
                solve(board, n, path, ans, col+1);
                
                upd[row+col]=false;
                lod[n-1+col-row]=false;
                r[row]=false;
                
                board[row][col]=0;
                path.pop_back();
            }
        }
        
        return;
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        
        solve(board, n, {}, ans, 0);
        
        return ans;
    }

};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}