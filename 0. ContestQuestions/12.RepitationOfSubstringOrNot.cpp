#include<bits/stdc++.h>
using namespace std;

int kSubstrConcat (int n, string s, int k)
{
    if(n%k!=0)
        return false;
    
    unordered_map<string, int> freq;
    
    for(int i=0; i<n; i+=k)
    {
        string subStr=s.substr(i, k);
        freq[subStr]++;
    }
    
    int atleast=ceil((float)n/((float)2*float(k)));
    
    for(auto elem : freq)
    {
        if(elem.second>=atleast)
            return true;
    }
    
    return false;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<kSubstrConcat(20, "", 4);

    return 0;

}