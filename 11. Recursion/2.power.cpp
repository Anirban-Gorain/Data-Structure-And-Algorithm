#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) 
{
    double ans;
    ans=getPow(abs(x), abs(n));

    if(n<0)
    {
        ans=1/ans;
    }

    if(x<0 && n%2!=0)
        ans=ans*-1l;

    return ans;
}

double getPow(double x, int n) 
{
    if(x==0)
        return 0;
    if(n==0)
        return 1;

    double temp=getPow(x, n/2);

    return (n%2==0)?temp*temp:temp*temp*x;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}