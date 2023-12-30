#include<bits/stdc++.h>
using namespace std;

// NGE variation 1 (Non-Circular)
// BruteForce, TC:-O(n^2), AS:-O(1)

// Optimal, TC:-O(n), AS:-O(n), Implementation-1

class Solution
{
    public:

    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Right to Left.
        
        stack<long long> st;
        vector<long long> NGE(n, -1);
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[i]>=st.top())
                st.pop();
            
            if(!st.empty())
                NGE[i]=st.top();
            else
                NGE[i]=-1;
                
            st.push(arr[i]);
        }
        
        return NGE;
    }
};

// Optimal, TC:-O(n), AS:-O(n), Implementation-2

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> st;
    vector<long long> NGE(n, -1);
    
    for(int i=0; i<n; i++)
    {
        // if(st.empty())
        // {
        //     st.push(i);
        //     continue;
        // }
            
        while(!st.empty() && arr[i]>arr[st.top()])
        {
            NGE[st.top()]=arr[i];
            st.pop();
        }
        
        st.push(i);
    }
    
    // Remaining elements of the stack has no NGE.
    
    return NGE;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}