#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:-O(n^2), AS:-O(1)

// Optimal, TC:-O(n), AS:-O(n)

class Solution
{
    public:

    vector<int> nextGreaterElement(int N, vector<int>& arr) 
    {
        stack<int> st;
        vector<int>NGE(N, -1);
        
        for(int i=0; i<2*N; i++)
        {
            while(!st.empty() && arr[i%N]>arr[st.top()])
            {
                NGE[st.top()]=arr[i%N];
                st.pop();
            }
            
            st.push(i%N);
        }
        
        return NGE;
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