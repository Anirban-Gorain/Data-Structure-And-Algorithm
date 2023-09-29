#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:- O(n*k) AS:-O(k)

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n=arr.size();
    vector<int> howMany(n-1, 0);


    for(int i=1; i<=k; i++)
    {
        long double maxDist=-1; int maxDistInd=-1;
        
        for(int j=0; j<n-1; j++)
        {
            // Before placing the current station what is the gap?

            long double dist=(long double) (arr[j+1]-arr[j])/(long double) (howMany[i]+1);

            if(dist>maxDist)
            {
                maxDist=dist;
                maxDistInd=j;
            }
        }
        howMany[maxDistInd]++;
    }

    long double maxGap=-1;

    for(int i=0; i<n-1; i++)
    {
        long double gap=(long double) (arr[i+1]-arr[i])/ (long double) howMany[i]+1;

        maxGap=max(maxGap, gap);
    }

    return maxGap;
}

// Better, TC:- O(k*log(n)) AS:-O(k)

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n=arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    // Inserting every gap

    for(int i=0; i<n-1; i++)
    {
        long double gap=arr[i+1] - arr[i];
        pq.push({gap, i});
    }

    for(int i=1; i<=k; i++)
    {
        auto tp=pq.top();
        pq.pop();
        int gapAt=tp.second;
        long double gap=arr[gapAt+1]-arr[gap];

        howMany[gapAt]++;

        long double newGap=gap/ (long double) (howMany[gapAt]+1);

        pq.push({newGap, gapAt});
    }

    return pq.top().first;
}

// Optimal

int countGasStations(vector<int> &arr, int n, long double dist)
{
    int countStations=0;

    for(int i=0; i<n-1; i++)
    {
        int cal=((arr[i+1]-arr[i])/dist); // No of stations b/w arr[i] and arr[i+1] when the distance dist(at max);

        if((arr[i+1]-arr[i])==(cal*dist))
        {
            cal--;
        }

        countStations+=cal;
    }

    return countStations;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    long double low=0, high=0, ans;
    int n=arr.size();

    for(int i=0; i<n-1; i++)
    {
        high=max(high, (long double) (arr[i+1]-arr[i]));
    }

    long double diff=10e-6;

    while(high-low>diff)
    {
        long double mid=(low+high)/(2.0);

        int noOfGasStations=countGasStations(arr, n, mid);

        if(noOfGasStations>k)
        {
            low=mid;
        }
        else
        {
            high=mid;
            // ans=mid;
        }
    }

    return high;
}