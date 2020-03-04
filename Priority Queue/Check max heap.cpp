#include <iostream>

using namespace std;



bool checkMaxHeap(int arr[], int n){
    
   if(n==0||n==1)
        return true;
    for (int i = 0 ; i < n ; i++){
        
        if(2*i+1<n && arr[i]<arr[2*i+1])
            return false;
        if(2*i+2<n && arr[i]<arr[2*i+2])
            return false;
    }
    
    return true;
}


int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}
