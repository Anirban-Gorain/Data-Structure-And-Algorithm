#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n), AS:-O(n)

int maxDepth(string s)
{
    stack<char> order;
    int len=s.length();
    int maxDepth=INT_MIN;

    for(int i=0; i<len; i++)
    {
        if(s[i]=='(')
            order.push('(');
        else if(s[i]==')')
        {
            int depth=order.size();
            maxDepth=max(maxDepth, depth);

            if(depth>0)
                order.pop();
        }
    }

    return (order.size()!=0)?-1:maxDepth;
}

// Optimal, TC:-O(n), AS:-O(1)

int maxDepth(string s)
{
    int noOFopenings=0;
    int len=s.length();
    int maxDepth=INT_MIN;

    for(int i=0; i<len; i++)
    {
        if(s[i]=='(')
            noOFopenings++;
        else if(s[i]==')')
        {
            maxDepth=max(maxDepth, noOFopenings);

            if(noOFopenings>0)
                noOFopenings--;
            else
                return -1;
        }
    }

    return (noOFopenings!=0)?-1:maxDepth;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<maxDepth("((5+2)(c+e)((a)))");

    return 0;

}