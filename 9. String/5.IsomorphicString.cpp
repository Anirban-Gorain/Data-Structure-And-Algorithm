#include<bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();

    if(len1!=len2)
        return false;

    unordered_map<char, char> map;

    for(int i=0; i<len1; i++)
    {
        if(map.find(str1[i])!=map.end())
        {
            char mappedTo=map.find(str1[i])->second;

            if(mappedTo!=str2[i])
                return false;
        }
        else
            map[str1[i]]=str2[i];
    }

    map.clear();

    for(int i=0; i<len1; i++)
    {
        if(map.find(str2[i])!=map.end())
        {
            char mappedTo=map.find(str2[i])->second;

            if(mappedTo!=str1[i])
                return false;
        }
        else
            map[str2[i]]=str1[i];
    }

    return true;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}