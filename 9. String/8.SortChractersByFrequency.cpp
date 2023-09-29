#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^2), AS:-O(n)

// Optimal, TC:-O(n*log(n)), AS:-O(n)

bool comp(pair<int, char> p1, pair<int, char> p2)
{
    if(p1.first>p2.first)
        return true;
    else if(p1.first<p2.first)
        return false;


    return (p1.second>p2.second);
}

string frequencySort(string s)
{
    unordered_map<char, int> freq;
    int n=s.length();

    for(int i=0; i<n; i++)
        freq[s[i]]++;

    vector<pair<int, char>> store;

    for(auto it : freq)
    {
        char elem=it.first;
        int freqCount=it.second;

        store.push_back(make_pair(freqCount, elem));
    }

    sort(store.begin(), store.end(), comp);

    int len=store.size();
    string ans;

    for(int i=0; i<len; i++)
    {
        char elem=store[i].second;
        int freqCount=store[i].first;

        for(int j=0; j<freqCount; j++)
            ans+=elem;
    }

    return ans;
}

// Optima, TC:-O(n*log(n)), AS:-O(n)

// Using priority queue.

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<frequencySort("geeksforgeeks");

    return 0;

}