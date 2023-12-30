#include<bits/stdc++.h>
using namespace std;

// BruteForce, To get min out of all the elements will find all the min elements.

// Better, All theree methods are using a common extra space of O(N)

class Solution
{
    int minEle=INT_MAX;
    stack<pair<int, int>> st;

    public:
    
       int getMin()
       {
            if(st.size()==0)
                return -1;

            auto mostMin=st.top();

            return mostMin.second;
       }
       
       int pop()
       {
            if(st.size()==0)
                return -1;

            int currentMin=st.top().second;
            int currentTop=st.top().first;
            st.pop();

            if(st.size()==0)
                minEle=INT_MAX;
            else if(currentMin==currentTop)
            {
                minEle=st.top().second;
            }
            // else if(currentTop>currentMin)
            //     // Nothing to do
            // else if(currentTop<currentMin)
            //     // Not possiable
                
            return currentTop;
       }
       
       void push(int x)
       {
          minEle=min(minEle, x);
          st.push({x, minEle}); 
       }
};

// Optimal, To be done

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}