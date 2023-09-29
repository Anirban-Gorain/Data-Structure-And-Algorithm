#include<bits/stdc++.h>
using namespace std;

//Brute-force, TC:-O(n) AS:- O(n1+n3)

double median(vector<int> a, vector<int> b)
{
	int n1=a.size();
	int n2=b.size();
	vector<int> merged;
	int totalElem=n1+n2;

	int left=0, right=0;

	while(left<n1 && right<n2)
	{
		if(a[left]<=b[right])
		{
			merged.push_back(a[left]);
			left++;
		}
		else
		{
			merged.push_back(b[right]);
			right++;
		}
	}

	while(left<n1)
	{
		merged.push_back(a[left]);
		left++;
	}

	while(right<n2)
	{
		merged.push_back(b[right]);
		right++;
	}

	int half=totalElem/2;

	return (totalElem%2==0)? ((double)(merged[half-1]+merged[half])/2.0) : ((double)merged[half]);
}

// Better-1, TC:-O((n1+n2)+log(n1)+log(n2)) AS:- O(1)

double median(vector<int> a, vector<int> b)
{
    int n1=a.size();
	int n2=b.size();
	int totalElem=n1+n2;

    int left=n1-1;
    int right=0;

    while(left>=0 && right<n2)
    {
        if(a[left]>b[right])
        {
            swap(a[left], b[right]);
            left--; right++;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int half=totalElem/2;

    if(totalElem%2==0)
    {
        int first=half-1;
        int second=half;

        if(first<n1)
        {
            if(second<n1)
            {
                return (a[first]+a[second])/2;
            }
            else
            {
                return (a[first]+b[second%n1])/2;
            }
        }
        else
        {
            return (b[first%n1]+b[second%n1])/2.0;
        }
    }
    else
    {
        if(half<n1)
            return a[half];
        else
            return b[half%n1];
    }
}

// Better1, TC:-O((n1+n2)) AS:- O(1)

double median(vector<int> a, vector<int> b)
{
    int whichElem=0;
    int n1=a.size();
    int n2=b.size();
    int ind1=(n1+n2)/2;
    int ind2=(n1+n2)/2-1;
    int elem1, elem2;
    int left=0, right=0;

    while(left<n1 && right<n2)
    {
        int hold;

        if(a[left]<=b[right])
        {
            hold=a[left];
            left++;
        }
        else
        {
            hold=b[right];
            right++;
        }

        if(whichElem==ind1)
            elem1=hold;

        if(whichElem==ind2)
            elem2=hold;

        whichElem++;
    }

    while(left<n1)
    {
        int hold=a[left];
        left++;

        if(whichElem==ind1)
            elem1=hold;
        if(whichElem==ind2)
            elem2=hold;

        whichElem++;
    }

    while(right<n2)
    {
        int hold=b[right];
        right++;

        if(whichElem==ind1)
            elem1=hold;
        if(whichElem==ind2)
            elem2=hold;

        whichElem++;
    }

    int totalElements=n1+n2;

    return ((totalElements%2)==0)?((elem1+elem2)/2):elem1;
}

// Optimal, TC:-O(lon(n1, n2)) AS:-O(1)

double findMedianSortedArrays(vector<int> a, vector<int> b)
{
    // if(n1>n2) findMedianSortedArrays(b, a);
    int n1=a.size(), n2=b.size();
    if(n1>n2) return findMedianSortedArrays(b, a);
    int low=0, high=n1, half=(n1+n2+1)/2;

    while(low<=high)
    {
        int mid1=(low+high)/2;
        int mid2=half-mid1;

        // 0 ... (mid-1) | mid ... (n-1)

        int l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;

        if(mid1<n1)
            r1=a[mid1];
        if(mid2<n2)
            r2=b[mid2];
        if(mid1-1>=0)  
            l1=a[mid1-1];
        if(mid2-1>=0)
            l2=b[mid2-1];

        if(l1<=r2 && l2<=r1)
        {
            double median;

            if((n1+n2)%2==0)
                median=(max(l1, l2)+min(r1, r2))/2.0;
            else
                median=max(l1, l2);

            return median;
        }
        else if(l2>r1)
            low=mid1+1;
        else
            high=mid1-1;
        
    }

    return -1;
}

int main(void)
{
    cout << findMedianSortedArrays({2}, {});
}