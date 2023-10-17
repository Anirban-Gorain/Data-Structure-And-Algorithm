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

int getLength(Node *it)
{
    int len=0;

    while(it!=NULL)
    {
        len++;
        it=it->next;
    }

    return len;
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

    cout<<getLength(head);

    return 0;

}