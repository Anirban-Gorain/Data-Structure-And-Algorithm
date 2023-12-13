#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:-O(n), AS:-O(1)
// Better, TC:-O(lgn(n)), AS:-O(n)


// Optimal, TC:-O(log(n)), AS:-O(1)

int power(long long N, long long R)
{
    int m=1e9+7;
    long long res=1;

    while(R>0)
    {
        if((R&1)!=0)
        {
            res=(res%m * N%m)%m;
        }

        N=(N%m * N%m)%m;

        R=R>>1;
    }

    return res;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}