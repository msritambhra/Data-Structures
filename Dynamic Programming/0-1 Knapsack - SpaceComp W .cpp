#include <iostream>
using namespace std;
#include<climits>

// Space Complexity : O(W) (Optimized from O(n*W))
int knapsack(int* weights, int* values, int n, int maxWeight){
    
    if(n==0 || maxWeight==0)
        return 0;
    
    int ** output = new int*[2];
    for(int i = 0; i<2;i++){
        output[i] = new int[maxWeight+1];
        for(int j = 0; j<=maxWeight; j++)
            output[i][j] = 0;
    }
    
    int i = 0;
    while(i<n){
        int j = 0;
        
        if(i%2==0){
            while(j<=maxWeight){
                
                if(weights[i]<=j)
                    output[0][j] = max(values[i] + output[1][j-weights[i]], output[1][j]);
                else
                    output[0][j] = output[1][j]; 
                j++;
            }
            
        }
        
        else{
            
             while(j<=maxWeight){
                
                if(weights[i]<=j)
                    output[1][j] = max(values[i] + output[0][j-weights[i]], output[0][j]);
                else
                    output[1][j] = output[0][j]; 
                j++;
            }
            
        }
        
        i++;
    }
    
    return (n%2==0)?output[1][maxWeight]:output[0][maxWeight];
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