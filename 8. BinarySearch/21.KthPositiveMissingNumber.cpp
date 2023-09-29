#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:- O(n^2) AS:- O(k)

int missingK(vector < int > vec, int n, int k)
{
    vector<int> possibleAns(k);
    int n=vec.size();

    for(int i=1; i<=10e9; i++)
    {
        bool isFound=false;

        for(int j=0; j<n; j++)
        {
            if(vec[j]==i)
                isFound=true;
        }

        if(isFound==false) // Element not found
        {
            possibleAns.push_back(i);

            if(possibleAns.size()==k)
                return possibleAns[k-1];
        }
    }

    return -1;
}

// Better, TC:- O(0e9) For unordered_set / O(10e9*log(n)) for set AS:- O(n)

int missingK(vector < int > vec, int n, int k)
{
    unordered_set<int> vecCpy(vec.begin(), vec.end());

    for(int i=1; i<=10e9; i++)
    {
        if(vecCpy.find(i)==vecCpy.end())
            k--;

        if(k==0)
            return i;
    }

    return -1;
}



int missingK(vector < int > arr, int n, int k)
{

    if(arr[0]>k)
        return k;

    int low=0, high=n-1;
    int indRequired;

    while(low<=high)
    {

        int mid=low-(low-high)/2;

        // Total number of numbers from 1 to arr[mid], including arr[mid]

        int numbersBefore=arr[mid]-(mid+1);

        if(numbersBefore>k)
        {
            high=mid-1;
        }
        else
        {
            indRequired=mid;
            low=mid+1;
        }
    }

    int ans=arr[indRequired]+(k-(arr[indRequired]-indRequired-1));

    return ans;
}

int main(void)
{
    cout<<missingK({1, 7, 8, 9, 14}, 5, 4);
}