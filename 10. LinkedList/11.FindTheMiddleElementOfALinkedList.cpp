#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    
};

// Brute-Force, TC:-O(n), AS:-O(n)

// Better, TC:-O(2n), AS:-O(1)

int getMiddle(Node *head)
{
    // Counting the length of LL

    int len=0;
    Node *it=head;

    while(it!=NULL)
    {
        it=it->next;
        len++;
    }

    // Middle element

    int middle=(len/2)+1;

    for(int i=1; i<middle; i++)
    {
        head=head->next;
    }

    return head->data;
}

// Optimal, TC:-O(n), AS:-O(1)

int getMiddle(Node *head)
{
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL && (fast->next)!=NULL)
    {
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }

    return slow->data;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}