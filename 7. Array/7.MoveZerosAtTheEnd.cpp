#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd(int arr[], int n)
{
	int i=0, j=0;

    if(arr[j]!=0)
    {
        swap(arr[i], arr[j]);
        i++;
        j++;
    }
    else
    {
        j++;
    }
}