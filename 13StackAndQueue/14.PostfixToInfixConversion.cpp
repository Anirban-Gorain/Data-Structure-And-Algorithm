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

    string postToInfix(string pre_exp)
    {
        stack<string> st;
        string ans;
        int len=pre_exp.length();
        
        for(int i=0; i<len; i++)
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
                // if ch is a operator

                string pop2=st.top(); st.pop();
                string pop1=st.top(); st.pop();

                st.push("("+pop1+ch+pop2+")");
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