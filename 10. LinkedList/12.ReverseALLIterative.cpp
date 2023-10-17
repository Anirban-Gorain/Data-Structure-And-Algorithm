#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Optimal, TC:-O(n) and AS:-O(1)

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

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}