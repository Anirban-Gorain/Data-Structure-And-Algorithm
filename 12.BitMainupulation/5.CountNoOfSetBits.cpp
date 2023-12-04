#include<bits/stdc++.h>
using namespace std;

int setBits(int n)
{
    int ans=0;
    
    while(n>0)
    {
        if(n&1)
            ans++;
            
        n=n>>1;
    }
    
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