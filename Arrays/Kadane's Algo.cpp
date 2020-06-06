#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t=0; t<T; t++){
	    int n ;
	    cin>>n;
	    int *arr = new int[n];
	    cin>>arr[0];
	    int maxsum = arr[0];
	    int currentsum =arr[0];
	    for(int i = 1; i<n; i++){
	        cin>>arr[i];
	        
	        if(currentsum+arr[i]>arr[i])
	           currentsum=currentsum+arr[i];
	       else
	            currentsum=arr[i];
	       if (maxsum<currentsum)
	        maxsum = currentsum;
	   }
	  cout<<maxsum<<endl;
	   
	}
	return 0;
}