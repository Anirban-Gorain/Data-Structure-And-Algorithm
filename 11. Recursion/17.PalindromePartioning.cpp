#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    while(start<=end)
        if(str[start++]!=str[end--])
            return false;

    return true;
}

void solve(string str, int start, vector<vector<string>> &ans, vector<string> possiableAns)
{
    if(str.length()==start)
    {
        ans.push_back(possiableAns);
        return;
    }

    for(int i=start; i<=str.length(); i++)
    {
        if(isPalindrome(str, start, i))
        {
            possiableAns.push_back(str.substr(start, i-start+1));
            solve(str, i+1, ans, possiableAns);
            possiableAns.pop_back();
        }
    }

    return;
}

vector<vector<string>> partition(string str)
{
    vector<vector<string>> ans;

    solve(str, 0, ans, {});

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