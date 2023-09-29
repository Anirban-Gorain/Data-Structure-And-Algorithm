#include<bits/stdc++.h>
using namespace std;

// Brute-force, Double pass solution

vector<int> alternateNumbers(vector<int>&a)
{
    int len=a.size();
    vector<int> ans(len);

    // Assigning + numbers

    for(int i=0, j=0; i<len; i++)
    {
        if(a[i]>0)
        {
            ans[j]=a[i];
            j+=2;
        }
    }

    // Assigning - numbers

    for(int i=0, j=1; i<len; i++)
    {
        if(a[i]<0)
        {
            ans[j]=a[i];
            j+=2;
        }
    }

    return ans;
}

// Optimal, Single pass solution

vector<int> alternateNumbers(vector<int>&a)
{
    int len=a.size();
    int pos=0, neg=1, noOfNeg=0, noOfPos=0;
    vector<int> ans(len);

    for(int i=0; i<len; i++)
    {
        if(a[i]>0)
            noOfPos++;
        else
            noOfNeg++;
    }

    int criticalPoint=min(noOfPos, noOfNeg)*2-1;

    for(int i=0; i<len; i++)
    {
        if(a[i]<0) 
        {
            ans[neg]=a[i];

            if(neg<criticalPoint)
                neg+=2;
            else
                neg++;
        }
        else
        {
            ans[pos]=a[i];
            
            if(pos<criticalPoint)
                pos+=2;
            else
                pos++;
        }
    }

    return ans;
}