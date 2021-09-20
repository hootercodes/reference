/* Given an array of integers, return an array of multiple-of-3-indexed elements in the original array, in reversed order.

For example, suppose the original array is [2, 1, 3, 6, 5]. Then elements whose indexes are a multiple of 3 are 2 and 6. The returned array is [6, 2].

Hint: you may use stack.*/

#include<bits/stdc++.h> 
using namespace std ;
int  solve(int n, int a[])
{
        int b[n];
        int j=0;
        for(int i=0;i<n;++i )
        {
                if(i%3==0)
                {
                        b[j]=a[i];
                        j++;
                }
        }
        int k=0;
        for(int i=j-1;i>=0;--i)
        {
                a[k]=b[i];
                k++;
        }
        return j ;
}
int main()
{
        int n ;
        cin>>n ;
        int a[n];
        for(int i =0;i<n;++i)
        cin>>a[i];
        int s=solve(n,a);
        
        for(int i =0;i<s;++i)
        cout<<a[i]<<' ';
        
}