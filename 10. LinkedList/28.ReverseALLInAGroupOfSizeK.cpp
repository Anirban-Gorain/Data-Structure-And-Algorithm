#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;

struct node *reverse (struct node *head, int k)
{ 
    int cnt=0, updateHead=true, updateTempHead=true, isMultipleOfK;
    node *it=head, *prev=NULL, *tempHead, *prevTempHead, *tail, *next;
    
    while(it!=NULL)
    {
        cnt++;
        isMultipleOfK=0;
        
        if(updateTempHead)
        {
            updateTempHead=false;
            tempHead=it;
        }
        
        tail=it;
        next=it->next;
        tail=it;
        it->next=prev;
        prev=it;
        it=next;
        
        
        if(cnt==k)
        {
            cnt=0; updateTempHead=true;
            if(updateHead)
            {
                updateHead=false;
                head=tail;
                prevTempHead=tempHead;
                prev=NULL;
                isMultipleOfK=1;
                continue;
            }
            
            prevTempHead->next=tail;
            prev=NULL;
            prevTempHead=tempHead;
            
            isMultipleOfK=1;
        }
    }
    
    if(isMultipleOfK!=1)
        prevTempHead->next=tail;
    
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