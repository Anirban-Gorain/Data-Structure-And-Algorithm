#include<bits/stdc++.h>
using namespace std;

// BruteForce, TC:-O(n^2), AS:-O(1)

// Better, TC:-O(n), AS:-O(n)

// Optimal, TC:-O(n), AS:-O(1)

vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    long long XORAll=0;
    
    for(int i=0; i<N; i++)
    {
        XORAll=XORAll^Arr[i];
    }
    
    // Finding the set bit position of XORAll
    
    int pos=0;
    
    while((XORAll&(1<<pos))==0)
        pos++;
        
    int num1=0, num2=0;
    
    for(int i=0; i<N; i++)
    {
        if((Arr[i]&(1<<pos))==0)
            num1=num1^Arr[i];
    }
    
    for(int i=0; i<N; i++)
    {
        if((Arr[i]&(1<<pos))!=0)
            num2=num2^Arr[i];
    }
    
    vector<long long> ans={num1, num2};
    
    sort(ans.rbegin(), ans.rend());
    
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