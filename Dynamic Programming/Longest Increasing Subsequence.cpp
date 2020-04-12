#include<algorithm>
#include<climits>
#include <iostream>
using namespace std;

/*int lis(int arr[], int n , int prev , int curr){
    
    if(curr>=n)
        return 0;
    
    int x= 0, y;
    
    if(arr[curr]>prev)
        x = 1 + lis(arr,n,arr[curr],curr+1);
    
    y = lis(arr,n,prev,curr+1);
    
    return max(x,y);
}

int lis(int arr[], int n) {
			
	return lis(arr,n,INT_MIN,0);
    
}
*/

//2. Dynamic Programming 


int lis(int arr[], int n) {
	
    
    int * output = new int[n];
    

	output[0] = 1;
    int ans = 1;
    for(int i = 1 ; i < n ; i++){
        
        int max = 1;
        
        for(int j = i-1; j>=0; j--){
            
            if(arr[j]<arr[i]){
                int op = output[j] + 1;
                if(op>max)
                    max = op;   
            }
            
        }   
        
        output[i] = max;
        if(max > ans)
            ans = max;
    }
    
    
    delete [] output;
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n);
}

