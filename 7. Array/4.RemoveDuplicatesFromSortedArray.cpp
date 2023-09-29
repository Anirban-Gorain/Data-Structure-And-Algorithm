#include<iostream>
#include<set>
using namespace std;

// Brute1
// Better, TC:(nlogn)

int remove_duplicate(int a[],int n)
{
    set<int> st;

    for(int i=0; i<n; i++)
        st.insert(a[i]); // logn time

    int i=0;
    for(auto elem : st)
    {
        a[i]=elem;
        i++;
    }

    return st.size();
}

// Optimized

int remove_duplicate(int a[],int n)
{
    if(n==1)
        return 1;

    int i=0, j=1;

    while(j<n)
    {
        if(a[i]==a[j])
            j++;
        else
        {
            i++;
            a[i]=a[j];
            j++;
        }
    }
    
    n=(i+1);

    return n;
}

int main(void)
{
    
    return 0;
}