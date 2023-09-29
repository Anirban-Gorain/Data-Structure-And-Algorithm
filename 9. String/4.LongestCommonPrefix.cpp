#include<bits/stdc++.h>
using namespace std;

// , TC:-O(n*MaxWordSize), AS:-O(LenOfThePrefix)

string longestCommonPrefix (string arr[], int N)
{
    if(N==0)
        return "-1";

    string ans=arr[0];

    for(int i=1; i<N; i++)
    {
        string str1=ans;
        string str2=arr[i];
        int len1=str1.length(), len2=str2.length();
        ans="";

        for(int j=0; j<min(len1, len2); j++)
        {
            if(str1[j]==str2[j])
                ans=ans+str1[j];
            else
            {
                if(ans.size()==0)
                    return "-1";

                break;
            }

        }
    }

    return ans;
}

// , TC:-O(n*MaxWordSize), AS:-O(LenOfThePrefix)

string longestCommonPrefix (string arr[], int N)
{
    int minLen=INT_MAX;

    for(int i=0; i<N; i++)
    {
        int tempLen=arr[i].length();
        minLen=min(minLen, tempLen);
    }

    string ans;

    for(int i=0; i<minLen; i++)
    {
        char temp=arr[0][i];
        bool canBeAdded=true;

        for(int j=1; j<N; j++)
        {
            if(temp!=arr[j][i])
            {
                canBeAdded=false;
                break;
            }
        }

        if(canBeAdded==true)
        {
            ans=ans+temp;
        }
        else    
        {
            return (ans.length()==0)?"-1":ans;
        }
    }

    return ans;
}

// , TC:-O(n*MaxWordSize), AS:-O(log(n)*MaxWordSize)

string getPrefix(string arr[], int start, int end)
{
    if(start==end)
        return arr[start];

    int mid=(start+end)/2;

    string pre1=getPrefix(arr, start, mid);
    string pre2=getPrefix(arr, mid+1, end);

    string result = "";
    int len = min(pre1.length(), pre2.length());
 
    for(int i=0; i<len; i++)
    {
        if(pre1[i]!=pre2[i])
            break;

        result += pre1[i];
    }
 
    return (result);
}

string longestCommonPrefix (string arr[], int N)
{
    string ans=getPrefix(arr, 0, N-1);
    return (ans.length()==0)?"-1":ans;
}

// , TC:-O(n+log(CommonPrefix)*n), AS:-O(CommonPrefix)

string longestCommonPrefix (string arr[], int N)
{
    // Getting the min length and min length string.

    string searchSpace;
    int SPlen=INT_MAX;

    for(int i=0; i<N; i++)
    {
        if(SPlen>arr[i].length())
        {
            searchSpace=arr[i];
            SPlen=arr[i].length();
        }
    }

    // Applying BS on min len string

    int low=0, high=SPlen;
    string ans;

    while(low<=high)
    {
        int mid=low-(low-high)/2;

        string subPart=searchSpace.substr(low, mid-low+1);
        bool canBeAdded=true;
        for(int i=0; i<N; i++)
        {
            if(arr[i].substr(low, mid-low+1)!=subPart)
            {
                canBeAdded=false;
                break;
            }
        }

        if(canBeAdded==true)
        {
            ans=ans+subPart;
            low=mid+1;
        }
        else
            high=mid-1;
    }

    return (ans.length()==0)?"-1":ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    string arr[]={"geeksforgeeks", "geeks", "geek", "geezer"};
    cout<<longestCommonPrefix(arr, 4);

    return 0;

}