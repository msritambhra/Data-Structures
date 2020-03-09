/*

Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
Output will be 1, as 1 is the minimum count of numbers required.

*/

#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


// 1. Brute Force
int minCount(int n){
    
    if((sqrt(n)-floor(sqrt(n))) ==0 )
        return 1;
    if(n<=3)
        return n;
    
    
    int count = n;
     
    for(int i = 1; i <=n; i++){
        
        int x = i*i;
        if(x>n)
            break;
        else
            count = min(count,1 + minCount(n-x));
    }
    
    return count;
}

// 2. Memoization
int minCount(int n, int * ans){
    
    if((sqrt(n)-floor(sqrt(n))) ==0 )
        return 1;
    if(n<=3)
        return n;
    
    if(ans[n]!=-1)
        return ans[n];
    int count = n;
    for(int i = 1; i <=n; i++){
        
        int x = i*i;
        if(x>n)
            break;
        else
            count = min(count,1 + minCount(n-x,ans));
    }
    
    ans[n] = count;
    
    return ans[n];
    
}

int minCount(int n){
    
    int *ans = new int[n+1];
    for(int i = 0; i<n+1;i++)
        ans[i] =  -1;
    return minCount(n,ans);
}

// 3. Dynamic Programming

int minCount(int n){
    if((sqrt(n)-floor(sqrt(n))) ==0 )
        return 1;
    
    int *ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    
    int count = n;
    for(int i =4 ; i<=n; i++){
        if((sqrt(i)-floor(sqrt(i))) ==0 ){
            ans[i] = 1;
        continue;}
        
        ans[i] = i;
        
        for(int j = 1; j<=sqrt(i);j++){
            int x = j*j;
            if(x>i)
                break;
            ans[i] = min(ans[i],ans[i-x]+1);
        }
        
        
        
    }
    
    return ans[n];
    
    
    
}


int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}
