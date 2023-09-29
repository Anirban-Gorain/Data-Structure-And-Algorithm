#include<bits/stdc++.h>
using namespace std;

void ptn1(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<n; cols++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void ptn2(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<=rows; cols++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void ptn3(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<=rows; cols++)
        {
            cout<<cols+1;
        }
        cout<<endl;
    }
}
void ptn4(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<=rows; cols++)
        {
            cout<<rows+1;
        }
        cout<<endl;
    }
}
void ptn5(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<n-rows; cols++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void ptn6(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<n-rows; cols++)
        {
            cout<<cols+1;
        }
        cout<<endl;
    }
}
void ptn7(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int cols=0; cols<n-rows; cols++)
        {
            cout<<cols+1;
        }
        cout<<endl;
    }
}
void ptn8(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int sps=1; sps<=n-rows-1; sps++)
            cout<<" ";

        for(int cols=0; cols<2*rows+1; cols++)
        {
            cout<< "*";
        }
        cout<<endl;
    }
}
void ptn9(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int sps=0; sps<rows; sps++)
            cout<<" ";

        for(int cols=0; cols<2*(n-1-rows)+1; cols++)
        {
            cout<< "*";
        }
        cout<<endl;
    }
}
void ptn10(int n)
{
    int start;
    for(int rows=0; rows<n; rows++)
    {
        if(rows%2==0)
            start=1;
        else
            start=0;
        for(int cols=0; cols<=rows; cols++)
        {
            cout<<start;
            start=1-start;
        }
        cout<<endl;
    }
}
void ptn11(int n)
{
    int spaces = 2*n-2;
    for(int rows=1; rows<=n; rows++)
    {
        for(int cols=1; cols<=rows; cols++)
        {
            cout<<cols;
        }

        // Spaces

        for(int sps=1; sps<=spaces; sps++)
        {
            cout<<" ";
        }
        spaces-=2;

        for(int cols=rows; cols>=1; cols--)
        {
            cout<<cols;
        }

        cout<<endl;
    }
}
void ptn12(char n)
{
    for(char rows='A'; rows<=n; rows++)
    {
        for(char cols='A'; cols<=rows; cols++)
        {
            cout<<cols;
        }
        cout<<endl;
    }
}
void ptn13(char n)
{
    for(char rows=n; rows>='A'; rows--)
    {
        for(char cols='A'; cols<=rows; cols++)
        {
            cout<<cols;
        }
        cout<<endl;
    }
}
void ptn14(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        for(int sps=1; sps<=(n-1-rows); sps++)
        {
            cout<<" ";
        }
        char ltr='A';
        
        int breakPoint=(2*rows+1)/2+1;
        for(int cols=1; cols<=2*rows+1; cols++)
        {
            cout<<ltr;
            if(cols<breakPoint)
                ltr++;
            else
                ltr--;
        }
        cout<<endl;
    }
}
void ptn15(int n)
{
    for(int rows=0; rows<n; rows++)
    {
        char print='E'-rows;

        for(int cols=0; cols<=rows; cols++)
        {
            cout<<print;
            print++;
        }
        cout<<endl;
    }
}
void ptn16(int n)
{
    int inisps=0;
    
    for(int rows=0; rows<n; rows++)
    {
        // Stars
        for(int cols=1; cols<=n-rows; cols++)
            cout<<"*";
        // Spaces
        for(int cols=1; cols<=inisps; cols++)
            cout<<" ";
        // Stars
        for(int cols=1; cols<=n-rows; cols++)
            cout<<"*";
        
        cout<<endl;
        inisps+=2;
    }

    inisps=2*n-2;

    for(int rows=0; rows<n; rows++)
    {
        // Stars
        for(int cols=1; cols<=rows+1; cols++)
            cout<<"*";
        // Spaces
        for(int cols=1; cols<=inisps; cols++)
            cout<<" ";
        // Stars
        for(int cols=1; cols<=rows+1; cols++)
            cout<<"*";
        
        cout<<endl;
        inisps-=2;
    }

}
void ptn17(int n)
{
    int inisps=2*n-2;

    for(int rows=0; rows<n-1; rows++)
    {
        // Stars
        for(int cols=1; cols<=rows+1; cols++)
            cout<<"*";
        // Spaces
        for(int cols=1; cols<=inisps; cols++)
            cout<<" ";
        // Stars
        for(int cols=1; cols<=rows+1; cols++)
            cout<<"*";
        
        cout<<endl;
        inisps-=2;
    }

    inisps=0;
    
    for(int rows=0; rows<n; rows++)
    {
        // Stars
        for(int cols=1; cols<=n-rows; cols++)
            cout<<"*";
        // Spaces
        for(int cols=1; cols<=inisps; cols++)
            cout<<" ";
        // Stars
        for(int cols=1; cols<=n-rows; cols++)
            cout<<"*";
        
        cout<<endl;
        inisps+=2;
    }
}
void ptn18(int n)
{
    for(int fstRow=1; fstRow<=n; fstRow++)
        cout<<"*";
    cout<<endl;
    for(int midRows=1; midRows<=n-2; midRows++)
    {
        cout<<"*";
        for(int cols=1; cols<=n-2; cols++)
        {
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for(int lstRow=1; lstRow<=n; lstRow++)
        cout<<"*";
}
void ptn19(int n)
{
    for(int rows=0; rows<2*n-1; rows++)
    {
        for(int cols=0; cols<2*n-1; cols++)
        {
            int top=rows;
            int bottom=(2*n-2)-rows;
            int left=cols;
            int right=(2*n-2)-cols;
            int minDistance=min(min(left, right),min(top, bottom));
            cout<<n-minDistance;
        }
        cout<<endl;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    int t, n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        
        ptn16(n);
    }
}