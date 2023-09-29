#include<bits/stdc++.h>
using namespace std;

// Efficient way to calculate nCr, TC:- O(r)

int nCr(int n, int r)
{
    int ans=1;
    for(int i=0; i<r; i++)
    {
        ans=ans*(n-i);
        ans=ans/(i+1);
    }

    return ans;
}

// Type-1, Row and Col will be given we have to tell the element.

int element(int row, int col)
{
    return nCr(row-1, col-1);
}

// Type-2, Row no will be given, we have to print the entire row.

vector<int> printNthPascalRow(int n)
{
    vector<int> sendAns(1, 1);
    int ans=1;
    for(int i=1; i<n; i++)
    {
        ans=ans*(n-i);
        ans=ans/i;
        sendAns.push_back(ans);
    }

    return sendAns;
}

// Type-3, n will be given, print pascal triangle upto nth row.

vector<vector<int>> pascalTriangle(int N)
{
    vector<vector<int>> ans;
    for(int row=1; row<=N; row++)
    {
        vector<int> holdRow=printNthPascalRow(row);
        ans.push_back(holdRow);
    }

    return ans;
}

int main(void)
{
    cout << element(5, 3) << "\n";
    printNthPascalRow(5);
    return 0;
}