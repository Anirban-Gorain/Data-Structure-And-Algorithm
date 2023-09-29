#include<bits/stdc++.h>
using namespace std;

// Brute-Force, TC:-O(n^2) AS:-O(1)

vector<int> findMissingRepeatingNumbers(vector < int > arr)
{
    int len=arr.size();
    int a;
    int flag=false;

    // Getting the number which repeats twice.

    for(int i=0; i<len; i++)
    {
        int elem=arr[0];

        for(int j=0; j<len; j++)
        {
            if(i==j)
                continue;
            
            if(arr[j]==elem)
            {
                a=elem;
                flag=true;
                break;
            }
        }

        if(flag==true)
            break;
    }

    // Getting the missing number

    int sum=0;

    for(int i=0; i<len; i++)
        sum=sum+arr[i];
    
    sum=sum-a;
    int b=len*(len+1);
    b=b/2;
    b=b-sum;

    return {a, b};
}

// Better

vector<int> findMissingRepeatingNumbers(vector < int > arr)
{
    int len=arr.size();
    int a;

    unordered_map<int, int> mp; // (Element, Frequency)

    for(int i=0; i<len; i++)
    {
        mp[arr[i]]++;

        if(mp[arr[i]]==2)
        {
            a=arr[i];
            break;
        }
    }

    // Getting the missing number

    int sum=0;

    for(int i=0; i<len; i++)
        sum=sum+arr[i];
    
    sum=sum-a;
    int b=len*(len+1);
    b=b/2;
    b=b-sum;

    return {a, b};
}

// Optimal, Using math, TC:-O(n) AS:-O(1)

vector<int> findMissingRepeatingNumbers(vector < int > arr)
{
    long long arrSum=0, arrSqSum=0, sumOfNaturalNumbers, sumOfSqOfNaturalNumbers;
    long long len=(long long)arr.size();

    for(int i=0; i<len; i++)
    {
        arrSum=arrSum+(long long)arr[i];
        arrSqSum=arrSqSum+((long long)arr[i]*(long long)arr[i]);
    }

    sumOfNaturalNumbers=len*(len+1)/2;
    sumOfSqOfNaturalNumbers=len*(len+1)*((2*len)+1)/6;


    // x-y

    long long xMy=arrSum-sumOfNaturalNumbers;

    // x^2-y^2

    long long x2My2=arrSqSum-sumOfSqOfNaturalNumbers;

    // x+y

    long long xPy=x2My2/xMy;

    // x

    long long x=(xPy+xMy)/2;

    // y

    long long y=xPy-x;

    return {(int)x, (int)y};
}

// Optimal, Using XOR, TC:-O() AS:-O()

vector<int> findMissingRepeatingNumbers(vector < int > arr)
{
    int len=arr.size();
    int XOROfArray=0;
    int XOROfnNum=0;

    for(int i=0; i<len; i++)
    {
        XOROfArray=XOROfArray^arr[i];
        XOROfnNum=XOROfnNum^(i+1);
    }

    int xXORy=XOROfArray^XOROfnNum;

    // Finding set bit position in XOR

    int stBitPos=0;

    while(!(xXORy&(1<<stBitPos)))
        stBitPos++;

    // There are three types in combine (arr and 1-N), num rep for 2, rep for 3, rep for 1.

    int cat1=0, cat2=0;

    for(int i=0; i<len; i++)
    {
        if(arr[i]&(1<<stBitPos))
        {
            cat1=cat1^arr[i];
        }
        else
        {
            cat2=cat2^arr[i];
        }

        if((i+1)&(1<<stBitPos))
        {
            cat1=cat1^(i+1);
        }
        else
        {
            cat2=cat2^(i+1);
        }
    }

    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(arr[i]==cat1)
            cnt++;
    }

    if (cnt==2)
    {
        return {cat1, cat2};
    }

    return {cat2, cat1};
}