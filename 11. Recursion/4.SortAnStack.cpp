#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void insert(stack<int> &s, int num)
{
    if(s.size()==0)
    {
        s.push(num);
        return;
    }
        
    int tpElem=s.top();
    
    if(tpElem>num)
    {
        s.pop();
        insert(s, num);
    }
    else
    {
        s.push(num);
        return;
    }
        
    s.push(tpElem);
    return;
}

void sort()
{
    if(s.size()==1)
        return;
    
    int tpElem=s.top();
    s.pop();
    sort();
    insert(s, tpElem);
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}