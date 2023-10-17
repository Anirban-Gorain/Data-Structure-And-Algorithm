#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data=value;
        prev=NULL;
        next=NULL;
    }
};

Node *insertElement(int data, int position, Node *head)
{
    Node *temp=new Node(data);

    if(position==1)
    {
        head->prev=temp;
        temp->next=head;
        return temp;
    }

    Node *it=head;

    for(int i=1; i<position; i++)
    {
        it=it->next;
    }

    temp->next=it;
    it->prev->next=temp;
    it->prev=temp;

    return temp;
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

    insertElement(9, 7, head);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        cout<<it->data;
    }

    cout << endl;

    

    return 0;

}