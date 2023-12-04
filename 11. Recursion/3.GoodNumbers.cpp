#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

long long power(long long N, long long R)
{
    
    if(R==0)
        return 1;
    if(N==0)
        return 0;
        
    long long temp=power(N, R/2);
    
    if(R%2==0)
        return (temp%mod * temp%mod)%mod;
    
    return (temp%mod * temp%mod * N%mod)%mod;
}

int countGoodNumbers(long long N)
{
    // if(N==1)
    //     return 5;
    
    long long evens, odds;
    // N++;
    
    if((N%2LL)==0)
    {
        evens=odds=N/2LL;
    }
    else
    {
        evens=(N/2LL)+1LL;
        odds=N/2LL;
    }
    
    long long temp1=power(5, evens);
    long long temp2=power(4, odds);
    
    return (temp1%mod * temp2%mod)%mod;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<countGoodNumbers(2);

    return 0;

}