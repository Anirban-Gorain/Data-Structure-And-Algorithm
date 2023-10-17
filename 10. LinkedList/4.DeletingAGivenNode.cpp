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

Node *deleteNode(int position, Node *it)
{
    if(position==1)
    {
        Node *temp=it->next;
        delete it;

        return temp;
    }

    for(int i=1; i<=position-2; i++)
    {
        it=it->next;
    }

    Node *hold=it->next;
    it->next=hold->next;
    delete hold;

    return it;
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
    head->next->next->next->next->next=new Node(5);
    head->next->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next->next->next->next=new Node(9);
    head->next->next->next->next->next->next->next->next->next->next=new Node(10);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }

    deleteNode(2, head);
    cout << endl;

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }

    head=deleteNode(1, head);
    cout << endl;

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data<<endl;
    }
    

    return 0;

}