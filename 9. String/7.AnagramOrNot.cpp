#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^2), AS:-O(1)

// Better, TC:-O(n*log(n)), AS:-O(1)

// Better, TC:-O(2n), AS:-O(2n)

bool isAnagram(string a, string b)
{
    int len1=a.length();
    int len2=b.length();
    
    if(len1!=len2)
        return false;
    
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    
    for(int i=0; i<len1; i++)
    {
        freq1[a[i]]++;
        freq2[b[i]]++;
    }
    
    for(auto it : freq1)
    {
        char elem1=it.first;
        int count1=it.second;
        
        if(freq2.find(elem1)!=freq2.end())
        {
            int count2=freq2.find(elem1)->second;
            
            if(count1!=count2)
                return false;
        }
        else
            return false;
    }
    
    return true;
}

// Optimal, TC:-O(2n), AS:-O(n)

bool isAnagram(string a, string b)
{
    int len1=a.length();
    int len2=b.length();
    
    if(len1!=len2)
        return false;
    
    unordered_map<char, int> freq;
    
    for(int i=0; i<len1; i++)
    {
        freq[a[i]]++;
        freq[b[i]]--;
    }
    
    for(auto it : freq)
    {
        if((it.second)!=0)
            return false;
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