#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    static bool comp(pair<int, int> x1, pair<int, int> x2)
    {
        if(x1.first==x2.first)
            return x1.second<x2.second;

        return x1.first>x2.first;
    }

    vector<int> topK(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;
    
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]]++;
    
        vector<pair<int, int>> store;
    
        for(auto elem : freq)
        {
            int frequency=elem.second;
            int element=elem.first;
            store.push_back({frequency, element});
        }
    
        sort(store.begin(), store.end(), comp);
        
        vector<int> send;
        
        for(int i=1; i<=k; i++)
            send.push_back(store[i-1].second);
            
        return send;
    }
};



//{ Driver Code Starts.
int main() {

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif
    
    return 0;
}