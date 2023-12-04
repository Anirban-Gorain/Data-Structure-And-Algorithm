#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    int rows;
    int cols;
    vector<vector<int>> dir={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool find(vector<vector<char>>& board, int i, int j, string &word, int ind)
    {
        if(word.length()==ind)
            return true;
        if(i<0 || j<0 || i==rows || j==cols || board[i][j]=='!' || board[i][j]!=word[ind])
            return false;
            
        char temp=board[i][j];
        board[i][j]='!';
        
        // Movements
        
        for(auto mv : dir)
        {
            int newRow=i+mv[1];
            int newCol=j+mv[0];
            
            if(find(board, newRow, newCol, word, ind+1))
                return true;
        }
        
        board[i][j]=temp;
        
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word)
    {
        rows=board.size();
        cols=board[0].size();
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(board[i][j]==word[0] && find(board, i, j, word, 0))
                    return true;
            }
        }
        
        return false;
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