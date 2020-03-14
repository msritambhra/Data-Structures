#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


void DFS(int**edges,int n , int sv, bool *visited,vector<int>*output){
    
    output->push_back(sv);
    visited[sv] = true;
    
    for(int i = 0;i<n;i++){
        if(i==sv)
            continue;
        if(edges[i][sv]==1 && visited[i]==false){
            DFS(edges,n,i,visited,output);
            
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
    
    vector<int>*output = new vector<int>();
    
    for(int i = 0 ; i <V; i++){
        
        if(visited[i]==false){
            
            DFS(edges,V,i,visited,output);
            
            sort(output->begin(),output->end());
            
            for(int j = 0;j<output->size();j++)
                cout<<output->at(j)<<" ";

            output->clear();
            cout<<endl;
        }
    
    }
    
    delete [] visited;
    
    for(int i =0; i<V; i++)
        delete [] edges[i];
    
    delete [] edges;
    
  return 0;
}
