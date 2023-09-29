#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:- O(n*log(n) + 2n) AS:- O(1) Ans array is not used to solve the problem, rather is used to return the ans.

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end()); // No need to write Comp

	int len=arr.size();
    vector<vector<int>> ans;

    for(int i=0; i<len; i++)
    {
        vector<int> temp=arr[i];

        int j=i+1;
        for(; j<len; j++)
        {
            int x1, y1, x2, y2;

            x1=temp[0];
            y1=temp[1];
            x2=arr[j][0];
            y2=arr[j][1];

            if(x2<=y1)
            {
                int mergedX=x1;
                int mergedY=max(y1, y2);
                temp.clear();
                temp={mergedX, mergedY};
            }
            else
            {
                break;
            }

        }
        ans.push_back(temp);
        i=j;
        i--;
    }
    return ans;
}

// Optimal, TC:- O(n*log(n) + n) AS:- O(1)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end()); // No need to write Comp

	int len=arr.size();
    vector<vector<int>> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<len; i++)
    {
        vector<int> temp=arr[i];

        if(ans.back()[1]>=arr[i][0])
        {
            ans.back()[1]=max(arr[i][1], ans.back()[1]);
        }
        else
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}



