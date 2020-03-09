#include<climits>
#include<iostream>
using namespace std;

/*

Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).  


// 1.  Brute Force
int countStepsTo1(int n){

    if(n==1)
        return 0;
    
    int x = INT_MAX,y = INT_MAX,z = INT_MAX;
    
    x = countStepsTo1(n-1);
    if(n%2==0)
         y =   countStepsTo1(n/2);
    if(n%3==0)
         z =  countStepsTo1(n/3);
    
    
    
    return 1 + min(x,min(y,z));
}


// 2. Memoization
int countStepsTo1(int n,int *ans){
    
    
    if(n==1)
        return 0;
    
    
    //Check if output already exists
    if(ans[n-1]!=-1){
        return ans[n-1];
    }
    
    
    //Calculate Output if not already stored
    int x = INT_MAX;
    int y= INT_MAX;
    int z=INT_MAX;
    
    x = countStepsTo1(n-1,ans);
    
    if(n%2==0)
         y =   countStepsTo1(n/2,ans);
    
    if(n%3==0)
         z =  countStepsTo1(n/3,ans);
    
    //Store the calculated result 
    ans[n-1] = min(x,min(y,z))+1;
    
    //Return the answer calculated
    return ans[n-1];
}

int countStepsTo1(int n){
    
    int *ans = new int[n];
    for(int i =0;i<n; i++)
        ans[i] = -1;
         
    return countStepsTo1(n,ans);
}



*/


// 3. Dynamic Programming

int countStepsTo1(int n){
    
    int *ans = new int[n];
    
    for(int i = 0; i<n ;i++){
        ans[i] = 0;
    }
  
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    
    for(int i = 4; i<n; i++){
        
        int c1,c2,c3;
        c1 = c2 = c3 = n;
        
        c1 = ans[i-1];
        
        if(i%2==0){
            c2 = ans[i/2];
        }
        
        if(i%3==0){
            c3 = ans[i/3];
        }
        
        ans[i] = 1 + min(c1,min(c2,c3));
        
    }
    
    int result = ans[n];
    delete ans;
    
    return result;
}


//Main Function

int main(){

  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;

}



