#include <iostream>
using namespace std;
#include<climits>


// 1. Brute Force Method
int knapsack(int* weights, int* values, int n, int maxWeight){

	if(maxWeight==0 || n==0){
        return 0;
    }
    
    if(weights[0]>maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight);
    else{
        int x = values[0] + knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
        int y = knapsack(weights+1,values+1,n-1,maxWeight);
    
        return max(x,y);
	}
}

//2. Memoization 

int knapsack_mem(int* weights, int* values, int n, int W, int **output){
    
    if(n<=0 || W<=0){
        output[n][W]=0;
    	return output[n][W];
    }
    
    if(output[n][W]!=INT_MIN){
        return output[n][W];
    }
    
    
    if(weights[n-1]>W)
        output[n][W] = knapsack_mem(weights,values,n-1,W,output);
    else{
        int x = values[n-1] + knapsack_mem(weights,values,n-1,W-weights[n-1],output);
        int y = knapsack_mem(weights,values,n-1,W,output);
    
        output[n][W] = max(x,y);
    }
    
    //output[n][W] = ans;
    
    return output[n][W];
}


int knapsack_mem(int* weights, int* values, int n, int maxWeight){

    int **output = new int*[n+1];
    int i, j;
    
    for( i = 0 ; i <=n; i++){
        output[i] = new int[maxWeight+1];
        for( j =0 ; j<=maxWeight; j++)
          {  output[i][j] = INT_MIN;}
    }
    //cout<<i<<" "<<j<<endl;
    return knapsack_mem(weights,values,n,maxWeight,output);
}


//3. Dynamic Programming ( Space Complexity: O(n*W) )

int knapsack_dp(int* weights, int* values, int n, int maxWeight){
    
    int **output = new int*[n+1];
    int i, j;
    for( i = 0 ; i <=n; i++)
        output[i] = new int[maxWeight+1];
    
    for(int i = 0; i<=n; i++){
        for(int j = 0 ; j<=maxWeight; j++){
            if(i==0 || j==0){
                output[i][j] = 0;
                continue;
            }
            
            if(weights[i-1]<= j)
                output[i][j] = max(values[i-1] + output[i-1][j-weights[i-1]],output[i-1][j]);
            else
                output[i][j] = output[i-1][j];
            
        }
    }
    
    return output[n][maxWeight];
}

int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;
}