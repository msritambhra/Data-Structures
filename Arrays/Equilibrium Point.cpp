/*

Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. 
Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

*/

#include <iostream>
using namespace std;

int main() {
	
    int test;
    cin>>test;
    for(int t = 0; t<test; t++){
        int n;
        cin>>n;
        int arr[n];
        int sum = 0 ;
        for(int i = 0 ; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        
        int leftSum = 0;
        int eq_point = -1;

        for(int i = 0 ; i<n; i++){
            sum -= arr[i];
            
            if(leftSum == sum){
                eq_point = i+1;
                break;
            }
            
            leftSum += arr[i];
        }
        
        cout<<eq_point<<endl;
        
    }
    
    return 0;
}