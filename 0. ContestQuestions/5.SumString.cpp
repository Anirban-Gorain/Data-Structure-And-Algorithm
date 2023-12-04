#include<bits/stdc++.h>
using namespace std;


string getSum(string a, string b)
{
    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int carry = 0;
    int index = 0;
    
    while(index < a.size() and index < b.size()){
        int sum = (a[index] - '0') + (b[index] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        ans += to_string(sum);
        ++index;
    }
    
    while(index < a.size()){
        int sum = (a[index] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        ans += to_string(sum);
        ++index;
    }
    
    while(index < b.size()){
        int sum = (b[index] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        ans += to_string(sum);
        ++index;
    }
    
    if(carry){
        ans += to_string(carry);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
};

int help(string s, int start, string strNum1, string strNum2, int end)
{
    int len=s.length();
    
    if(end==len-1)
        return true;
    
    string sum=getSum(strNum1, strNum2);
    
    for(int i=start; i<len; i++)
    {
        string res=s.substr(start, i-start+1);
        
        if(res.length()>sum.length())
            return false;
        else if(res==sum)
        {
            help(s, i+1, strNum2, res, i);
        }
    }
    
    return false;
}

int isSumString(string s)
{
    int len=s.length();
    
    if(len==1 || len==2)
        return false;
    
    for(int i=1; i<len; i++)
    {
        for(int j=0; j<i; j++)
        {
            string strNum1=s.substr(0, j-0+1);
            string strNum2=s.substr(j+1, (i)-(j+1)+1);
            
            if(help(s, i+1, strNum1, strNum2, -1))
            {
                return true;
            }
        }
    }
    
    return false;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<isSumString("112");

    return 0;

}