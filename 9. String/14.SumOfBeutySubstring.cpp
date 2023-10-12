#include<bits/stdc++.h>
using namespace std;

int beautySum(string s)
{
    int n=s.length();
    int sum=0;

    for(int start=0; start<n; start++)
    {
        int freq[26]={0};

        for(int end=start; end<n; end++)
        {
            int lFreq=INT_MAX, hFreq=INT_MIN;
            freq[s[end]-'a']++;

            for(int i=0; i<26; i++)
            {
                
                if(freq[i]!=0)
                {
                    lFreq=min(lFreq, freq[i]);
                    hFreq=max(hFreq, freq[i]);
                }
            }

            sum+=(hFreq-lFreq);
        }
    }

    return sum;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<beautySum("fsk");

    return 0;

}