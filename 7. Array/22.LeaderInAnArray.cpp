#include<bits/stdc++.h>
using namespace std;

// Brute-force sol, O(n^2)

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int len=a.size();

    for(int i=0; i<len; i++)
    {
        int flag=0;
        for(int j=i+1; j<len; j++)
        {
            if(a[i]<=a[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
            ans.push_back(a[i]);

        flag=0;
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// Optimal

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int len=a.size();
    int maxOnRight=INT_MIN;

    for(int i=len-1; len>=0; i--)
    {
        if(a[i]>maxOnRight)
        {
            ans.push_back(a[i]);
        }

        maxOnRight=max(maxOnRight, a[i]);
    }

    // Bottle neck

    sort(ans.begin(), ans.end());
}