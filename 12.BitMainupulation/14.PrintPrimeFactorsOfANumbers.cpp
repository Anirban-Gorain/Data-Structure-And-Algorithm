#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:-O(n), AS:-O(1)

// Optimal, TC:-O(sqrt(n)), AS:-O(1)

vector<int> getAllPrimeFactors(int n)
{
    vector<int> ans;
    
    for(int i=2; i*i<=n, n>1; i++)
    {
        while((n%i)==0)
        {
            ans.push_back(i);
            n=n/i;
        }
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