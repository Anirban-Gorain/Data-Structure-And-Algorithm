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

// Brute-Force, TC:-O(2n), AS:-O(1)

// Optimal, TC:-O(n), AS:-O(1)

Node* deleteMid(Node* head)
{
    Node *fast=head;
    Node *slow=head;

    if(fast->next==NULL)
        return NULL;

    while((fast->next->next)!=NULL && (fast->next->next->next)!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }

    slow->next=slow->next->next;

    return head;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}