/*

Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. 
Also, the rightmost element is always a leader. 

*/

#include <iostream>
using namespace std;
#include<climits>
#include<vector>

int main() {
	int test;
	cin>>test;
	for(int t = 0 ; t<test; t++){int n;
	cin>>n;
	vector<int> v;
	int arr[n];
	int max = INT_MIN;
	for(int i =0 ; i<n; i++){
	    cin>>arr[i];
	}
	
	for(int i =n-1; i>=0; i--){
	    if(arr[i]>=max){
	        max = arr[i];
	        v.push_back(max);
	    }
	    
	}
	
	for(int i =v.size()-1; i>=0; i--)
	    cout<<v[i]<<" ";
	
	cout<<endl;
}
	return 0;
}