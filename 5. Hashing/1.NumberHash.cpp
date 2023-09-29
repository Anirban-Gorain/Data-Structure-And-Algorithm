#include<iostream>
using namespace std;

// At max we will have 0 to 13 write a code for answering multiple frequency queries.

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        int t;
        cin >> t;
        arr[i]=t;
    }

    // Pre-computation

    int hash[13+1]={0};
    for(int i=0; i<5; i++)
    {
        hash[arr[i]]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;

        // Fetching

        cout << hash[t] << " ";
    }
    

    return 0;
}