#include <iostream>
#include <climits>
using namespace std;

/*
// 1. Brute Force
int minCostPath(int ** input,int m, int n ,int i, int  j){
    
    if(i==m-1&&j==n-1){
        return input[i][j];
    }
    
    
    if(i>=m || j>=n)
        return INT_MAX;
    
    int x = minCostPath(input,m,n,i,j+1);
    int y = minCostPath(input,m,n,i+1,j);
    int z = minCostPath(input,m,n,i+1,j+1);
    
    return input[i][j] + min(x,min(y,z));
}

int minCostPath(int **input, int m, int n) {
    
    return minCostPath(input,m,n,0,0);
        
}  

 

//2. Memoization

int minCostPath(int ** input,int m, int n ,int i, int  j, int **output){
    
    if(i==m-1&&j==n-1)
        return input[i][j];
    
    if(i>=m || j>=n)
        return INT_MAX;
   
    if(output[i][j]!=-1)
        return output[i][j];
    
    
    int x = minCostPath(input,m,n,i,j+1,output);
    int y = minCostPath(input,m,n,i+1,j,output);
    int z = minCostPath(input,m,n,i+1,j+1,output);
    
    int a =  input[i][j] + min(x,min(y,z));
    
    output[i][j] = a;
    
    return a;
}


int minCostPath(int **input, int m, int n) {
    
    int **output;
    output = new int*[m];
    for(int i = 0; i<m; i++)
        output[i] = new int[n];
    for(int i = 0 ; i<m; i++){
        for(int j = 0; j<n; j++)
            output[i][j] = -1;
    }
    return minCostPath(input,m,n,0,0,output);
        
} 

*/

//3. Dynamic Programming

int minCostPath(int **input, int m, int n){
    
    int** output =  new int*[m];
    
    for(int i =0 ; i<m; i++){
        output[i] = new int[n];
    }
    
    //Fill the destination index of matrix (m-1,n-1)
    output[m-1][n-1] = input[m-1][n-1];
    
    //Fill the last row (right to left)
    for(int j = n-2; j>=0; j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }
    
    //Fill the last column (bottom to top)
    for(int i = m-2; i>=0; i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }
    
    //Fill the remaining indexes
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            int m = min(output[i+1][j],min(output[i][j+1],output[i+1][j+1]));
            output[i][j] = m + input[i][j];
        }
    }
    
    int result  = output[0][0];
    delete output;
    
    return result;
}


int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}

