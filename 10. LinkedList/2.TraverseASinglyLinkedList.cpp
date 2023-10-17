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

    // Node *it=head;

    // do
    // {
    //     cout << it->data << endl;
    //     it=it->next;
        
    // } while (it!=NULL);

    // for(Node *it=head; it!=NULL; it=it->next)
    // {
    //     cout<<it->data<<endl;
    // }

    // Node *it=head;

    // while(it!=NULL)
    // {
    //     cout<<it->data<<"\n";

    //     it=it->next;
    // }

    recursiveTraversal(head);

    return 0;

}