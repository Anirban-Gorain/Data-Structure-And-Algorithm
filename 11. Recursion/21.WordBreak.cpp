#include<bits/stdc++.h>
using namespace std;

bool solve(unordered_set<string> dic, int ind, string A)
{
    if(A.length()==ind)
        return true;
        
    for(int i=ind; i<A.length(); i++)
    {
        string subStr=A.substr(ind, i-ind+1);
        
        if(dic.find(subStr)!=dic.end() && solve(dic, i+1, A))
        {
            return true;
        }
    }
    
    return false;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> dic(B.begin(), B.end());
    
    return solve(dic, 0, A);
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}