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

// Brute-Force, TC:-O(n), AS:-O(n)

// Optimal, TC:-O(n), AS:-O(1)

Node *reverse(Node *head)
{
    Node *it=head;
    Node *prev=NULL;
    Node *next;

    while(it!=NULL)
    {
        next=it->next;
        it->next=prev;
        prev=it;
        it=next;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    Node *head1=head;
    Node *fast=head;
    Node *slow=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    // Odd length or Even length

    Node *head2;

    if(fast==NULL)
        head2=slow;
    else
        head2=slow->next;

    // Reverse from head2

    head2=reverse(head2);

    bool res=true;

    while(head2!=NULL)
    {
        if((head1->data)!=(head2->data))
        {
            res=false;
            break;
        }

        head1=head1->next;
        head2=head2->next;
    }

    reverse(head2);

    return res;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(1);
    Node *temp1=new Node(2);
    Node *temp2=new Node(13);

    head->next=temp1;
    temp1->next=temp2;

    cout<<isPalindrome(head);

    return 0;

}