#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n)
{
    if(n==0)
        return 0;
    
    return !(n&(n-1));
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}