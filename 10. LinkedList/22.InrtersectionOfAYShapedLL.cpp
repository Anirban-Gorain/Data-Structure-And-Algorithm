#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(Node* head1, Node* head2)
{
    int n=0, m=0;
    
    for(Node *it=head1; it!=NULL; it=it->next)
    {
        n++;
    }
        
    for(Node *it=head2; it!=NULL; it=it->next)
    {
        m++;
    }
    
    Node *it=(n>m)?head1:head2;
    
    while(it->next!=NULL)
        it=it->next;
        
    it->next=(n>m)?head2:head1;


    
    Node *fast=(n>m)?head1:head2, *slow=(n>m)?head1:head2, *temp=(n>m)?head1:head2;
    
    do
    {
        fast=fast->next->next;
        slow=slow->next;
        
    }while(fast!=slow && fast!=NULL && fast->next!=NULL);

    if(fast==NULL || fast->next==NULL)
        return -1;
    
    while(slow!=temp)
    {
        slow=slow->next;
        temp=temp->next;
    }
    
    return temp->data;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head1=new Node(3);
    head1->next=new Node(6);
    head1->next->next=new Node(9);
    head1->next->next->next=new Node(15);
    head1->next->next->next->next=new Node(30);
    Node *head2=new Node(10);
    head2->next=head1->next->next->next;

    cout<<intersectPoint(head1, head2);

    return 0;

}