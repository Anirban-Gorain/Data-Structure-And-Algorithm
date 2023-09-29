#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(int arr[], int start, int end)
{
    int size=end-start;
    if(size == 0)
        return;
    
    // Hypothesis
    bubbleSort(arr, start+1, end);

    // After start+1 to end part is get sorted, placing the arr[start] in its position by compering the adj elements

    for(int j=start; j<=end-1; j++)
        if(arr[j]>arr[j+1])
            swap(arr[j], arr[j+1]);
}

void recursiveInsertionSort(int arr[], int end)
{
    if(end==0)
        return;
    
    // Hypothesis
    recursiveInsertionSort(arr, end-1);

    // Have to insert arr[end] in its correct position
    for(int j=end; j>0; j--)
        if(arr[j]<arr[j-1])
            swap(arr[j], arr[j-1]);
}

// Merge sort

vector<int> merge(int arr[], int start, int mid, int end)
{
    int left=start;
    int right=mid+1;
    
    vector<int> temp;
    
    while(left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left<=mid)
    {
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=end)
    {
        temp.push_back(arr[right]);
            right++;
    }
    
    return temp;
}

void mergeSort(int arr[], int start, int end)
{
    if(start==end)
        return;
        
    int mid=(start+end)/2;
    
    // Hypothesis
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    
    // Have to merge the two sorted halves
    vector<int> temp=merge(arr, start, mid, end);
    
    for(int i=start; i<=end; i++)
        arr[i]=temp[i-start];
}

// Quick sort

int getPivotInd(int arr[], int start, int end)
{
    int i=start;
    int j=end;
    int pivot=arr[start];

    while (i<j)
    {
        while (i<=end && arr[i]<=pivot)
        {
            i++;
        }
        while (j>=0 && arr[j]>pivot)
        {
            j--;
        }

        if(i<j) // There will a end point when i>j at that time we do not need to swap.
            swap(arr[i], arr[j]);
    }

    swap(arr[j], arr[start]);

    return j;
}

void quickSort(int arr[], int start, int end)
{
    // Base
    if(start>end)
        return;

    int partition=getPivotInd(arr, start, end);
    quickSort(arr, start, partition-1);
    quickSort(arr, partition+1, end);
}

// Shell sort

void shellSort(int arr[], int n)
{
    for(int gap=n/2; gap>0; gap=gap/2)
    {
        for(int i=gap; i<n; i++)
        {
            for(int j=i; j>=gap && arr[j-gap]>arr[j]; j=j-gap)
            {
                swap(arr[j-gap], arr[j]);
            }
        }
    }
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    int arr[]={5, 4, 3, 2, 1};
    int len=sizeof(arr)/sizeof(int);
    bubbleSort(arr, 0, len-1);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";

    int arr1[]={5, 4, 3, 2, 1};
    int len1=sizeof(arr1)/sizeof(int);
    recursiveInsertionSort(arr1, len1-1);
    for (int i = 0; i < len; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\n";

    int arr2[]={5, 4, 3, 2, 1};
    int len2=sizeof(arr2)/sizeof(int);
    mergeSort(arr2, 0, len2-1);
    for (int i = 0; i < len; i++)
    {
        cout << arr2[i] << " ";
    }
    
}