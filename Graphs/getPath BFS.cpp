#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> * getPath_BFS(int **edges, int V, int s,int e, bool *visited){
    
    vector<int> *output = new vector<int>();
    
     if(s==e){  
         output->push_back(e);
         return output;
     }
    
    unordered_map<int,int> umap;
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()){
        
        int v = q.front();
        q.pop();
        
        for(int i = 0 ; i<V; i++){
            if(i==s)
                continue;
            
            if(edges[i][v]==1 && visited[i]==false){
                visited[i]=true;
                q.push(i);
                umap[i] = v;
                
                // If end vertex ha been reached
                if(i==e){
                    int x  = i;
                    output->push_back(i);
                    
                    // Propagate in backward direction to get the path from end 
                    // vertex to start vertex
                    while(x!=s){
                        
                        x = umap[x];
                        output->push_back(x);
                        
                    }
                    
                    return output;}
            }
        }
                
    }// when queue is empty
    

    return NULL; // if no path to end vertex is detected
    
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

    int **edges = new int*[V];
    
    for(int i = 0 ; i<V; i++){
        edges[i] = new int[V];
        
        for(int j= 0 ;j<V; j++){
            edges[i][j] = 0;
        }
    }
    
    
    for(int i = 0; i<E; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    bool *visited = new bool[V];
    
    for(int i = 0; i<V; i++)
        visited[i] = false;
    
    int s,e;
    
    cin>>s>>e;
    
    vector<int>* output = getPath_BFS(edges,V,s,e,visited);
    if(output!=NULL){
        for(int i = 0 ; i<output->size();i++)
            cout<<output->at(i)<<" ";
        }
    
}
