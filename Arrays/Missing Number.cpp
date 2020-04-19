#include <iostream>
#include<unordered_map>
using namespace std;


//Optimized Solution
int main() {
	
	int n;
	cin>>n;
	for(int test = 0 ; test<n; test++){
	    int size;
	    cin>>size;
	    if(size==1){
	        cout<<1<<endl;
	        break;
	    }
	    int arr[size-1];
	    int sum = 0;
	    for(int i = 0 ; i<size-1; i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    
	    int real_sum = (size*(size+1))/2;
	    cout<<real_sum-sum<<endl;

	}
	return 0;
}

//Using Hashmaps

/*
int main() {
	int n;
	cin>>n;
	for(int test = 0 ; test<n; test++){
	    int size;
	    cin>>size;
	    if(size==1){
	        cout<<1<<endl;
	        break;
	    }
	    int arr[size-1];
	    unordered_map<int,int> umap;
	    for(int i = 0 ; i<size-1; i++){
	        cin>>arr[i];
	        if(umap.count(arr[i])==0)
	            umap[arr[i]] = 1;
	    }
	    
	    for(int i =1 ;i<=size; i++){
	        if(umap.count(i)==0){
	           cout<<i<<endl;
	           break;
	       }
	            
	    }
	   
	}
	return 0;
}
*/

