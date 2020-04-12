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
	
    if(n==0||n==1)
        return n;
    int * output = new int[n];
    
    int maxLength = 1;
	output[0] = 1;
    
    for(int i = 0 ; i < n ; i++){
        output[i] = 1;
        
        for(int j = i-1; j>=0; j--){
            if(arr[j]>arr[i])
                continue;
            int possibleAns = 1 + output[j];
            if(possibleAns > output[i])
                output[i] = possibleAns;
        
        }
        
        if(output[i]>maxLength)
            maxLength = output[i];
    }
    
    delete [] output;
    
    return maxLength;
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

