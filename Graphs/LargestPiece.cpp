/*


Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. 
Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

*/


#include<iostream>
#include<vector>
using namespace std;

#define NMAX 55

char cake[NMAX][NMAX];

int p[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};


int maxLen(char cake[NMAX][NMAX], int n, int i, int j, bool **visited,int max){
    
    if(visited[i][j]==true)
        return 0;
    
    visited[i][j] = true;
    int count = 1;
    for(int k = 0; k<4; k++){
        int new_i = i + p[k][0];
        int new_j = j + p[k][1];
        bool v = new_i>=0 && new_i<n && new_j>=0 && new_j<n;
        if(v && visited[new_i][new_j]==false && cake[new_i][new_j]=='1'){
            
            count += maxLen(cake,n, new_i, new_j,visited,max);
            
        }
    }
    
    return count;
}


int solve(int n,char cake[NMAX][NMAX])
{
	bool **visited = new bool*[n];
    for(int i = 0; i<n; i++){
        visited[i] = new bool[n];
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
    int ans,max;
    ans = max = 0;
    for(int i =0; i<n; i++){
        for(int j = 0 ; j<n; j++){
            if(!visited[i][j] && cake[i][j]=='1'){
                ans = maxLen(cake,n,i,j,visited,0);
                if(ans>max)
                    max = ans;
            }
        }
    }
    
    return max;
    
}



int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}