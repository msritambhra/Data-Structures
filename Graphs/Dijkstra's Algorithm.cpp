#include <iostream>
using namespace std;
#include<climits>

int findMinVertex(bool *visited, int*distance, int V){
    
    int minVertex = -1;
    for(int i = 0; i<V; i++){
        if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
            minVertex = i;
    }
    
    return minVertex;
}

void dijstrak(int **graph, int V){
	
      
    bool *visited = new bool[V];
    int *distance = new int[V];
    
    for(int i = 0; i<V; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    
    distance[0] = 0;
    
    for(int i = 0; i<V-1; i++){
        int minVertex = findMinVertex(visited,distance,V);
        visited[minVertex] = true;
        
        for(int j = 0; j<V; j++){
            if(!visited[j] && graph[minVertex][j]!=0  ){
                distance[j] = min(distance[j],distance[minVertex]+graph[minVertex][j]);
                
            }
        }
    }
    
    
    for(int i = 0; i<V; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  	int **graph = new int*[V];
  
    
    
    for(int i = 0; i<V; i++){
        graph[i] = new int[V];
        
        for(int j = 0; j<V; j++)
            graph[i][j] = 0;
    }
    
    for(int i =0; i<E; i++){
        int f,s,weight;
        cin>>f>>s>>weight;
        graph[f][s] = weight;
        graph[s][f] = weight;
    }
    
    dijstrak(graph,V);
    
   
    for(int i = 0; i<V; i++)
        delete [] graph[i];
    delete [] graph;

  return 0;
}
