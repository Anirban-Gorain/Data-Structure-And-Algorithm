#include<bits/stdc++.h>
using namespace std;

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

// This follwing is not exctly Infix to Postfix one condition has been changed slidly that we will pop the operators only when st.top()>CurrentOperatorPrecedence which we used to do when st.top()>=CurrentOperatorPrecedence.

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
                while (st.empty()!=1 && precedence(st.top())>precedence(ch)) 
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

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for(char &x : s)
    {
        if(x=='(')
            x=')';
        else if(x==')')
            x='(';
    }

    string prefix=infixToPostfix(s);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<infixToPrefix("(A-B/C)*(A/K-L)");

    return 0;

}