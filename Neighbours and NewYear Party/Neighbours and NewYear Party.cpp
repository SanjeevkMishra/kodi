#include <iostream>
#include <queue> 
#include <bits/stdc++.h> 

using namespace std;
void reverseQueue(queue<int>& Queue) 
{ 
    stack<int> Stack; 
    while (!Queue.empty()) { 
        Stack.push(Queue.front()); 
        Queue.pop(); 
    } 
    while (!Stack.empty()) { 
        Queue.push(Stack.top()); 
        cout<<Stack.top();
        Stack.pop(); 
    } 
}

int main()
{
    int i,j,n,t;
    cin>>t;
    for(j=0;j<t;j++){
    cin>>n;
    int a[n];
    queue <int> inc;
    queue <int> exc;
    queue <int> exc1;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int incl=a[0],excl=0,count=0,max;
    inc.push(a[0]);
    for(i=1;i<n;i++){
    int nw = (incl>excl)? incl:excl;
    if(nw==incl){
      exc1 = inc;
      count++;
    }
    incl = excl + a[i];
    inc=exc;
    if(a[i]==0)
    goto skip;
    inc.push(a[i]);
    skip: excl = nw;
    if(count==1){
        exc=exc1;
        count=0;
    }
    }
    if(incl==excl){
        max =  (inc.back()>exc.back())? inc.back():exc.back();
    }
    else{
    max = (incl>excl)? incl:excl;}
    if((max==incl)||(max==inc.back())){
        reverseQueue(inc);
    }
    else if((max==excl)||(max==exc.back()))
    reverseQueue(exc);
    }
    
}
