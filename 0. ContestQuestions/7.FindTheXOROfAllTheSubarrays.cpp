#include<bits/stdc++.h>
using namespace std;

// Find the XOR of All the sub-arrays.

class Solution
{
    public:

    int gameOfXor(int N , int A[]) 
    {
        int ans=0;
        
        for(int i=0; i<N; i++)
        {
            long long noOfOcc=(i+1)*(N-(i+1)+1);
            ans^=(noOfOcc%2==0)?0:A[i];
        }
        
        return ans;
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