#include<bits/stdc++.h>
using namespace std;

string rotateByOne(string str)
{
    char temp=str[0];
    int len=str.length();

    for(int i=0; i<len-1; i++)
        str[i]=str[i+1];

    str[len-1]=temp;

    return str;
}

// Brute-Force, TC:-O(n*n), AS:-O(1)

bool areRotations(string s1,string s2)
{
    int len1=s1.length();
    int len2=s2.length();

    if((len1!=len2))
        return false;

    if(s1==s2)
        return true;

    string cpyS1=s1;

    for(int i=1; i<=(len1-1); i++)
    {
        cpyS1=rotateByOne(cpyS1);

        if(cpyS1==s2)
            return true;
    }

    return false;
}

// Optimal, TC:-O(n), AS:-O(n)

bool areRotations(string s1,string s2)
{
    int len1=s1.length();
    int len2=s2.length();

    if((len1!=len2))
        return false;

    if(s1==s2)
        return true;

    string temp=s1+s2;

    if(temp.find(s2)!=string::npos)
        return true;


    return false;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    string str="ABCDEF";

    if(str.find("DCB")!=string::npos)
        cout<<"Present";
    else
        cout<<"Not present";

    return 0;

}