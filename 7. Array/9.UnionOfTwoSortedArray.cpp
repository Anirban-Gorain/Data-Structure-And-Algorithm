#include<bits/stdc++.h>
using namespace std;

// Brute

int unionArrays(int arr1[], int n1, int arr2[], int n2)
{
    set<int> st;
    for(int i=0; i<n1; i++)
        st.insert(arr1[i]);
    for(int i=0; i<n2; i++)
        st.insert(arr2[i]);

    int sizeOfUnionArray=st.size();
    return sizeOfUnionArray;
}

// Better

#include<bits/stdc++.h>
using namespace std;

int doUnion(int arr1[], int n1, int arr2[], int n2)
{
    int i, j;
    i=j=0;
    vector<int> unionArray;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            if(unionArray.size()==0 || unionArray.back()!=arr1[i])
                unionArray.push_back(arr1[i]);
            i++;
        }
        else
        {
            if(unionArray.size()==0 || unionArray.back()!=arr2[j])
                unionArray.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n1)
    {
        if(unionArray.size()==0 || unionArray.back()!=arr1[i])
                unionArray.push_back(arr1[i]);
        i++;
    }
    while(j<n2)
    {
        if(unionArray.size()==0 || unionArray.back()!=arr2[j])
                unionArray.push_back(arr2[j]);
        j++;
    }
    return unionArray.size();
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    int arr1[]={1, 2, 3, 4, 5};
    int arr2[]={1, 2, 3};
    cout << doUnion(arr1, 5, arr2, 3);
}