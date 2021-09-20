#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int sumOfEle(list<int>l)
{
    int s=0;
    //find the sum of elements which are multiple of 5
    for(auto it=l.begin();it!=l.end();++it)
    {
        if(*it%5==0)
        {
            s=s+*it;
        }
    }
    return s;
}
int main()
{
    list<int>lt;
    //add elements to list
    for(int i=0;i<=15;i++)
    {
        lt.push_back(i);
    }
    //print the list
    cout<<"elements of list: "<<endl;
    for(auto it=lt.begin();it!=lt.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //print the answer
    cout<<"Sum of element which are multiple of 5: "<<sumOfEle(lt)<<endl;
    

    return 0;
}
