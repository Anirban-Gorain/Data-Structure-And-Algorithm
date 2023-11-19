#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Brute-Force, TC:-O(n), AS:-O(n);
// Better, TC:-O(n*k), AS:-O(1);

Node* rotate(Node* head, int k)
{
    Node *cpyHead=head, *tail;
    
    for(Node *it=head; it!=NULL; it=it->next)
        tail=it;
        
    while(k!=0)
    {
        cpyHead=head;
        head=head->next;
        tail->next=cpyHead;
        cpyHead->next=NULL;
        tail=cpyHead;
        k--;
    }
    
    return head;
}

// Optimal, TC:-O(n), AS:-O(1);

Node *reverse(Node *head, int till)
{
    int cnt=1;
    Node *prev=NULL, *next, *it=head;

    while(cnt<=till && it!=NULL)
    {
        cnt++;

        next=it->next;
        it->next=prev;
        prev=it;
        it=next;
    }

    return prev;
}

Node* rotate(Node* head, int k)
{
    Node *head1=head, *head2=head;
    int size=0;

    for(Node *it=head; it!=NULL; it=it->next)
        size++;
        
    if(size==k)
        return head;

    head1=reverse(head, INT_MAX);

    head2=head1;
    for(int i=1; i<=size-k; i++)
        head2=head2->next;

    head1=reverse(head1, size-k);
    Node *tail1=head1;
    while(tail1->next!=NULL)
        tail1=tail1->next;

    head2=reverse(head2, k);
    tail1->next=head2;

    return head1;
}


int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(2);
    head->next=new Node(4);
    head->next->next=new Node(7);
    head->next->next->next=new Node(8);
    head->next->next->next->next=new Node(9);

    rotate(head, 2);

    return 0;

}