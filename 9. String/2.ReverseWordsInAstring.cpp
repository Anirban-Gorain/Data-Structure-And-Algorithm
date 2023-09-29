#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(3n), AS:-O(max(wordSize)+NoOfWords)

string reverseWords1(string s)
{
    string temp="";
    vector<string> words;

    for(char letter : s)
    {
        if(temp.size()>0 && letter==' ')
        {
            words.push_back(temp);
            temp.clear();
        }
        else if(letter!=' ')
        {
            temp=temp+letter;
        }
    }

    if(temp.size()>0)
        words.push_back(temp);



    reverse(words.begin(), words.end());
    temp.clear();

    for(string wrd : words)
    {
        temp=temp+" "+wrd;
    }

    temp=temp.erase(0,1);

    return temp;
}

// OPtimal, TC:-O(3n*max(wordSize)), AS:-O(1)

string reverseWords(string s)
{
    int n=s.size();

    // Deleting the unnecessary spaces.

    for(int i=0; i<n-1; i++)
    {
        if(s[i]==' ' && s[i+1]==' ')
        {
            s.erase(i, 1);
            i--;
        }
    }

    if(s[0]==' ')
        s.erase(0, 1);

    n=s.size();

    if(s[n-1]==' ')
        s.erase(n-1, 1);

    // Reversing the entire string

    reverse(s.begin(), s.end());

    // Reversing each word in s.

    int start=0;

    for(int i=0; i<n; i++)
    {
        if(s[i]==' ')
        {
            reverse(s.begin()+start, s.begin()+i);
            start=i+1;
        }
    }

    reverse(s.begin()+start, s.end());

    return s;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout<<reverseWords("     a good        example     ");

    return 0;

}