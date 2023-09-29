#include<iostream>
using namespace std;

// P1) Print name for n times using recursion.

void printName(int i, int n)
{
    if(i>n)
        return;

    cout << "Ani ";
    printName(i+1, n);
}

// P2) Print from 1-n using recursion.

void printOneToN(int i, int n)
{
    if(i>n)
        return;

    cout << i << " ";
    printOneToN(i+1, n);
}

// P3) Print from n-1 using recursion.

void printNToOne(int i, int n)
{
    if(i<1)
        return;

    cout << i << " ";
    printNToOne(i-1, n);
}

// P4) Print from 1-n using recursion, using a single parameter.

void printOneToN2(int n)
{
    if(n<1)
        return;

    printOneToN2(n-1);
    cout << n << " ";
}

// P5) Print from n-1 using recursion, using a single parameter.

void printNToOne2(int n)
{
    if(n<1)
        return;

    cout << n << " ";
    printNToOne2(n-1);
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    printName(1, 5);
    cout << "\n";
    printOneToN(1, 5);
    cout << "\n";
    printNToOne(5, 5);
    cout << "\n";
    printOneToN2(5);
    cout << "\n";
    printNToOne2(5);
    cout << "\n";
    return 0;
}