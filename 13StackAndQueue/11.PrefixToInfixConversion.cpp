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

    string preToInfix(string pre_exp)
    {
        stack<string> st;
        string ans;

        for(int i=pre_exp.length()-1; i>=0; i--)
        {
            char ch=pre_exp[i];

            string temp="";
            temp+=ch;

            if(isOperand(ch))
                st.push(temp);
            else
            {
                // if ch is a operator

                string pop1=st.top(); st.pop();
                string pop2=st.top(); st.pop();

                string constructEx="("+pop1+ch+pop2+")";
                st.push(constructEx);
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