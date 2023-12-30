#include<bits/stdc++.h>
using namespace std;

// Infix to Postfix --

int precedence(char x)
{
    if(x=='^')
        return 3;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    
    return -1; // For parenthesis.
}


string infixToPostfix(string s)
{
    string ans;
    stack<char> st;
    int len=s.length();

    for(int i=0; i<len; i++)
    {

        char ch=s[i];

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='1' && ch<='9'))
            ans.push_back(ch);
        else if(ch=='(')
            st.push(ch);
        else if(ch==')')
        {
            while (st.top()!='(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(st.empty()==1 || (precedence(st.top())<precedence(ch)))
                st.push(ch);
            else
            {
                while (st.empty()!=1 && precedence(st.top())>=precedence(ch)) 
                {
                    ans.push_back(st.top());
                    st.pop();
                }

                st.push(ch);
            }

        }
    }

    while (st.empty()!=1) 
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");

    return 0;

}