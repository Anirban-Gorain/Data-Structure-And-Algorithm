#include<bits/stdc++.h>
using namespace std;

// Bruteforce, push-> O(1), pop-> O(n), peek, O(n)

// Better, push-> O(n), pop-> O(1), peek, O(1)

class Queue
{
    // Define the data members(if any) here.

    stack<int> cn;
    stack<int> hld;

    
    public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        int n=cn.size();

        for(int i=1; i<=n; i++)
        {
            int tpElem=cn.top();
            hld.push(tpElem);
            cn.pop();
        }

        cn.push(val);

        for(int i=1; i<=n; i++)
        {
            int tpElem=hld.top();
            cn.push(tpElem);
            hld.pop();
        }
    }

    int deQueue()
    {
        if(cn.size()==0)
            return -1;

        int front=cn.top();
        cn.pop();

        return front;
    }

    int peek()
    {
        if(cn.size()==0)
            return -1;

        int front=cn.top();

        return front;
    }

    bool isEmpty()
    {
        return cn.empty();
    }
};

// Optimal, push-> O(1), pop-> Amotrized O(1), peek, Amotrized O(1)

class MyQueue
{
    stack<int> in, op;

    public:

    MyQueue()
    {
        
    }

    void shift()
    {
        int n=in.size();

        for(int i=1; i<=n; i++)
        {
            int topElem=in.top();
            op.push(topElem);
            in.pop();
        }
    }
    
    void push(int x)
    {
        in.push(x);
    }
    
    int pop()
    {
        if(op.size()==0)
        {
            shift();
        }

        int tpElem=op.top();
        op.pop();

        return tpElem;
    }
    
    int peek()
    {
        if(op.size()==0)
        {
            shift();
        }

        int tpElem=op.top();

        return tpElem;
    }
    
    bool empty()
    {
        if(op.size()==0)
        {
            shift();
        }

        return  op.empty();
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