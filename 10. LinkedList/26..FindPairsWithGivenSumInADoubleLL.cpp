#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

// Brute-Force, TC:-O(n^2), AS:-O(1)
// Better, TC:-O(n), AS:-O(n)
// Optimal, TC:-O(n), AS:-O(1)

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;
    
    Node *it1=head, *it2=head;
    int start=0, end=0;
    
    // it2 should be at the end node.
    
    while(it2->next!=NULL)
    {
        it2=it2->next;
        end++;
    }
        
    while(start<end)
    {
        int sum=(it1->data)+(it2->data);
        
        if(sum==target)
        {
            ans.push_back({it1->data, it2->data});
            
            it1=it1->next;
            it2=it2->prev;
            
            start++;
            end--;
        }
        else if(sum>target)
        {
            it2=it2->prev;
            end--;
        }
        else
        {
            it1=it1->next;
            start++;
        }
    }
    
    
    return ans;
}


int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}