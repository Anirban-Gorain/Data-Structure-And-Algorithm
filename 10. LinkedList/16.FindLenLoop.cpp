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

// Brute-Force, TC:-O(n), AS:-O(n)

int countNodesinLoop(Node *head)
{
    unordered_map<Node *, int> st;
    int count=0;

    while(head!=NULL)
    {
        count++;

        Node *temp=head->next;
        st.insert({head, count});

        if(st.find(temp)!=st.end())
        {
            int len=count-(st.find(temp)->second)+1;
            return len;
        }

        head=temp;
    }

    return 0;
}

// Optimal, TC:-O(n), AS:-O(1)

Node *findFirstNode(Node* head)
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

            return slow;
        }
    }

    return NULL;
}

int countNodesinLoop(Node *head)
{
    Node *startingPoint=findFirstNode(head);

    if(startingPoint==NULL)
        return 0;

    int count=1;
    Node *it=startingPoint->next;

    while(it!=startingPoint)
        count++;
    
    return count;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}