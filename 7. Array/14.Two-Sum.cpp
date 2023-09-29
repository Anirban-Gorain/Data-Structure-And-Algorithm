#include<bits/stdc++.h>
using namespace std;

// Brute Force variation 1

bool solve(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j && arr[i]+arr[j]==target)
            {
                return true;
            }
        }
    }

    return false;
}

// Brute Force variation 2

vector<int> solve1(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j && arr[i]+arr[j]==target)
            {   
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// Better

vector<int> solve2(int arr[], int n, int target)
{
    unordered_map<int, int> store;
    vector<int> result={-1, -1};

    for(int i=0; i<n; i++)
    {
        int more=target-arr[i];

        if(store.find(more)!=store.end())
        {
            return {store[more], i};
        }

        store[arr[i]]=i;
    }

    return {-1, -1};
}

// Optimal but this approach is optimal for only the first variation

bool solve3(int arr[], int n, int target)
{
    sort(arr, arr+n);

    int i=0, j=n-1;

    while(i<j)
    {
        int sum=arr[i]+arr[j];

        if(sum==target)
            return true;
        else if(sum>target)
            j--;
        else
            i++;
    }

    return false;
}

int main(void)
{

    return 0;
}