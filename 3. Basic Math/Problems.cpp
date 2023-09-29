#include<iostream>
using namespace std;

int reverseDigit(int n)
{
    int revN=0;

    while(n>0)
    {
        int lastDig=n%10;
        revN=revN*10+lastDig;
        n=n/10;
    }

    return revN;
}

int checkPalindrome(int n)
{
    int rev=reverseDigit(n);

    if(rev==n)
        cout << "Number is palindrome \n";
    else
        cout << "Number is not palindrome \n";
    return 0;
}

int checkArmstrong(int n)
{
    int cpyN=n;
    int cubeSum=0;

    while(n>0)
    {
        int lastDig=n%10;
        cubeSum=cubeSum+(lastDig*lastDig*lastDig);
        n=n/10;
    }
    if(cpyN==cubeSum)
        cout << "Armstrong number \n";
    else
        cout << "Not an Armstrong number \n";

    return 0;
}

void printFactors(int n)
{
    for(int i=1; i*i<=n /*sqrt(n)*/; i++)
    {
        if(n%i==0)
            cout << i << " ";
        if(n%i==0 && i*i!=n)
            cout << n/i << " ";
    }
    cout << "\n";
}

void checkPrime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cout << "Not a prime number\n";
            return;
        }
    }

    cout << "Prime number\n";
}

int gcd(int x1, int x2)
{
    int minNo=min(x1, x2);
    int gcd=1;
    
    for(int i=2; i*i<=minNo; i++)
    {
        if(x1%i==0 && x2%i==0)
            gcd=i;
        if(minNo%i==0 && i*i!=minNo)
        {
            int fac2=minNo/i;
            if(x1%fac2==0 && x2%fac2==0)
                gcd=i;
        }
    }
    return gcd;
}

// Euclidean using iterative method

int euclidean1(int x1, int x2)
{
    while (x1>0 && x2>0)
    {
        if(x1<x2)
            swap(x1, x2);

        x1=x1%x2;
    }

    if(x1==0)
        return x2;
    return x1;
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    cout << reverseDigit(1234) << "\n";
    checkPalindrome(121);
    checkArmstrong(1634);
    printFactors(36);
    checkPrime(7);
    cout << gcd(5, 7) << "\n";
    cout << euclidean1(10, 5);
    
    return 0;
}