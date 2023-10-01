#include<bits/stdc++.h>
using namespace std;

// Optimal, TC:-O(n), AS:-O(1)

int atoi(string str)
{
    long long ans=0;
    int ind=0;
    int n=str.length();

    if(str[ind]=='-')
        ind++;

    while (ind<n)
    {
        if(!(str[ind]>='0' && str[ind]<='9'))
            return -1;

        int charToNum=str[ind]-'0';

        ans=(ans*10)+charToNum;
        
        ind++;
    }
    
    return (str[0]=='-')?(ans*-1):ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}