#include<bits/stdc++.h>
using namespace std;

#define max (5*(1e6)+1)
#define ll long long
vector<int> sieve(max, 1);


class Solution
{
    public:

    int countPrimes(int n)
    {
        sieve[0]=sieve[1]=0;

        for(ll i=2; i<n; i++)
        {
            for(ll j=i*i; j<n; j=j+i)
                sieve[j]=0;
        }

        int cnt=0;

        for(int i=0; i<n; i++)
            if(sieve[i]==1)
                cnt++;
        
        return cnt;
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