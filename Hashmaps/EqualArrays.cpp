// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;
#define ll long long 

bool check(vector<ll> , vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        
        cout << check(arr,brr,n) << "\n";
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// arr : 1st given array
// brr : 2nd given array
// n : size of both the arrays
#include<unordered_map>
bool check(vector<ll> arr, vector<ll> brr, int n) {
    
    unordered_map<long long int,int> umap;
    
    for(int i = 0; i<n; i++){
        if(umap.find(arr[i])!=umap.end())
            umap[arr[i]] += 1;
        else
            umap[arr[i]] = 1;
        
    }
    
    for(int i = 0; i<n ;i++){
        if(umap.find(brr[i])!=umap.end() && umap[brr[i]]!=0)
            umap[brr[i]]-=1;
        else
            return false;
    }
    
    return true;
    
    
}