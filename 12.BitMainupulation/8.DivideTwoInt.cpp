#include<bits/stdc++.h>
using namespace std;

// BruteForce

// Better

long long divide(long long dividend, long long divisor) 
{
    long long low=1, high=1e9, ans;
    
    while(low<=high)
    {
        long long mid=low-(low-mid)/2;
        
        if(mid*abs(divisor)<=abs(dividend))
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    
    return ((dividend<0 && divisor<0) || (dividend>0 && divisor>0))?ans:-1*ans;
}

// Optimal


int divide(int dividend, int divisor)
{
    if(dividend==divisor)
        return 1;

    bool ispositive=(dividend<0 == divisor<0);

    long long a=abs(dividend);
    long long b=abs(divisor);
    long long ans=0;

    while(a>=b)
    {
        int temp=0;

        while((b<<(temp+1))<a)
            temp++;

        ans=ans+(1<<temp);
        a=a-(b<<temp);
    }

    ans=(ispositive)?ans:-ans;

    if(ans>pow(2, 31)-1)
        return pow(2, 31)-1;
    if(ans<-pow(2, 31))
        return -pow(2, 31);

    return ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    return 0;

}