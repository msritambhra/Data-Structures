#include<iostream> 
#include<algorithm> 
using namespace std; 

/*

// A thief wants to loot houses. He knows the amount of money in each house. 
// He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

// 1. Brute Force 
int getMaxMoney(int arr[], int n){

	if(n<=0)
        return 0;
    
    int x = arr[n-1] + getMaxMoney(arr,n-2);
    int y = arr[n-2] + getMaxMoney(arr,n-3);
    
    int res =  max(x,y);
    
    return res;
    

}

// 2. Memoization
int getMaxMoney_mem(int arr[], int n, int *output){
    
    if(n<=0)
        return 0;
    if(n==1)
        return arr[n-1];
    
    if(output[n-1]!=-1)
        return output[n-1];
    
    int x = arr[n-1] + getMaxMoney_mem(arr,n-2,output);
    int y = arr[n-2] + getMaxMoney_mem(arr,n-3,output);
    
    output[n-1] =  max(x,y);
    
    return output[n-1];
    
}


int getMaxMoney(int arr[], int n){
    
    if(n==0)
        return 0;
    
    int *output = new int[n];
    for (int i =0 ; i<n; i++)
        output[i] = -1;
    
    getMaxMoney_mem(arr,n,output);
}

*/

// 3. Dynamic Programming
int getMaxMoney(int arr[], int n){
    
    if(n<=0)
        return 0;
    if(n==1)
        return arr[n-1];
    
    int * output = new int[n];
    
    output[0] = arr[0];
    output[1] = max(arr[1],output[0]);
    
    for(int i = 2; i<n; i++){
        output[i] = max(arr[i]+output[i-2],output[i-1]);
    }
    
    return output[n-1];
}

int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}
