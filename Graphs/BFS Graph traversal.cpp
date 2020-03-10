
#include <iostream>
#include<queue>
using namespace std;

void print_BFS(int **edges,int n, int sv, bool *visited){
 
    queue<int> q;

    q.push(sv);
    visited[sv] = true;

    while(!q.empty()){

        int v = q.front();
        cout<<v<<" ";
        q.pop();

        for(int i = 0; i<n; i++){
            if(i==v)
                continue;
            if(edges[v][i]==1 && visited[i]==false){
                q.push(i);
                visited[i] = true;
            }   
        }       
    }   
}

int main() {
    int V, E;
    cin >> V >> E;
    
    // Creating adjacency matrix
    int ** edges = new int*[V];
    for(int i = 0; i <V; i++){
        edges[i] = new int[V];
        for(int j = 0 ; j<V;j++)
            edges[i][j]= 0;
    }
    
    // Initializing values of vertices connected with edges
    for(int i = 0 ; i <E; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
        
    }
    
    bool *visited = new bool[V];
    
    for(int i = 0; i<V ; i++)
        visited[i] = false;
    
    // Handling case when theres is an unconnected graph
    for(int i = 0; i<V ; i++){
        if(!visited[i])
            print_BFS(edges,V,i,visited);
    }
    
  return 0;
}
