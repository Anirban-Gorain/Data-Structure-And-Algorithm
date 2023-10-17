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

// Brute-Force, TC:-O(n), AS:-O(n)

Node* divide(int N, Node *head)
{
    // Reaching the last Node.

    Node *it=head;
    vector<int> even;
    vector<int> odd;

    // Storing the Even

    while(it!=NULL)
    {
        if((it->data)==0)
            even.push_back(it->data);
        else
            odd.push_back(it->data);

        it=it->next;
    }

    it=head;

    for(int elem : even)
    {
        it->data=elem;
        it=it->next;
    }

    for(int elem : odd)
    {
        it->data=elem;
        it=it->next;
    }

    return head;
}

// Optimal, TC:-O(n), AS:-O(1)

// Complex

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}