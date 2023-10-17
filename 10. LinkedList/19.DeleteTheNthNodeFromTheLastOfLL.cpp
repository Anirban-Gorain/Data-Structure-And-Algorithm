#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute-Force, TC:-O(2n), AS:-O(1)

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int len=0;
    ListNode *it=head;

    while(it!=NULL)
    {
        len++;
        it=it->next;
    }

    int fromFirst=len-n+1;

    if(fromFirst==1)
    {
        ListNode *cpyHead=head;
        head=head->next;
        delete cpyHead;
        return head;
    }

    it=head;

    for(int i=1; i<=fromFirst-2; i++)
    {
        it=it->next;
    }

    ListNode *toBeDeleted=it->next;
    it->next=it->next->next;

    delete toBeDeleted;

    return head;
}

// Optimal, TC:-O(n), AS:-O(1)

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *fast, *slow;
    fast=slow=head;

    for(int i=1; i<=n; i++)
        fast=fast->next;
    
    if(fast==NULL)
    {
        head=head->next;
        return head;
    }

    while((fast->next)!=NULL)
    {
        fast=fast->next;
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