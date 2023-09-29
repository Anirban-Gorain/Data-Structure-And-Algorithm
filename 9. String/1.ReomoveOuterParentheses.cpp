#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    int openCnt=0, closeCnt=0, n=s.length(), start=0, end=0;
    string res;

    while(end<n)
    {
        if(s[end]=='(')
            openCnt++;
        else if(s[end]==')')
            closeCnt++;
        
        if(openCnt==closeCnt && (openCnt!=0))
        {
            openCnt=0;
            closeCnt=0;
            res=res+s.substr(start+1, end-start-1);

            start=end+1;
        }

        end++;
    }

}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    string s;
    cin>>s;
    string ans=removeOuterParentheses(s);
    cout<<ans;

    return 0;

}