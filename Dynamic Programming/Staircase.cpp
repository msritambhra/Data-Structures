/*

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return all possible number of ways.

*/


#include<iostream>
using namespace std;


long staircase(int n){
    
    
    long *ans = new long[n+1];
    
    for(int i =0 ;i<n+1;i++)
        ans[i] = 0 ;
    
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    
    for(int i =3 ; i<n+1; i++){
        
        long x = ans[i-1];
        long y = ans[i-2];
        long z = ans[i-3];
        ans[i] = x+y+z;
        
        
    }
    
    long result = ans[n];
    
    delete ans;
    
    return result;
    
    
}


int main(){

  int n; 
  cin >> n ;
  cout << staircase(n) << endl;

}


