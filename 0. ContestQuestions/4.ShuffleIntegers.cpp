#include<bits/stdc++.h>
using namespace std;

// Optimal, TC:-O(n), AS:-O(1)

void shuffleArray(int arr[],int n)
{
    int i=0, j=n/2;
    
    while(j<n)
    {
        arr[j]=(arr[j]<<10)|arr[i];
        j++; i++;
    }
    
    i=0, j=n/2;
    
    while(j<n)
    {
        int a=arr[j]&1023;
        int b=arr[j]>>10;
        
        arr[i]=a;
        arr[i+1]=b;
        
        i+=2; j++;
    }
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}