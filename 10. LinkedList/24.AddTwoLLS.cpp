#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* reverseList(struct Node *head)
{
    Node *current=head;
    Node *prev=NULL;
    
    while(current!=NULL)
    {
        Node *next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    int n=0, m=0;
    Node *it1=first, *it2=second;

    while(it1!=NULL)
    {
        it1=it1->next;
        n++;
    }

    while(it2!=NULL)
    {
        it2=it2->next;
        m++;
    }

    first=reverseList(first);
    second=reverseList(second);

    // Larger length LL will be it1/firdt, smaller length LL will be it2/second

    it1=(n>m)?first:second;
    it2=(!(n>m))?first:second;
    first=it1; second=it2;
    Node *prev=NULL;

    int carry=0;

    while (it2!=NULL)
    {
        int sum=(it1->data)+(it2->data)+carry;
        carry=sum/10;
        sum=sum%10;

        it1->data=sum;

        prev=it1;
        it1=it1->next;
        it2=it2->next;
    }


    while(it1!=NULL)
    {
        int sum=(it1->data)+carry;
        carry=sum/10;
        sum=sum%10;

        it1->data=sum;

        it1=it1->next;
    }

    if(carry==0)
    {
        first=reverseList(first);
        return first;
    }
    
    prev->next=new Node(carry);
    first=reverseList(first);

    return first;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *first=new Node(7);
    first->next=new Node(5);

    Node *second=new Node(3);
    second->next=new Node(5);

    addTwoLists(first, second);

    return 0;

}