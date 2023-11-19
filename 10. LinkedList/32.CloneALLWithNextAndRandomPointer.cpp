#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

// Brute-Force, TC:-O(n^2), AS:-O(1)

// Better, TC:-O(n/n*logn), AS:-O(n)

Node *copyList(Node *head)
{
    Node *dummy=new Node(-1);
    Node *it1=head, *it2=dummy;
    unordered_map<Node *, Node *> mp;
    
    while(it1!=NULL)
    {
        it2->next=new Node(it1->data);
        
        mp.insert({it1, (it2->next)});
        
        it2=it2->next;
        it1=it1->next;
    }
    
    Node *newHead=dummy->next;
    it1=head;
    it2=newHead;
    
    while(it1!=NULL)
    {
        if((it1->arb)!=NULL)
        {
            it2->arb=mp[it1->arb];
        }
        
        it2=it2->next;
        it1=it1->next;
    }
    
    return newHead;
}

// Optimal, TC:-O(n), AS:-O(1)


Node *copyList(Node *head)
{
    Node *it1=head;
    Node *newNode=new Node(-1);
    Node *it2=newNode;

    while(it1!=NULL)
    {
        Node *next=it1->next;

        Node *temp=new Node(it1->data);
        it2->next=temp;
        it1->next=it2->next;
        it2->next->next=next;

        it1=next;
        it2->next=temp;
    }

    Node *newHead=head->next;
    it1=head;

    while (it1!=NULL)
    {
        Node *next=it1->next->next;

        if((it1->arb)!=NULL)
        {
            it1->next->arb=it1->arb->next;
        }

        it1=next;
    }
    
    it1=head;

    while(it1!=NULL)
    {
        Node *next=it1->next->next;
        it1->next->next=(next!=NULL)?(next->next):NULL;
        it1->next=next;
        it1=next;
    }

    return newHead;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *one=new Node(1);
    Node *two=new Node(2);
    Node *three=new Node(3);
    Node *four=new Node(4);
    Node *five=new Node(5);

    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;

    one->arb=three;
    three->arb=five;
    five->arb=two;
    two->arb=one;
    four->arb=three;

    Node *head=one;

    copyList(head);

    return 0;

}