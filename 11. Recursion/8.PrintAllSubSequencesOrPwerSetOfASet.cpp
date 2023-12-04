#include<bits/stdc++.h>
using namespace std;

// Using recursion

void solve(string s, string ans, int ind, vector<string> &allAns)
{
    if(ind==s.length())
    {
        if(ans.length()>0)
            allAns.push_back(ans);
        
        return;
    }
    
    
    ans.push_back(s[ind]);
    solve(s, ans, ind+1, allAns);
    ans.pop_back();
    solve(s, ans, ind+1, allAns);
    
    return;
}

vector<string> AllPossibleStrings(string s)
{
    vector<string> allAns;
    
    
    solve(s, "", 0, allAns);
    
    sort(allAns.begin(), allAns.end());
    return allAns;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}