/*

Gary has a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. 
The key of this game is to find a cycle that contain dots of same colour. 

Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. 
Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

*/



#include<bits/stdc++.h>
using namespace std;
#define MAXN 51


int p[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int found = 0;

void search(char board[][MAXN],int n, int m, int i, int j,int from_i,int from_j,bool **visited,char c){
    
    if(i<0 || i>=n || j<0 || j>=m)
        return;
        
    if(board[i][j]!=c)
        return;
    if(visited[i][j]){
        found = 1;
        return;
    }
    visited[i][j] = true;
    for(int k = 0 ; k<4; k++){
        
        int new_i = i + p[k][0];
        int new_j = j + p[k][1];
        
        if(new_i== from_i && new_j==from_j)
            continue;
        search(board,n,m,new_i,new_j,i,j,visited,c);
            
    }

}


int solve(char board[][MAXN],int n, int m)
{
    
    bool **visited = new bool*[n];
    for(int i = 0 ; i<n; i++){
        visited[i] = new bool[m];
        for(int j = 0; j<m; j++)
            visited[i][j] = false;
    }
    

    for(int i = 0 ; i<n; i++){
        for(int j = 0 ;j<m; j++){
            if(visited[i][j]==false){
            
            search(board,n,m,i,j,-1,-1,visited,board[i][j]);
            
            }
        }
    }
    
    
    return found;
     
}


int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}