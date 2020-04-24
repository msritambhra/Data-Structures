/*

Given an array A of N elements. Find the majority element in the array.
A majority element in an array A of size N is an element that appears more than N/2 times in the array.

*/

#include <iostream>
using namespace std;
#include<unordered_map>

int main() {
    int test;
    cin>>test;
    for(int t = 0; t<test; t++){
    int n;
    unordered_map<int,int> umap;
    cin>>n;
	int arr[n];
	int max = 0,maxn;
	for(int i = 0; i<n; i++){
	    cin>>arr[i];
	    if(umap.count(arr[i])==0){
	        umap[arr[i]] = 1;
	        if(umap[arr[i]]>max){
	            max = umap[arr[i]];
	            maxn = arr[i];
	        }
	    }
	    else{
	        umap[arr[i]] +=1;
	        if(umap[arr[i]]>max){
	            max = umap[arr[i]];
	            maxn = arr[i];
	        }
	        
	    }
	    
	}
	
	if(max>n/2)
	    cout<<maxn<<endl;
	else
	    cout<<-1<<endl;
	}
	
	return 0;
}