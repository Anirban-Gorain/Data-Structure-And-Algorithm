#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

void deleteAllOccurOfX(struct Node** head_ref, int key)
{
    Node *head=*head_ref;
    Node *it=head;
    it=head;
    
    while(it!=NULL)
    {
        if(it->data!=key)
        {
            it=it->next;
            continue;
        }
        else if(it->next==NULL && it->prev==NULL)
        {
            *head_ref=NULL;
            break;
        }
        else if(it->next==NULL)
        {
            // Last node
            
            it->prev->next=NULL;
            it=NULL;
        }
        else if(it->prev==NULL)
        {
            // Head Node
            
            head=head->next;
            *head_ref=head;
            it=it->next;
            it->prev=NULL;
        }
        else
        {
            // Middle node
            
            Node *next=it->next;
            it->prev->next=it->next;
            it->next->prev=it->prev;
            it=next;
        }
    }
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(2);
    head->next=new Node(5);
    head->next->prev=head;
    head->next->next=new Node(5);

    return 0;

}