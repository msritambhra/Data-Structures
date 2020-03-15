/*

Given a NxM matrix containing Uppercase English Alphabets only. 
Your task is to tell if there is a path in the given matrix which makes the sentence “CORONAVIRUS” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.

Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on

*/



#include<bits/stdc++.h>
using namespace std;
#define MAXN 102


int p[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool validate_point(int i, int j, int N ,int M){
    return (i>=0 && i<N && j>=0 && j<M);
}
bool search(char Graph[][MAXN],int N,int M,int i, int j,bool **visited, string s){
    
    if(s.size()==0)
        return true;
    
    visited[i][j] =true;
    bool ans = false;
    int new_i, new_j;
    for(int k = 0 ; k<8; k++){
        
        new_i = i + p[k][0];
        new_j = j + p[k][1];
       
        if(validate_point(new_i,new_j,N,M)){
            
            if(visited[new_i][new_j]==false && Graph[new_i][new_j]==s[0] ){
            
                ans= search(Graph, N, M, new_i, new_j, visited,s.substr(1));
                if(ans)
                    return true;
            }
        }
        
    }
    
    visited[i][j] = false;
    
    return ans;
    
}


int solve(char Graph[][MAXN],int N, int M)
{
	bool **visited = new bool*[N];
    for(int i = 0 ; i <N;i++){
        visited[i] = new bool[M];
        for(int j = 0 ; j<M; j++)
            visited[i][j] = false;
    }
    
    int found = 0;
    for(int i = 0 ; i<N;i++){
        
        for(int j = 0 ; j<M; j++){
            string s = "CORONAVIRUS";
            found = 0;
            if(visited[i][j]==false && Graph[i][j]==s[0]){
                
                
                found = search(Graph, N, M,i,j,visited, s.substr(1));
                visited[i][j] = true;
                if(found)
                    break;
                
            }
        }
        if(found)
            break;
    }
    
    return found;
}



int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}

