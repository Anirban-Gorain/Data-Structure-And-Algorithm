#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^3), AS:-O(1)
// Better, TC:-O(n^2), AS:-O(n^2) => Using DP;

// Optimal, TC:-O(n^2), AS:-O(1)

string longestPalindrome(string S)
{
    int len=S.size();
    int maxLen=1;
    string ans;
    ans+=S[0];
    
    for(int i=0; i<len; i++)
    {
        // Checking for even length.
        
        int low=i-1; int high=i;
        
        while(low>=0 && high<len && S[low]==S[high])
        {
            int currentLen=high-low+1;
            
            if(currentLen>maxLen)
            {
                maxLen=currentLen;
                ans=S.substr(low, currentLen);
            }
            
            low--;
            high++;
        }
        
        // Checking for odd length.
        
        low=i-1; high=i+1;
        
        while(low>=0 && high<len && S[low]==S[high])
        {
            int currentLen=high-low+1;
            
            if(currentLen>maxLen)
            {
                maxLen=currentLen;
                ans=S.substr(low, currentLen);
            }
            low--;
            high++;
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