#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/contest/job-a-thon-28-hiring-challenge-for-freshers/problems

// Optimal, TC:-O(n+q*log(n)), AS:-O(n)

class Solution
{
    public:

    bool isLyingInRange(vector<int> sp, int l, int r)
    {
        int low=0, high=sp.size()-1;

        while(low<=high)
        {
            int mid=low-(low-high)/2;

            if(sp[mid]>=l && sp[mid]<=r)
                return true;
            else if(sp[mid]<l)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return false;
    }

    vector<int> findTheRing(int n, int q, vector<int> arr, vector<vector<int>> que) 
    {
        vector<vector<int>> val(201);
        vector<int> ans;

        int ind=0;

        for(int x : arr)
        {
            if(x>=0)
                val[x].push_back(ind);
            else
                val[100-x].push_back(ind);

            ind++;
        }

        for(auto q : que)
        {
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int need=r-l-k;

            if(need>=-100 && need<=100)
            {
                ind=(need>=0)?need:(100-need);
                ans.push_back(isLyingInRange(val[ind], l, r));
            }
        }

        return ans;
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