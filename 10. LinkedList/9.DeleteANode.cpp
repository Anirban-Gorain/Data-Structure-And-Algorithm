#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

Node *deleteNode(int position, Node *it)
{
    for(int i=1; i<position; i++)
    {
        it=it->next;
    }

    Node *temp=it;

    if((it->prev)!=NULL)
        it->prev->next=temp->next;
    if((temp->next)!=NULL)
        temp->next->prev=temp->prev;

    return it->next;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(10);
    Node *temp1=new Node(15);
    Node *temp2=new Node(20);
    Node *temp3=new Node(25);
    Node *temp4=new Node(30);

    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    temp2->next=temp3;
    temp3->prev=temp2;
    temp3->next=temp4;
    temp4->prev=temp3;

    deleteNode(6, head);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<" ";
    }    

    return 0;

}