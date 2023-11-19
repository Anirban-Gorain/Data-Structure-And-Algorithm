#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *merge(Node *left, Node *right)
{
    Node *dummy=new Node(-1);
    Node *lastInDummy=dummy;

    if(left==NULL)
        return right;
    
    if(right==NULL)
        return left;

    while(left!=NULL && right!=NULL)
    {
        if((left->data)<(right->data))
        {
            lastInDummy->bottom=left;
            lastInDummy=left;
            left=left->bottom;
        }
        else
        {
            lastInDummy->bottom=right;
            lastInDummy=right;
            right=right->bottom;
        }
    }

    while(left!=NULL)
    {
        lastInDummy->bottom=left;
        lastInDummy=left;
        left=left->bottom; 
    }

    while(right!=NULL)
    {
        lastInDummy->bottom=right;
        lastInDummy=right;
        right=right->bottom;
    }

    Node *ans=dummy->bottom;

    return ans;
}

Node *flatten(Node *root)
{
   Node *dummy=NULL, *it=root;

   while(it!=NULL)
   {
        dummy=merge(dummy, it);
        it=it->next;
   }


   return dummy;
}

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}