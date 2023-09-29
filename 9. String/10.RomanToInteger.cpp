#include<bits/stdc++.h>
using namespace std;

// Optimal, TC:-O(n), AS:-O(1)

int letterToNum(char letter)
{
    if(letter=='I')
        return 1;
    else if(letter=='V')
        return 5;
    else if(letter=='X')
        return 10;
    else if(letter=='L')
        return 50;
    else if(letter=='C')
        return 100;
    else if(letter=='D')
        return 500;


    return 1000;
}

int romanToDecimal(string str)
{
    int len=str.length();
    int num=letterToNum(str[len-1]);

    for(int i=len-2; i>=0; i--)
    {
        int current=letterToNum(str[i]);
        int after=letterToNum(str[i+1]);

        if(current>=after)
        {
            num+=current;
        }
        else
        {
            num-=current;
        }
    }

    return num;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}