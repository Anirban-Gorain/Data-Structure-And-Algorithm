#include<bits/stdc++.h>
using namespace std;

// Brute force, TC:-O(n^4) AS:-(Unique Ans)

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n=nums.size();
    set<vector<int>> uniqueAns;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int l=k+1; l<n; l++)
                {
                    int sum=nums[i]+nums[j]+nums[k]+nums[l];

                    if(sum==target)
                    {
                        vector<int> tempAns={nums[i], nums[j], nums[k], nums[l]};
                        sort(tempAns.begin(), tempAns.end());
                        uniqueAns.insert(tempAns);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(uniqueAns.begin(), uniqueAns.end());

    return ans;
}

// Better, TC:-O(n^3*log(n)) AS:-(2n)

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n=nums.size();

    unordered_map<int, int> element; // Element, Index
    set<vector<int>> uniqueAns;
    for(int i=0; i<n; i++)
    {
        element[nums[i]]=i;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int sum=nums[i]+nums[j]+nums[k];
                int less=target-sum;
                // int index=element.find(less)->second;

                if(element.find(less)!=element.end() && element[less]!=i && element[less]!=j && element[less]!=k)
                {
                    vector<int> tempAns={nums[i], nums[j], nums[k], less};
                    sort(tempAns.begin(), tempAns.end());
                    uniqueAns.insert(tempAns);
                }
            }
        }
    }

    vector<vector<int>> ans(uniqueAns.begin(), uniqueAns.end());

    return ans;
}

// Optimal, TC:-O(n^3) AS:-(1)

vector<vector<int>> fourSum(vector<int> nums, int target)
{
    int n=nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++)
    {
        if(i>0 && nums[i-1]==nums[i])
            continue;

        for(int j=i+1; j<n; j++)
        {
            if(j!=i+1 && nums[j]==nums[j-1])
                continue;

            int k=j+1;
            int l=n-1;

            while(k<l)
            {
                int sum=nums[i]+nums[j]+nums[k]+nums[l];

                if(sum<target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                else
                {
                    // sum==target

                    vector<int> tempAns={nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(tempAns);

                    k++;
                    l--;

                    while((k<l) && (nums[k-1]==nums[k])) k++;
                    while(k<l && nums[l+1]==nums[l]) l--;
                }

            }
        }
    }

    return ans;
}