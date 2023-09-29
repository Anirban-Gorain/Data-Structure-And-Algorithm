#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(2*(m+n)) AS:-O(m+n)

// Optimal-1 TC:-O(m+n+m*log(m)+n*log(n)) AS:-O(1)

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
	int m=a.size();
	int n=b.size();

    int pointerA=m-1;
    int pointerB=0;

    while(a[pointerA]>b[pointerB])
    {
        swap(a[pointerA], b[pointerB]);
        pointerA--; pointerB++;
    }

    sort(a.begin(), a.end());
}

// Optimal-2 TC:-O() AS:-O()