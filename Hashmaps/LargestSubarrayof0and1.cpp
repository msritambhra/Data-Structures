#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}


// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s

#include<unordered_map>

int maxLen(int arr[], int n) {
    
    if(n==0||n==1)
       return 0;
    for(int i =0; i<n; i++)
        if(arr[i]==0)
            arr[i] = -1;
            
    unordered_map<int,int> umap;
    int max=0,sum=0;
    
    for(int i =0; i<n; i++){
        sum+=arr[i];
        if(sum==0){
            if(i+1>max)
                max = i+1;
            umap[sum] = i;
            continue;
        }
        if(umap.count(sum)>0){
            if(i-umap[sum]>max)
                max = i-umap[sum];
            if(max==n)
                return max;
        }
        else
            umap[sum]=i;
    }
    
    return max;

}
