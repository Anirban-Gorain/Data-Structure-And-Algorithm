#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, int ind, vector<int> set, vector<vector<int>> &ans)
{
    // if(sum>target)
    //     return;
    if(0==target)
    {
        ans.push_back(set);
        return;
    }
    
    int n=candidates.size();
    
    for(int i=ind; i<n; i++)
    {
        if((i>ind) && candidates[i]==candidates[i-1])
            continue;
            
        if(candidates[i]>target)
            return;
            
        set.push_back(candidates[i]);
        solve(candidates, target-candidates[i], i+1, set, ans);
        set.pop_back();
    }
    
    return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;

    sort(candidates.begin(), candidates.end());
    
    vector<int> ds;
    
    solve(candidates, target, 0, ds, ans);

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