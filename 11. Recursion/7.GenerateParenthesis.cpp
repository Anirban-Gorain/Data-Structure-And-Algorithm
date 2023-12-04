#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(), AS:-O()

bool areBracketsBalanced(string s)
{
        int i=-1;
        for(auto& ch:s){
            if(ch=='(' || ch=='{' || ch=='[')
                s[++i]=ch;
            else{
                if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
                    i--;
                else
                    return false;
            }
        }
        return i==-1;
}
    
void solve(int n, string ans, vector<string> &allAns)
{
    if(ans.length()==2*n)
    {
        
        if(areBracketsBalanced(ans))
        {
            allAns.push_back(ans);
        }
        
        return;
    }
    
    ans.push_back('(');
    solve(n, ans, allAns);
    
    ans.pop_back();
    
    ans.push_back(')');
    solve(n, ans, allAns);
    
    return;
}

vector<string> AllParenthesis(int n) 
{
    vector<string> allAns;
    solve(n, "", allAns);
    
    return allAns;
}

// Optimal, TC:-O(), AS:-O()

void solve(int n, string ans, int openings, int closings, vector<string> &allAns)
{
    if(ans.length()==2*n)
    {
        
        allAns.push_back(ans);
        return;
    }
    
    if(openings<n)
    {
        ans.push_back('(');
        solve(n, ans, openings+1, closings, allAns);
        ans.pop_back();
    }
    
    
    if(closings<openings)
    {
        ans.push_back(')');
        solve(n, ans, openings, closings+1,  allAns);
    }
    
    return;
}

vector<string> AllParenthesis(int n) 
{
    vector<string> allAns;
    solve(n, "", 0, 0, allAns);
    
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