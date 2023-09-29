#include<bits/stdc++.h>
using namespace std;

void rev(int arr[], int start, int end)
{
    int till=(end-start+1)/2;

    for(int steps=1; steps<=till; steps++)
    {
        swap(arr[start+(steps-1)], arr[end-(steps-1)]);
    }
}

void leftRotate(int arr[], int n, int d)
{
    rev(arr, 0, d-1);
    rev(arr, d, n-1);
    rev(arr, 0, n-1);
}