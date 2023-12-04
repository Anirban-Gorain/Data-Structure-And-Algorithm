#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int ind, vector<vector<int>> &ans, vector<int> set)
{
    ans.push_back(set);
    for(int i=ind; i<nums.size(); i++)
    {
        if(i>ind && nums[i]==nums[i-1])
            continue;
        
        
        set.push_back(nums[i]);
        solve(nums, i+1, ans, set);
        set.pop_back();
    }
    
    return;
}

vector<vector<int>> printUniqueSubsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    // ans.push_back({});
    
    sort(nums.begin(), nums.end());
    solve(nums, 0, ans, {});
    
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