#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int findMinVertex(int * weights,bool *visited, int V){
    
    int minVertex = -1;
    
    for(int i=0; i<V; i++){
        if(!visited[i] && (minVertex==-1 || weights[i]<weights[minVertex]))
            minVertex = i;
    }
    
    return minVertex;
}

void prims(int ** graph, int V, int E){
    
    bool * visited = new bool[V];
    int * weights = new int[V];
    int * parents = new int[V];
    
    for(int i = 0 ; i<V; i++){
        weights[i] = INT_MAX;
    	parents[i] = -1;
        visited[i] = false;
    }
    weights[0] =0;
    
    for(int i =0; i <V-1; i++){
        
        int minVertex = findMinVertex(weights,visited,V);
        visited[minVertex] = true;
        
        for(int j=0; j<V; j++){
            if(graph[minVertex][j]!=0 && !visited[j]){
                if(weights[j]>graph[minVertex][j]){
                    weights[j] = graph[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }
    
    for(int i = 1; i<V; i++){
        cout<<min(i,parents[i])<<" "
            <<max(i,parents[i])<<" "
            <<weights[i]<<endl;
    }
    
}

int main()
{
  int V, E;
  cin >> V >> E;

    int ** graph = new int*[V];
    for(int i = 0; i<V; i++){
        graph[i] = new int[V];
        for(int j =0; j<V; j++)
            graph[i][j] = 0;
    }
    
    
  for(int i =0; i<E; i++){
      int v1,v2,w;
      cin>>v1>>v2>>w;
      
      graph[v1][v2] = w;
      graph[v2][v1] = w;
  }
    
    prims(graph,V,E);

  return 0;
}
