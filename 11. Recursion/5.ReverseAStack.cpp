#include<bits/stdc++.h>
using namespace std;

void insertAtLast(stack<int> &st, int num)
{
    if(st.size()==0)
    {
        st.push(num);
        return;
    }
    
    int tpElem=st.top();
    st.pop();
    
    insertAtLast(st, num);
    
    st.push(tpElem);
    
    return;
}

void Reverse(stack<int> &st)
{
    if(st.size()==0)
        return;
        
    int tpElem=st.top();
    st.pop();
    
    Reverse(st);
    insertAtLast(st, tpElem);
    
    return;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}