#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

void recursiveTraversal(Node *it)
{
    if(it==NULL)
        return;

    cout<<it->data<<endl;
    recursiveTraversal(it->next);
}

Node *insertionInSLL(int value, int position, Node *it)
{
    Node *temp=new Node(value);

    if(position==1)
    {
        temp->next=it;

        return temp;
    }

    for(int i=1; i<=position-2; i++)
    {
        it=it->next;
    }

    temp->next=it->next;
    it->next=temp;

    return temp;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }

    cout<<endl;
    head=insertionInSLL(100000, 1, head);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }

    cout<<endl;
    insertionInSLL(200000, 2, head);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }

    cout<<endl;
    insertionInSLL(700000, 7, head);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }

    return 0;

}