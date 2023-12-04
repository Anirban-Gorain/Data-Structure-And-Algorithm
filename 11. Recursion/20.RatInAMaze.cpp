#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void solve(vector<vector<int>> &m, int n, int i, int j, string path, vector<string> &ans)
    {
        if(i<0 || j<0 || i==n || j==n || m[i][j]==0 || m[i][j]==-1)
            return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        for(int ind=0; ind<4; ind++)
        {
            if(ind==0)
                path.push_back('R');
            else if(ind==1)
                path.push_back('L');
            else if(ind==2)
                path.push_back('D');
            else
                path.push_back('U');
                
            int temp=m[i][j];
            m[i][j]=-1;
                
            int newI=i+dir[ind][0];
            int newJ=j+dir[ind][1];
            
            solve(m, n, newI, newJ, path, ans);
            
            m[i][j]=temp;
            path.pop_back();
        }
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        
        solve(m, n, 0, 0, {}, ans);
        
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