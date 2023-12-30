#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:-O(n^2), AS:-O(1)

// Optimal, TC:-O(n), AS:-O(n), Im-1

vector<int> help_classmate(vector<int> arr, int n) 
{ 
    stack<int> st;
    vector<int> NSE(n);
    
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()>=arr[i])
            st.pop();
            
        if(st.empty())
            NSE[i]=-1;
        else
            NSE[i]=st.top();
            
        st.push(arr[i]);
    }
    
    return NSE;
}

// Optimal, TC:-O(n), AS:-O(n), Im-2

vector<int> help_classmate(vector<int> arr, int n) 
{ 

    stack<int> st;
    vector<int> NSE(n, -1);
    
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            NSE[st.top()]=arr[i];
            st.pop();
        }
        
        st.push(i);
    }
    
    return NSE;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}