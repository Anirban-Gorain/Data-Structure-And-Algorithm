#include<bits/stdc++.h>
using namespace std;

int solve(int k, int n, int sum, vector<vector<int>> &ans, vector<int> set, int i)
{
    if(set.size()==k)
    {
        if(sum==n)
        {
            ans.push_back(set);
            return 1;
        }
        else
            return 0;
    }
    if(sum>n)
    {
        return 0;
    }
    if(i>9)
        return 0;
        
    set.push_back(i);
    int left=solve(k, n, sum+i, ans, set, i+1);
    
    set.pop_back();
    int right=solve(k, n, sum, ans, set, i+1);
    
    int mod=(1e9+7);
    
    return (left%mod + right%mod)%mod;
}

vector<vector<int>> combinationSum(int k, int n)
{
    vector<vector<int>> ans;
    
    solve(k, n, 0, ans, {}, 1);
    
    return ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}