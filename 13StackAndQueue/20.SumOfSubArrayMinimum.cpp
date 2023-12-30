#include<bits/stdc++.h>
using namespace std;

// Brute, TC:-O(n^3), AS:-O(1)

// Generate all the the Subarrays.

// Better, TC:-O(n), AS:-O(2n)

// https://practice.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

int sumSubarrayMins(int n, vector<int> arr)
{

    int sum=0;
    vector<int> left(n);
    vector<int> right(n);
    stack<pair<int, int>> st; // <arr[i], cnt>

    for(int i=0; i<n; i++)
    {
        int cnt=1;

        while(!st.empty() && arr[i]<arr[st.top().first])
        {
            cnt+=st.top().second;
            st.pop();
        }

        st.push({i, cnt});
        left[i]=cnt;
    }

    while(!st.empty())
        st.pop();

    for(int i=n-1; i>=0; i--)
    {
        int cnt=1;

        while(!st.empty() && arr[i]<=arr[st.top().first])
        {
            cnt+=st.top().second;
            st.pop();
        }

        st.push({i, cnt});
        right[i]=cnt;
    }

    int m=1e9+7;

    for(int i=0; i<n; i++)
    {
        int mul=left[i]*right[i]*arr[i];
        sum=(sum%m+mul%m)%m;
    }

    return sum;
}

// Optimal, TC:-O(n), AS:-O(n)

// https://leetcode.com/problems/sum-of-subarray-minimums/solutions/2118729/very-detailed-stack-explanation-o-n-images-comments/
// https://leetcode.com/problems/sum-of-subarray-minimums/solutions/1405264/c-monotonic-stack-detailed-explanation/

class Solution
{
    public:

    int sumSubarrayMins(int n, vector<int> arr)
    {
        stack<int> st;
        st.push(-1);
        arr.push_back(0);
        n++;

        int sum=0;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top()!=-1 && arr[i]<arr[st.top()])
            {
                // We are considering the Subarray in which st.top() will be the minimum.

                int m=1e9+7;

                int tp=st.top(); st.pop();
                int left=tp-st.top();
                int right=i-tp;
                int mul=left*right*arr[tp];
                sum=(sum%m+mul%m)%m;
            }

            st.push(i);
        }

        return sum;
    }
};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    sumSubarrayMins(5, {2, 3, 8, 6, 2});

    return 0;
}