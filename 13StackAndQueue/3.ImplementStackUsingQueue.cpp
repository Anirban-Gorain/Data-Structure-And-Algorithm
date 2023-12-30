#include<bits/stdc++.h>
using namespace std;

// Using two queues.

// Optimal

class MyStack
{
    queue<int> container;
    queue<int> holder;

    public:

    MyStack()
    {
        
    }
    
    void push(int x)
    {
        container.push(x);
    }
    
    int pop()
    {
        int n=container.size();
        int elem;

        // Shifting from container to holder

        for(int i=1; i<=n-1; i++)
        {
            int temp=container.front();
            container.pop();
            holder.push(temp);
        }

        // The top element

        elem=container.front();
        container.pop();

        // Shifting from holder to container

        n=holder.size();

        
        for(int i=1; i<=n; i++)
        {
            int temp=holder.front();
            holder.pop();
            container.push(temp);
        }

        return elem;
    }
    
    int top()
    {
        int n=container.size();
        int elem;

        // Shifting from container to holder

        for(int i=1; i<=n; i++)
        {
            elem=container.front();
            container.pop();
            holder.push(elem);
        }

        // Shifting from holder to container

        n=holder.size();
        
        for(int i=1; i<=n; i++)
        {
            int temp=holder.front();
            holder.pop();
            container.push(temp);
        }

        return elem;
    }
    
    bool empty()
    {
        return container.empty();
    }
};

// Using only one queue.

// Bruteforce

class MyStack
{
    queue<int> container;

    public:

    MyStack()
    {
    }
    
    void push(int x)
    {
        container.push(x);
    }
    
    int pop()
    {
        int n=container.size();

        for(int i=1; i<=n-1; i++)
        {
            int temp=container.front();
            container.pop();
            container.push(temp);
        }

        int topElem=container.front();
        container.pop();

        return topElem;
    }
    
    int top()
    {
        int n=container.size();
        int topElem;

        for(int i=1; i<=n; i++)
        {
            topElem=container.front();
            container.pop();
            container.push(topElem);
        }

        return topElem;
    }
    
    bool empty()
    {
        return container.empty();
    }
};

// Optimal

class MyStack
{
    queue<int> container;

    public:

    MyStack()
    {
    }
    
    void push(int x)
    {
        int n=container.size();
        container.push(x);

        for(int i=1; i<=n; i++)
        {
            int topElem=container.front();
            container.pop();
            container.push(topElem);
        }
    }
    
    int pop()
    {
        int topElem=container.front();
        container.pop();

        return topElem;
    }
    
    int top()
    {
        return container.front();
    }
    
    bool empty()
    {
        return container.empty();
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