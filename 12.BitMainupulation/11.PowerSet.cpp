#include<bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    
    for(int i=0; i<(1<<s.length()); i++)
    {
        string subAns;
        
        for(int j=0; j<s.length(); j++)
        {
            if((i&(1<<j))!=0)
                subAns.push_back(s[j]);
        }
        
        if(subAns.length()>0)
            ans.push_back(subAns);
            
        subAns.clear();
    }
    
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