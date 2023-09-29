#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

bool comp(pair<int, int>, pair<int, int>);

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    // Pair --
    // It is a part of <utility> header
    cout << "PAIR --\n";

    pair<int, int>p1={1, 2};
    cout << "First element is " << p1.first << ", Second element is " << p1.second << endl;
    pair<int, int>p2[]={{1, 5}, {4, 3}, {4, 4}};
    cout << p2[1].first << " " << p2[1].second << endl;
    pair<int, pair<int, int>>p3={1, {5, 7}};
    cout << p3.second.second << endl;

    // Vector
    // Vector is part of <vector> header
    cout << "VECTOR --\n";

    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.emplace_back(3);
    vector<int>v2(5, 100);
    cout<<v2.size() << endl;
    vector<pair<int, int>>v3;
    v3.push_back({1, 2});
    v3.emplace_back(4, 5);
    cout << v3[0].first << " " << v3[1].second << endl;
    vector<int>v4(v1);
    for(int i=0; i<v4.size(); i++)
        cout << v4[i] << " "; 
    cout << endl;
    vector<int>::iterator it1=v1.begin();
    cout << *(it1+1) << endl;
    vector<int>::reverse_iterator it2=v1.rend();
    cout<<*(--it2) << endl;
    auto it3=v1.end();
    cout << *(it3-1) << endl;
    auto i4=v1.rbegin();
    cout << *(++i4) << endl;
    for(vector<int>::iterator it=v1.begin(); it!=v1.end(); it++)
        cout << *(it) << " ";
    cout << "\n";
    for(auto it=v1.begin(); it!=v1.end(); it++)
        cout << *(it) << " ";
    cout << "\n";
    for(auto i : v1)
        cout << i << " ";
    cout << "\n";
    for(int i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    cout << "\n";
    v1.erase(v1.begin()+1);
    cout << v1.size() << endl;
    v1.clear();
    for(int i=1; i<= 50; i++)
        v1.push_back(i);
    for(auto i : v1)
        cout << i << " ";
    cout << "\n";
    v1.erase(v1.begin(), v1.begin()+40);
    for(auto i : v1)
        cout << i << " ";
    cout << "\n";
    v1.insert(v1.begin()+2, 99);
    for(auto i : v1)
        cout << i << " ";
    cout << "\n";
    v1.insert(v1.begin(), v1.begin(), v1.end());
    for(auto i : v1)
        cout << i << " ";
    cout << "\n";
    v1.pop_back();
    cout << v1.size() << " " << v2.size() << endl;
    v1.swap(v2);
    cout << v1.size() << " " << v2.size() << endl;

    // List
    // List is part of <list> header
    cout << "LIST --\n";


    list<int> l1;
    l1.push_back(10);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_front(100);
    list<int> l2(5, 10);
    cout << l2.size() << endl;
    list<pair<int, int>> l3;
    l3.push_back({10, 2});
    cout << l3.front().first << endl;
    list<int> l5(l1);
    list<int>::iterator itList1=l1.begin();
    cout << *(itList1);
    list<int>::reverse_iterator itList2=l1.rend();
    cout << endl;

    // Deque
    // Deque is part of <queue> header
    cout << "Deque --\n";

    deque<int> d1;
    d1.push_back(30);
    d1.push_back(55);
    d1.push_back(97);
    d1.push_back(65);
    d1.push_back(53);
    for(auto t : d1)
    {
        cout << t << " ";
    }
    cout << endl;
    d1.push_front(50);
    d1.push_front(39);
    for(auto t : d1)
    {
        cout << t << " ";
    }
    cout << "\n";
    cout << d1.front() << " " << d1.back() << endl;
    d1.pop_back();
    d1.pop_front();
    for(auto t : d1)
    {
        cout << t << " ";
    }
    cout << "\n";

    // Stack
    // Stack is part of <stack> header
    cout << "Stack --\n";

    stack<int> s1;
    s1.push(10);    
    s1.push(11);    
    s1.push(19);    
    s1.push(30);    
    s1.push(47);
    s1.emplace(9);
    cout << s1.top() << "\n";
    cout << s1.size() << "\n";
    cout << s1.empty() << "\n";
    stack<int> s2;
    s1.swap(s2);
    cout << s1.size() << "\n";

    // Priority Queue
    // Priority Queue is part of <queue> header
    cout << "Priority Queue --\n";

    priority_queue<int> pq;
    pq.push(30);
    pq.push(35);
    pq.push(37);
    pq.push(39);
    pq.push(39);
    pq.push(33);
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(30);
    pq1.push(35);
    pq1.push(37);
    pq1.push(39);
    pq1.push(39);
    pq1.push(33);
    cout << pq1.top() << "\n";

    // Set
    // Set is part of <set> header
    cout << "Set --\n";
    
    set<int> st1;
    st1.insert(1);
    st1.insert(1);
    st1.insert(1);
    st1.insert(5);
    st1.insert(7);
    st1.insert(9);
    st1.insert(32);
    cout << st1.size() << "\n";
    auto it=st1.find(5);
    if(it != st1.end())
        cout << "Present \n";
    else
        cout << "Not present \n";
    st1.erase(5);
    it=st1.find(5);
    if(it != st1.end())
        cout << "Present \n";
    else
        cout << "Not present \n";
    cout << st1.count(1) << endl;

    // Multiset
    // Multiset is part of <set> header
    cout << "Multiset --\n";

    multiset<int> m1;
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(5);
    m1.insert(9);
    m1.insert(2);
    m1.insert(8);
    for(auto t : m1)
        cout << t << " ";
    cout << endl;
    m1.erase(1);
    for(auto t : m1)
        cout << t << " ";
    cout << endl;
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    auto m1it=m1.find(1);
    m1.erase(m1it);
    for(auto t : m1)
        cout << t << " ";
    cout << endl;
    cout << m1.count(1);

    // Unordered set
    // Unordered set is part of <unordered_set> header
    cout << "Unordered set --\n";
    
    unordered_set<int> us1;
    us1.insert(1);
    us1.insert(2);
    us1.insert(9);
    us1.insert(7);
    us1.insert(6);
    for(auto it : us1)
        cout << it << " ";
    cout << "\n";
    if(us1.find(8) != us1.end())
        cout << "Element present \n";
    else  
        cout << "Element not found \n";

    // Map
    // Map is part of <map> header
    cout << "Map --\n";

    map<int, int> mp1;
    mp1[1]=2;
    auto mp1it=mp1.begin();
    cout << mp1[1] << "\n";
    mp1[1]++;
    cout << mp1[1] << "\n";
    mp1[5]++;
    cout << mp1[5] << "\n";

    // unordered_map
    // unordered_map is part of <map> header
    cout << "unordered_map --\n";

    unordered_map<int, int> um1;
    um1.insert({1, 5});
    um1.insert({1, 5});
    um1.insert({2, 5});
    um1.insert({7, 5});
    um1.insert({7, 5});
    for(auto it : um1)
        cout << it.first << " " << it.second << "\n";
    cout << "\n";

    // Sorting
    cout << "Sorting --\n";
    
    int a[]={5, 4, 3, 2, 1};
    int len=sizeof(a)/sizeof(int);
    sort(a, a+len);
    for(auto it : a)
        cout << it << " ";
    cout << "\n";
    pair<int, int> parr[]={{1, 2}, {9, 8}, {6, 5}, {6, 3}};
    int parrLen=sizeof(parr)/sizeof(parr[0]);
    cout << parrLen << "\n";
    /*
        Sorting this pair in --
        Based on first .first of ascending order if they same then based on .second of descending order.
    */
   sort(parr, parr+parrLen, comp);
   for(auto it : parr)
   {
        cout << "{" << it.first << ", " << it.second << "} ";
   }
   cout << endl;

    // Permutations
    cout << "Permutations --\n";

    string s="ABC";
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
    cout << "\n";

    // Max and Min element
    cout << "Max and Min element --\n";

    int max=*max_element(a, a+len);
    int min=*min_element(a, a+len);
    cout << max << " " << min;

    // Binary search
    cout << "Binary search --\n";

    int barr[]={1, 2, 3, 9, 30, 48};
    int i1=binary_search(barr, barr+6, 3);
    int i2=binary_search(barr, barr+6, 10);
    cout << i1 << " " << i2 << "\n";

    // LowerBound and UpperBound
    cout << "LowerBound and UpperBound --\n";

    int luArr[]={1, 2, 2, 2, 5, 7, 7, 7, 7, 10, 10, 10, 10, 13, 18};
    cout << lower_bound(luArr, luArr+15, 135)-luArr << endl;
    cout << upper_bound(luArr, luArr+15, 8)-luArr << endl;
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first < p2.first)
        return true;
    else if (p1.first > p2.first)
        return false;
    else
    {
        if(p1.second > p2.second)
        return true;
        else if(p1.second < p2.second)
        return false;
        else
            return true; // For equal
    }   
}