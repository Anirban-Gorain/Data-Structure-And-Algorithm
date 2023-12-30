#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    bool isOperand(char ch)
    {
        if((ch>='0' & ch<='9') || (ch>='A' & ch<='Z') || (ch>='a' & ch<='z'))
            return true;

        return false;
    }
    
    string preToPost(string pre_exp)
    {
        stack<string> st;
        string ans;
        int len=pre_exp.length();
        
        for(int i=len-1; i>=0; i--)
        {
            char ch=pre_exp[i];
            
            if(isOperand(ch))
            {
                string temp="";
                temp+=ch;
                st.push(temp);
            }
            else
            {
                string pop1=st.top(); st.pop();
                string pop2=st.top(); st.pop();
                
                string construct=pop1+pop2+ch;
                st.push(construct);
            }
        }
        
        return st.top();
    }
};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}