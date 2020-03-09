

#include<cmath>
#include<iostream>
using namespace std;

/*

Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.


//1. Brute Force
int balancedBTs(int h) {
  
    
    if(h==1||h==0)
        return 1;
    
    int mod = (int) (pow(10,9))+7;
        
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
    
    int ans = (temp1+temp2)%mod;
    
    return ans;
}

// 2. Memoization
int binaryTreesOfHeightH(int h, int *ans) {
    
     
    if(h==1||h==0)
        return 1;
    if(ans[h]!=-1)
        return ans[h];
    int mod = (int) (pow(10,9))+7;
        
    int x = binaryTreesOfHeightH(h-1,ans);
    int y = binaryTreesOfHeightH(h-2,ans);
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
    
    ans[h] = (temp1+temp2)%mod;
    
    return ans[h];
}

int binaryTreesOfHeightH(int h){
    
    int *ans = new int[h+1];
    for(int i =0;i<h+1;i++){
        ans[i] = -1;
    }
    
    return binaryTreesOfHeightH(h,ans);
}*/

//3. Dynamic Programming 
int binaryTreesOfHeightH(int h){
    
    if(h<=1)
        return 1;
    
    int *ans = new int[h+1];
    
    ans[0] = 1;
    ans[1] = 1;
    
    for(int i =2;i<=h;i++){
        
        int x = ans[i-1];
        int y = ans[i-2];
        
        int mod = (int) pow(10,9) + 7;
        int temp1 = (int)(((long)(x)*x)%mod);
        int temp2 = (int)((2*(long)(x)*y)%mod);
        ans[i] = (temp1+temp2)%mod;
    }
    
    int res = ans[h];
    delete ans;
    
    return res;
}


int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}
