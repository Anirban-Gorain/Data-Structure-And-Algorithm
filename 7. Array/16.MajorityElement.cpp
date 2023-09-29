#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr)
{
    int count=0;
    int elem;
    int len=arr.size();

    for(int i=0; i<len; i++)
    {
        if(count==0)
        {
            count=1;
            elem=arr[i];
        }
        else if (arr[i]==elem)
            count++;
        else
            count--;
        
    }

    // This following step is not required iff it assured that the array will always contain a Majority element.

    count=0;

    for(int i=0; i<len; i++)
        if(arr[i]==elem)
        {
            count++;
            if(count>len/2) return elem;
        }
            
    return -1;
}