#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Better, TC:-O(n), AS:-O(n)

Node* segregate(Node *head) 
{
    vector<Node *> zeros;
    vector<Node *> ones;
    vector<Node *> twos;
    
    for(Node *it=head; it!=NULL; it=it->next)
    {
        if(it->data==0)
            zeros.push_back(it);
        else if(it->data==1)
            ones.push_back(it);
        else
            twos.push_back(it);
    }

    // Deciding the headOf the LL.

    if(zeros.size()!=0)
        head=zeros[0];
    else if(ones.size()!=0)
        head=ones[0];
    else 
        head=twos[0];

    // Linking 0's 1's 2's individually.

    int nZ=zeros.size()-1, nO=ones.size()-1, nT=twos.size()-1;

    for(int i=0; i<nZ; i++)
        zeros[i]->next=zeros[i+1];

    for(int i=0; i<nO; i++)
        ones[i]->next=ones[i+1];

    for(int i=0; i<nT; i++)
        twos[i]->next=twos[i+1];

    // Linking ones after all the zeros, linking tows after all ones.

    if(zeros.size()!=0)
    {
        if(ones.size()!=0)
        {
            zeros[zeros.size()-1]->next=ones[0];
        }
        else
        {
            if(twos.size()!=0)
            {
                zeros[zeros.size()-1]->next=twos[0];
            }
            else
            {
                zeros[zeros.size()-1]->next=NULL;
            }
        }
    }

    if(ones.size()!=0)
    {
        if(twos.size()!=0)
        {
            ones[ones.size()-1]->next=twos[0];
        }
        else
        {
            ones[ones.size()-1]->next=NULL;
        }
    }

    if(twos.size()!=0)
    {
        twos[twos.size()-1]->next=NULL;
    }

    return head;
}

// Optimal, TC:-O(n), AS:-O(1)

// Complex implementation, but possible.

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    Node *head=new Node(2);    
    head->next=new Node(2);    
    head->next->next=new Node(1);    
    head->next->next->next=new Node(2);    
    head->next->next->next->next=new Node(1);

    segregate(head); 

    return 0;
}