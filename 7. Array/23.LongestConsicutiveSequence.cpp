#include<bits/stdc++.h>
using namespace std;

//BruteForce, TC:- O(n*n*lcs), AS:- O(1)

bool linearSearch(vector<int> &arr, int len, int elem)
{
    for(int i=0; i<len; i++)
    {
        if(arr[i]==elem)
            return true;

    }
    return false;
}

int longestSuccessiveElements(vector<int> &arr)
{
    int len=arr.size();
    int lcs=0;

    for(int i=0; i<len; i++)
    {
        int elem=arr[i]+1;
        int currentLCSLen=1;

        while(linearSearch(arr, len, elem))
        {
            currentLCSLen++;
            elem++;
        }

        lcs=max(currentLCSLen, lcs);
    }

    return lcs;
}

// Better, TC:- O(nlogn), AS:- O(1)

int longestSuccessiveElements(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int lcs=0;
    int count=1;
    int len=arr.size();
    int lastElem=-1; // It can be vary base on the constrain.
    
    for(int i=0; i<len; i++)
    {
        if((arr[i]-1)==lastElem)
        {
            count++;
        }
        else if(arr[i]!=lastElem)
        {
            count=1;
            lcs=max(lcs, count);
        }

        lastElem=arr[i];

    }

    return max(lcs, count);
}

// Optimal, TC:- O(n), AS:- O(n)

int longestSuccessiveElements(vector<int> &arr)
{
    int len=arr.size();
    int lcs=0;
    unordered_set<int> st(arr.begin(), arr.end());

    for(int i=0; i<len; i++)
    {

        int currentLCSLen=1;
        
        if(st.find(arr[i]-1)==st.end())
        {
            int elem=arr[i]+1;
            while(st.find(elem)!=st.end())
            {
                currentLCSLen++;
                elem++;
            }
        }

        lcs=max(currentLCSLen, lcs);
    }

    return lcs;
}