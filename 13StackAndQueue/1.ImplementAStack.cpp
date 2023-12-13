#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int topInd=-1;

    public:
    
    Stack(int capacity)
    {
        arr=new int[capacity];
        size=capacity;
    }

    void push(int num)
    {
        if((topInd+1)==size)
            return;
        
        arr[++topInd]=num;
    }

    int pop()
    {
        if(topInd==-1)
            return -1;


        return arr[topInd--];
    }
    
    int top()
    {
        if(topInd==-1)
            return -1;

        return arr[topInd];
    }
    
    int isEmpty()
    {
        if(topInd==-1)
            return 1;
        
        return 0;
    }
    
    int isFull()
    {
        if((topInd+1)==size)
            return 1;
        
        return 0;
    }
    
};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}