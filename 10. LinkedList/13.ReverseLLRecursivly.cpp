#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node *reverse(Node *current, Node *prev)
{
    if(current==NULL)
        return prev;
        
    Node *head=reverse(current->next, current);
    current->next=prev;
    
    return head;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);

    head->next=temp1;
    temp1->next=temp2;
    

    reverse(head, NULL);

    return 0;

}