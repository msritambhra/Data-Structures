#include <iostream>
using namespace std;

int main() {
    
	int test;
	cin>>test;
	for(int t = 0; t<test; t++){
	    
	    int n;
    	cin>>n;
    	int arr[n];
    	
    	for(int i =0 ;i<n;i++){
    	    cin>>arr[i];
    	}
    	
    	for(int i = n-1; i>=0; i--)
    	    cout<<arr[i]<<" ";
    	cout<<endl;
	    
	}
	    
	return 0;
}