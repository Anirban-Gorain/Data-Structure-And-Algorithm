#include<bits/stdc++.h>
using namespace std;

// Brute force, TC:-O(n^3) AS:- O(1)

// Three nested loop based sol.

// Better, TC:-O(n^2) AS:- O(1)

// Two nested loop based sol.

// Optimal, TC:-O(n) AS:- O(n)

int subarraysWithSumK(vector < int > arr, int k)
{
    unordered_map<int, int> prefixXOR; // (XOR, Index)
    int len=arr.size();
    int XOR=0;
    int count=0;

    for(int i=0; i<len; i++)
    {
        XOR=XOR^arr[i];

        if(XOR==k)
            count++;

        if(prefixXOR.find(XOR^k)!=prefixXOR.end())
        {
            count=count+prefixXOR[XOR^k];
        }

        prefixXOR[XOR]++;
    }

    return count;
}