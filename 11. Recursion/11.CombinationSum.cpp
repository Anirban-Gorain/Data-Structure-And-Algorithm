#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int ind, int sum, int tillSum, vector<int> elements, vector<vector<int>> &ans)
{
    if(tillSum==sum)
    {
        ans.push_back(elements);
        return;
    }
    else if(tillSum>sum)
    {
        return;
    }
    else if(ind==arr.size())
    {
        return;
    }
    
    elements.push_back(arr[ind]);
    solve(arr, ind, sum, tillSum+arr[ind], elements, ans);
    
    elements.pop_back();
    solve(arr, ind+1, sum, tillSum, elements, ans);   
}
    
vector<vector<int>> combinationSum(vector<int> &arr, int sum) 
{
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int bucket=0;
    
    for(int i=1; i<n; i++)
    {
        if(arr[bucket]!=arr[i])
        {
            bucket++;
            arr[bucket]=arr[i];
        }
    }
    
    arr.erase(arr.begin()+1+bucket, arr.end());
    
    vector<vector<int>> ans;

    solve(arr, 0, sum, 0, {}, ans);
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