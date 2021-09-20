#include<bits/stdc++.h>
using namespace std;
queue<int> findCommanElement(queue<int>q1,queue<int>q2){
    queue<int>q3;   
  
    
    while(q1.size()>0 && q2.size()>0){  
        if(q1.front()==q2.front()){
            q3.push(q1.front());
            q1.pop();
            q2.pop();
        }
        else if(q1.front() > q2.front()){
            q2.pop();
        }
        else{
            q1.pop();
        }
    }
return q3;   
}
int main(){

    
    std::queue<int>q1,q2;
    int n1,n2;

    
    cout<<"Enter the no of element in queue1: ";
    cin>>n1;
    int element;
    for(int i=0;i<n1;i++){
        cout<<"enter the element"<<i+1<<": ";
        cin>>element;
        q1.push(element);
    }
    cout<<"Enter the no of element in queue2: ";
    cin>>n2;
    for(int i=0;i<n2;i++){
        cout<<"enter the element"<<i+1<<": ";
        cin>>element;
        q2.push(element);
    }
  
    
    queue<int> q3=findCommanElement(q1,q2);

    
    cout<<endl;
    cout<<"Common Elements are: ";
    while(!q3.empty()){
      cout<<q3.front()<<" ";
      q3.pop();
    }
    cout<<endl;
    return 0;
}
