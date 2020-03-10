#include <iostream>
using namespace std;

void print_DFS(int**edges,int n , int sv, bool *visited){
    
    cout<<sv<<" ";
    visited[sv] = true;
    
    for(int i = 0;i<n;i++){
        if(i==sv)
            continue;
        if(edges[i][sv]==1 && visited[i]==false){
            print_DFS(edges,n,i,visited);
        }
        
    }
    
    
}
int main() {
    int V, E;
    cin >> V >> E;

    int ** edges = new int*[V];
    for(int i = 0; i <V; i++){
        edges[i] = new int[V];
        for(int j = 0 ; j<V;j++)
            edges[i][j]= 0;
    }
    
    for(int i = 0 ; i <E; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
        
    }
    
    bool *visited = new bool[V];
    
    for(int i = 0; i<V ; i++)
        visited[i] = false;
    
    print_DFS(edges,V,0,visited);

    delete [] visited;
    
    for(int i =0; i<V; i++)
        delete [] edges[i];
    
    delete [] edges;

    return 0;
}
