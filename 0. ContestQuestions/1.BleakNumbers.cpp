/*
    To represent numbers from [1, n] we need max log(n)_2 number of bits.
*/

int is_bleak(int n)
{
    for(int i=((n-28)>0?(n-28):1); i<=n-1; i++)
    {
        int sum=i+__builtin_popcount(i);
        
        if(sum==n)
            return 0;
    }
    
    return 1;
}