#include<bits/stdc++.h>
using namespace std;

// Using recursion

void solve(string &s, int ind, vector<string> &ans)
{
    if((ind)==s.length())
    {
        ans.push_back(s);
        return;
    }
    
    if(s[ind]=='?')
    {
        s[ind]='0';
        solve(s, ind+1, ans);
        s[ind]='1';
        solve(s, ind+1, ans);
        s[ind]='?';
    }
    else
    {
        solve(s, ind+1, ans);
    }
    
    return;
}

vector<string> generate_binary_string(string s)
{
    vector<string> ans;
    solve(s, 0, ans);
    
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