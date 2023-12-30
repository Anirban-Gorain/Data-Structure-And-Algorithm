#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^2), AS:-O(1)

// Better, TC:-O(n), AS:-O(n)

long long trappingWater(int arr[], int n)
{
    stack<pair<int, int>> maxRight;
    int maxi=INT_MIN;
    
    for(int i=n-1; i>=2; i--)
    {
        maxi=max(arr[i], maxi);
        
        maxRight.push({arr[i], maxi});
    }
    
    long long collectedWater=0;
    maxi=arr[0];
    
    for(int i=1; i<n-1; i++)
    {
        int minPillar=min(maxi, maxRight.top().second);
        
        int water=minPillar-arr[i];
        collectedWater+=(water>0)?water:0;
        
        maxi=max(maxi, arr[i]);
        maxRight.pop();
    }
    
    return collectedWater;
}

// Optimal, TC:-O(n), AS:-O(1)

long long trappingWater(int arr[], int n)
{
    int leftMax=arr[0], rightMax=arr[n-1];
    int left=1, right=n-2;
    long long ans=0;
    
    while(left<=right)
    {
        if(leftMax<rightMax)
        {
            ans+=((leftMax-arr[left])>0?(leftMax-arr[left]):0);
            leftMax=max(leftMax, arr[left]);
            left++;
        }
        else
        {
            ans+=((rightMax-arr[right])>0?(rightMax-arr[right]):0);
            rightMax=max(rightMax, arr[right]);
            right--;
        }
        
    }
    
    return ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}