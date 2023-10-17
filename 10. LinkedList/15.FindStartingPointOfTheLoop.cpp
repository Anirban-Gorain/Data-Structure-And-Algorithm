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

int findFirstNode(Node* head)
{
    unordered_set<Node *> st;

    while(head!=NULL)
    {
        Node *temp=head->next;

        if(st.find(temp)!=st.end())
            return (*st.find(temp))->data;

        st.insert(head);
        head=temp;
    }

    return -1;
}

// Optimal, TC:-O(n), AS:-O(1)

int findFirstNode(Node* head)
{
    Node *slow=head, *fast=head;

    while(fast!=NULL && (fast->next)!=NULL)
    {
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
        
        if(fast==slow)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }

            return slow->data;
        }
    }

    return -1;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}