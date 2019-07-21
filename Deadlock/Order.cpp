Question -> A job order given by a client consist of N tasks, numbered 1, 2, 3, ..., N . However, some tasks may depend on other tasks. 
For instance, given 9 tasks, if task 4 depends on task 6, task 6 depends on task 8, and task8 depends on task 5 and no other dependencies 
are there, then tasks could be carried out in one possible order 1, 2, 3, 5, 7, 8, 9, 6, 4. However, other orders may also exist. We 
need to order the execution of these tasks based on the dependencies, that is, a task is done after all its dependencies are executed.
However, there could be peculiar situations such as task 3 depending on 8, task 8 depending on task 7 and task 7 depending on task 3. 
This is called a deadlock situation, where the dependencies form a loop, and it is not possible to execute the set of tasks. Given a set
of tasks, and a set of dependencies, your program should determine if this is going to result in a deadlock. If there is no possibility 
of a deadlock then the program should print all possible tasks that could be executed first in any valid ordering of tasks. If there is 
a deadlock for the given set of tasks, output -1. In a case of no deadlock, Output a list of all possible tasks, in ascending order, that 
could be initiated at the beginning.

Input:
The first line contains two single space separated integers N and D, where N is the number of tasks and
D is the number of dependencies.
Next D lines contain two single space separated integers x and y where x and y are task IDs (1-based)
and task y is dependent on task x.

Constraints:
1 ≤ D ≤ N (N − 1)
1 ≤ x, y ≤ N, x ̸= y
Easy: 1 ≤ N ≤ 10
Advanced: 1 ≤ N ≤ 500

Solution:

#include<bits/stdc++.h>
#include<iostream> 
#include <list> 
#include <limits.h> 
#include <algorithm>

using namespace std; 
  
class Graph 
{ 
    int V;   
    list<int> *adj;    
    bool isCyclicUtil(int v, bool visited[], bool *rs); 
public: 
    Graph(int V);    
    void addEdge(int v, int w); 
    bool isCyclic(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
   
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    {  
        visited[v] = true; 
        recStack[v] = true; 
  
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  
    return false; 
} 
  

bool Graph::isCyclic() 
{ 
   
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 1; i <V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    
    for(int i = 1; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 
  
int main() 
{ 
    int l=0;
    int N,D;
    
    int k=0;
    cout<<"Enter N and D\n";
    cin>>N>>D;
    Graph g(N);

    int R = N*(N-1);

    int arr[R];
    int x[R];
    int y[R];

    cout<<"Enter " << D <<" Edge\n";
    for(int i=0;i<D;i++)
    {
        int p,q;
        cin>>p>>q;
        g.addEdge(q-1,p-1);
        x[k]=p;
        y[k]=q;
        k++;
    }
     
    int size=k;
      
    if(g.isCyclic()) 
    {
        cout<<"\n";
        cout<<"-1";
    } 
    else
    {
        sort(x,x+size);
        sort(y,y+size);
        int j=0;

        int m=1;
        while(m<=N)
        {
            if (binary_search(x, x + size,m) && !(binary_search(y, y+ size,m)))
            {
                arr[l]=m;
                l++;
                m++;
            } 
            else
            {
                m++;
            }
        }      
    } 
    cout<<"\n";
    for(int i=0;i<l;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    return 0; 
} 
