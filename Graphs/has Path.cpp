#include <iostream>
using namespace std;


bool hasPath(int **edges,int n, int s, int e, bool *visited){
    
    if(edges[s][e]==1 || s==e)
        return true;
    
    visited[s] = true;
    for(int i = 0;i<n; i++){
        
        if(edges[s][i]==1 && visited[i]==false){
            bool ans = hasPath(edges,n,i,e,visited);
            if(ans)
                return true;
        }
    }
  
    return false;
}


int main() {
    int V, E;
    cin >> V >> E;

      
    int **edges = new int*[V];
    for(int i =0; i<V; i++){
        edges[i] =new int[V];
        for(int j = 0; j<V; j++)
            edges[i][j] = 0;
    }
    
    for(int i =0; i<E; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int s,e;
    cin>>s>>e;
    
    bool *visited = new bool[V];
    
    for(int i = 0; i<V ; i++)
        visited[i] = false;
    
    if(hasPath(edges,V,s,e,visited))
        cout<<"true";
    else
        cout<<"false";
    
    
    
  return 0;
}


