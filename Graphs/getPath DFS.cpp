#include<iostream>
#include<vector>
using namespace std;

vector<int> *getPath_DFS(int**edges, int n ,int s, int e, bool *visited){
    
    if(s==e){
        vector<int>*output= new vector<int>();
        output->push_back(e);
        return output;
    }
    
    visited[s] = true;
    for(int i = 0; i<n; i++){
        if(i==s)
            continue;
        if(edges[s][i]==1 && visited[i]==false){
            vector<int>* smallOutput = getPath_DFS(edges,n,i,e,visited);
            
            if(smallOutput!=NULL){
                smallOutput->push_back(s);
                return smallOutput;}
        }
    }
    
    return NULL;
    
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
    
    vector<int> *output = getPath_DFS(edges,V,s,e,visited);
    if(output!=NULL){
    for(int i = 0 ; i<output->size();i++)
        cout<<output->at(i)<<" ";
    }
    
    
  return 0;
}


