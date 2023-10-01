#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^3), AS:-O(26)
// Better, TC:-O(n^2), AS:-O(26)

long long int substrCount (string s, int k)
{
    int n=s.length();
    int count=0;
    unordered_set<char> st;

    for(int i=0; i<n; i++)
    {
        string str;
        for(int j=i; j<n; j++)
        {
            str=str+s[i];
            st.insert(s[j]);

            if(st.size()==k)
            {
                count++;
                // cout<<str<<"\n";
            }
            else if(st.size()>k)
            {
                // cout<<str<<"\n";
                st.clear();
                break;
            }
        }
        st.clear();
    }

    return count;
}

// Optimal, TC:-O(n*k) Where k<n, AS:-O(26)

long long int countAtMost (string &s, int k)
{
    int count=0, n=s.length();
    int left=0, right=0, distinct=0;
    int mp[26]={0};

    while(right<n)
    {
        if(mp[s[right]-'a']==0)
            distinct++;
            
        mp[s[right]-'a']++;

        while(distinct>k)
        {
            mp[s[left]-'a']--;

            if(mp[s[left]-'a']==0)
                distinct--;

            left++;
        }

        count+=(right-left+1);
        right++;
    }

    return count;
}

long long substrCount(string s, int k)
{
    return countAtMost(s, k)-countAtMost(s, k-1);
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}