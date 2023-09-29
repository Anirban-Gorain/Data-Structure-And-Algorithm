#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int maxProfit=0;
    int minCP=prices[0];
    int len=prices.size();

    for(int i=1;i<len;i++)
    {
        int profit=prices[i]-minCP;
        maxProfit=max(maxProfit, profit);

        minCP=min(minCP, prices[i]);
    }

    return maxProfit;
}