#include<iostream>
using namespace std;

// Optimal
void leftRotationByOne(int arr[], int n)
{
    int temp=arr[0];
    for(int i=1; i<n; i++)
        arr[i-1]=arr[i];
    arr[n-1]=temp;
}

int main(void)
{
    return 0;
}