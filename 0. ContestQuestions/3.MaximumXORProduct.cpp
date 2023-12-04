#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    int maximumXorProduct(long long a, long long b, int n)
    {
        for(int i=n-1; i>=0; i--)
        {
            long long mask=1ll<<i;
            
            bool aSet=((a&mask)!=0)?true:false;
            bool bSet=((b&mask)!=0)?true:false;

            if(aSet==true && bSet==true)
                continue;
            else if(aSet==false && bSet==false)
            {
                a=a^mask;
                b=b^mask;
            }
            else
            {
                if(a>b && aSet==true)
                {
                    a=a^mask;
                    b=b^mask;
                }
                else if(b>a && bSet==true)
                {
                    a=a^mask;
                    b=b^mask;
                }
            }



        }

        int mod=1e9+7;
        int ans=((a%mod)*(b%mod))%mod;

        return ans;
    }
};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}