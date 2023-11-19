#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};

Node *getMid(Node *head)
{
    Node *slow=head, *fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *dummy=new Node(-1);
    Node *lastInDummy=dummy;

    if(left==NULL)
        return right;
    
    if(right==NULL)
        return left;

    while(left!=NULL && right!=NULL)
    {
        if((left->data)<(right->data))
        {
            lastInDummy->next=left;
            lastInDummy=left;
            left=left->next;
        }
        else
        {
            lastInDummy->next=right;
            lastInDummy=right;
            right=right->next;
        }
    }

    while(left!=NULL)
    {
        lastInDummy->next=left;
        lastInDummy=left;
        left=left->next; 
    }

    while(right!=NULL)
    {
        lastInDummy->next=right;
        lastInDummy=right;
        right=right->next;
    }

    Node *ans=dummy->next;

    return ans;
}

Node* mergeSort(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *mid=getMid(head);

    Node *left=head;
    Node *right=mid->next;
    mid->next=NULL;
    
    left=mergeSort(left);
    right=mergeSort(right);

    Node *ans=merge(left, right);

    return ans;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(2);
    head->next=new Node(1);

    mergeSort(head);

    return 0;

}