#include<bits/stdc++.h>
using namespace std;

string get(int num)
{
    unordered_map<int, string> mp;

    mp.insert({2, "abc"});
    mp.insert({3, "def"});
    mp.insert({4, "ghi"});
    mp.insert({5, "jkl"});
    mp.insert({6, "mno"});
    mp.insert({7, "pqrs"});
    mp.insert({8, "tuv"});
    mp.insert({9, "wxyz"});
    
    return mp[num];
}

void solve(int a[], int ind, int n, string iMAns, vector <string> &ans)
{
    if(ind==n)
    {
        ans.push_back(iMAns);
        return;
    }
        
    string str=get(a[ind]);
        
    for(char ch : str)
    {
        iMAns.push_back(ch);
        solve(a, ind+1, n, iMAns, ans);
        iMAns.pop_back();
    }
}

vector<string> possibleWords(int a[], int N)
{
    vector<string> ans;
    solve(a, 0, N, "", ans);
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