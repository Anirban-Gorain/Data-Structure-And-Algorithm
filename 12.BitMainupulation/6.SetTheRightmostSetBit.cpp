#include<bits/stdc++.h>
using namespace std;

// BruteForce

int setBit(int n)
{
    int pos=0;
    int cpy=n;
    
    while(n&1)
    {
        pos++;
        n=n>>1;
    }
    
    n=cpy;
    
    if((n>>pos)==0)
        return n;
        
    n=n|(1<<pos);
    
    return n;
}

// Optimal

int setBit(int n)
{
    if(!(n&(n+1)))
        return n;
        
    return n|(n+1);
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}