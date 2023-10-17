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

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);

    // Way 1

    (*head).next=temp1;
    (*(*head).next).next=temp2;

    // Way 2
    
    head->next=temp1;
    head->next->next=temp2;

    return 0;
}