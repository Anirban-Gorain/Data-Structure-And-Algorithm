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

int findFirstNode(Node* head)

{
    unordered_set<Node *> st;

    while(head!=NULL)
    {
        Node *temp=head->next;
        st.insert(head);

        if(st.find(temp)!=st.end())
            return (*st.find(temp))->data;

        head=temp;
    }

    return -1;
}

// Brute-Force, TC:-O(n), AS:-O(n)

bool detectLoop(Node* head)
{
    unordered_set<Node *> st;

    while(head!=NULL)
    {
        Node *temp=head->next;

        if(st.find(temp)!=st.end())
            return true;

        st.insert(head);
        head=temp;
    }

    return false;
}

// Optimal, TC:-O(n), AS:-O(1)

bool detectLoop(Node* head)
{
    Node *slow=head, *fast=head;

    while(fast!=NULL && (fast->next)!=NULL)
    {
        if(fast==slow)
            return true;

        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }

    return false;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(1);
    Node *temp1=new Node(3);
    Node *temp2=new Node(4);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp1;

    cout<<detectLoop(head);

    return 0;

}