#include<iostream>
#include<algorithm>
using namespace std;

void selectionSort(int arr[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        int *minElem=min_element(arr+i, arr+len);
        swap(arr[i], *minElem);
    }
}

void bubbleSort(int arr[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-1-i; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]); // For increasing order
        }
    }
}

void insertionSort(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j]<arr[j-1])
                swap(arr[j], arr[j-1]);
        }
    }
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    int arr[]={5, 4, 3, 7, 10, -1, 3};
    selectionSort(arr, sizeof(arr)/sizeof(int));
    for(auto elem : arr)
    {   
        cout << elem << " "; 
    }
    cout << "\n";

    int arr1[]={5, 4, 3, 7, 10, -1, 3};
    bubbleSort(arr1, sizeof(arr1)/sizeof(int));
    for(auto elem : arr1)
    {   
        cout << elem << " "; 
    }
    cout << "\n";

    int arr2[]={5, 4, 3, 7, 10, -1, 3};
    insertionSort(arr2, sizeof(arr2)/sizeof(int));
    for(auto elem : arr2)
    {   
        cout << elem << " "; 
    }
    cout << "\n";
}