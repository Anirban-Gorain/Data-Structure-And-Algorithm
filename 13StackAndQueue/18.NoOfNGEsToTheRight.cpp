#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    // Brute-Force, TC:-O(n*q), AS:-O(1)

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> NGEs;
        
        for(int i=0; i<queries; i++)
        {
            int elem=arr[indices[i]];
            int cnt=0;
            
            for(int j=(indices[i]+1); j<n; j++)
            {
                if(elem<arr[j])
                    cnt++;
            }
            
            NGEs.push_back(cnt);
        }
        
        return NGEs;
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