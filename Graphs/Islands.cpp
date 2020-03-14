/*

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.

Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N

Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M

Output Return Format :
The count the number of connected groups of islands

*/


#include<iostream>
#include<vector>
using namespace std;


void DFS(int **edges, int n , int s, bool * visited){
    
    visited[s] = true;
    
    for(int i = 0 ; i<n; i++){
        if(i==s)
            continue;
        if(edges[i][s]==1 && visited[i]==false)
            DFS(edges,n,i,visited);
    }
}


int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **edges = new int*[n];
    for(int i = 0 ; i<n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0 ;
    }
    
    for(int i = 0 ; i<m; i++){
        //cout<<u[i]<<" "<<v[i];
        edges[u[i]-1][v[i]-1] = 1;
        edges[v[i]-1][u[i]-1] = 1;
    }
    
    bool *visited = new bool[n];
    
    for(int i = 0 ; i < n; i++)
        visited[i] = false;
    
    int count = 0 ;
    for(int i = 0 ; i<n; i++){
        //cout<<i<<endl;
        if(visited[i]==false){
            DFS(edges,n,i,visited);
            count++;}
    }
    return count;
}


int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}