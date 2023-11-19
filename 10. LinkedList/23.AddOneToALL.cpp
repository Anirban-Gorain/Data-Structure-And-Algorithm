#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
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

Node* addOne(Node *head) 
{
    head=reverseList(head);

    for(Node *it=head; it!=NULL; it=it->next)
    {
        if((it->data)<9)
        {
            (it->data)++;
            head=reverseList(head);
            return head;
        }
        else
        {
            it->data=0;
        }

    }

    Node *temp=new Node(1);

    temp->next=head;

    return temp;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}