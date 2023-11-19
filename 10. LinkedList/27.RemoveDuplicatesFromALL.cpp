#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

// Brute-Force, TC:-O(n^2), AS:-O(1)

// Better, TC:-O(n), AS:-O(1)

// Optimal, TC:-O(n), AS:-O(1)

Node * removeDuplicates(struct Node *head)
{
    Node *uniques=head, *it=head->next;
    
    while(it!=NULL)
    {
        if(it->data==uniques->data)
        {
            it=it->next;
            continue;
        }
        
        uniques=uniques->next;
        uniques->data=it->data;
    }
    
    uniques->next=NULL;
    
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