#include<bits/stdc++.h>
using namespace std;

// Optimal

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack
{
    //Write your code here

    int size=0;
    Node *it=NULL;

    public:

    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(size==0)
            return 1;

        return 0;
    }

    void push(int data)
    {
        size++;
        Node *newNode=new Node(data);

        if(it==NULL)
        {
            it=newNode;
            return;
        }

        newNode->next=it;
        it=newNode;        
    }

    void pop()
    {
        if(it==NULL)
            return;
        
        size--;
        it=it->next;
    }

    int getTop()
    {
        if(it==NULL)
            return -1;

        return (it->data);
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