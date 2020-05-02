#include <iostream>
using namespace std;


int main() {
	
    int test;
    cin>>test;
    
    for(int t =0; t<test; t++){
    	    int n;
        	cin>>n;
        	
        	int arr[n];
        	for(int i =0; i<n; i++)
        	    cin>>arr[i];
        	int low,mid,high;
        	
        	low = mid = 0;
        	high = n-1;
        	
        	while(mid<=high){
        	    
        	    int val = arr[mid];
        	    
        	    if(val==0){
        	        int temp = arr[low];
        	        arr[low] = arr[mid];
        	        arr[mid] = temp;
        	        low++;
        	        mid++;
        	    }
        	    
        	    else if(val==1)
        	        mid++;
        	    
        	    else{
        	        int temp = arr[mid];
        	        arr[mid] = arr[high];
        	        arr[high] = temp;
        	        high--;
        	    }
        	}
        	
        	for(int i =0; i<n; i++)
        	    cout<<arr[i]<<" ";
        	cout<<endl;
    	    
    }
	return 0;
}