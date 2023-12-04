#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:-O(n), AS:-O(1)

int findXOR(int l, int r)
{
    int ans=0;
    
    for(int i=0; i<32; i++)
    {
        int cnt=0;
        
        for(int j=l; j<=r; j++)
        {
            if(((j&(1<<i)))!=0)
                cnt++;
        }
        
        cnt=cnt%2;
        
        ans=ans|(cnt<<i);
    }
    
    return ans;
}

// Optimal, TC:-O(1), AS:-O(1)

int XOROfOneToN(int n)
{
    if(n%4==1)
        return 1;
    else if(n%4==2)
        return n+1;
    else if(n%4==3)
        return 0;

    return n;
}

int findXOR(int l, int r)
{
    return XOROfOneToN(l-1)^XOROfOneToN(r);
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}