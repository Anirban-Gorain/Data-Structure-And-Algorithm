#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
 };
 
struct Queue
{
    Node* front;
    Node* rear;
    void push(int);
    int pop();
   
    Queue()
    {
        front = rear = NULL;
    }
};

void Queue::push(int x)
{
    Node *newNode=new Node(x);

    if(rear==NULL)
    {
        front=rear=newNode;
        return;
    }

    rear->next=newNode;
    rear=newNode;
}

int Queue::pop()
{
    if(front==NULL)
        return -1;

    int frontElem=front->data;
    front=front->next;

    if(front==NULL)
        rear=NULL;

    return frontElem;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}