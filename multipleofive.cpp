#include<bits/stdc++.h>
using namespace std;


int multiplesOfFive(list <int> l)
{
    
    list<int> :: iterator it;

    
    int sum = 0;

    
    for(it = l.begin();it != l.end(); it++)
    {
        if(*it % 5 == 0)
        {
            
            sum = sum + (*it);
        }
    }

    
    return sum;
}


int main()
{

    
    list <int> l;

    
    l.push_back(1);
    l.push_back(5);
    l.push_back(25);
    l.push_back(37);
    l.push_back(7);
    l.push_back(10);
    l.push_back(18);
    l.push_back(15);

    
    int ans = multiplesOfFive(l);


    cout<<"Sum of all the elements that are a multiple of 5 in the list are: "<<ans<<endl;

    return 0;
}
