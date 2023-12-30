#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    long long f(long long x,int n,vector<int> &length,vector<int> &cost)
    {
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            ans+=abs(length[i]-x)*cost[i];
        }
        return ans;
    }

    long long minimumCost(int n,vector<int> length,vector<int> cost){

        long long s = *min_element(length.begin(), length.end());
        long long e = *max_element(length.begin(), length.end());
        long long ans = 1e15;

        while(s<=e)
        {
            long long mid = (s+e)/2;
            long long x = f(mid,n,length,cost);
            long long y = f(mid+1,n,length,cost);

            ans = min({ans, x, y});

            if(y>x)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
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