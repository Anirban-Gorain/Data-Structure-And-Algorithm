#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int q, len=s.length();
    cin >> q;

    // Pre-computation
    
    int hash[26]={0};
    for(int i=0; i<len; i++)
    {
        int charToIndex=s[i]%97;
        hash[charToIndex]++;
    }

    while(q--)
    {
        char t;
        cin >> t;

        // Fetching

        cout << hash[t%97] << " ";
    }

    return 0;
}