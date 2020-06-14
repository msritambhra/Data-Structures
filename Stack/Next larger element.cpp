/*

Given an array A of size N having distinct elements,the task is 
to find the next greater element for each element of the array in order of their appearance in the array.
If no such element exists, output -1 

*/


#include <iostream>
#include<stack>

using namespace std;

int main() {
	int t;
	cin>>t;
	for(int T = 0; T<t; T++){
	    long n;
	    cin>>n;
	    long arr[n];
	    
	    for(long i = 0; i<n; i++)
	        cin>>arr[i];
	        
	    stack<long> s;
	    
	    long ans[n];
	    
	    for(long i = n-1; i>=0; i--){
	 
	         while (s.empty() == false && s.top() < arr[i]) {          
                s.pop(); 
            } 
            
            if(s.empty())
                ans[i] = -1;
            else
                ans[i] = s.top();
   
            s.push(arr[i]); 
        }
        
        
    
        for(long i = 0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        
        cout<<endl;
	            
	    
	}
	return 0;
}