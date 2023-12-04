#include<bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
    
    return {a, b};
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}