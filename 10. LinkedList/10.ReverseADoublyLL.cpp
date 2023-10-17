#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

// Optimal, TC:-O(n), AS:-O(1)

Node* reverseDLL(Node *head)
{
    // Reaching the last node;

    Node *it=head;

    while (it->next!=NULL)
        it=it->next;
    
    head=it;

    while(it!=NULL)
    {
        swap(it->next, it->prev);
        it=it->next;
    }

    return head;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(1);
    Node *temp1=new Node(2);
    Node *temp2=new Node(3);
    Node *temp3=new Node(4);
    Node *temp4=new Node(5);
    
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    temp2->next=temp3;
    temp3->prev=temp2;
    temp3->next=temp4;
    temp4->prev=temp3;

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<" ";
    }

    head=reverseDLL(head);
    cout<<endl;

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<" ";
    }

    return 0;

}