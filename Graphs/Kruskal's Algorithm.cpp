#include <iostream>
#include<algorithm>
using namespace std;

class Edge{
    public:
    	int source;
    	int dest;
    	int weight;
};

bool comapre(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int find_parent(int vertex, int *parent){
    
    if(parent[vertex] == vertex)
        return vertex;
    
    return find_parent(parent[vertex],parent);
}

void krushkal(Edge *input, int V, int E){
    
    sort(input,input+E,comapre);
    
    Edge * output = new Edge[V-1];
    
    int * parent = new int[V];
    
    for(int i =0; i<V; i++){
        parent[i] = i;
    }
    
    int count = 0;
    int i=0;
    while(count != V-1){
        
        int sourceParent = find_parent(input[i].source,parent);
        int destParent = find_parent(input[i].dest,parent);
        
        if(sourceParent!=destParent){
            output[count] = input[i];
            parent[sourceParent] = destParent;
            count++;
        }
        
        i++;
        
    }
    
    for(i =0; i<V-1; i++){
        cout<<min(output[i].source,output[i].dest)<<" "
            <<max(output[i].source,output[i].dest)<<" "
            <<output[i].weight<<endl;
    }
    
    return;
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  Edge * input = new Edge[E];

    for(int  i = 0; i < E; i++ ){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
     }
    
    krushkal(input,V,E);
  return 0;
}
