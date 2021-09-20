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
