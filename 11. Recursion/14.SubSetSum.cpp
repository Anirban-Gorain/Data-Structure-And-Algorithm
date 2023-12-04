#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int ind, int sum, vector<int> &ans)
{
    if(ind==arr.size())
    {
        ans.push_back(sum);
        return;
    }
    
    solve(arr, ind+1, sum+arr[ind], ans);
    solve(arr, ind+1, sum, ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    
    solve(arr, 0, 0, ans);
    
    sort(ans.begin(), ans.end());
    
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