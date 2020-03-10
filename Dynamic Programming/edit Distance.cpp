#include <iostream>
#include <vector>
using namespace std;

/*

Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
Edit Distance of two strings is minimum number of steps required to make one string equal to other. 

In order to do so you can perform following three operations only :

1. Delete a character
2. Replace a character with another one
3. Insert a character


*/

// 1. Brute Force Method 
int editDistance(string s1, string s2){

    if(s1.size()==0 || s2.size()==0)
        return max(s1.size(),s2.size());
    
    if(s1[0]==s2[0])
        return editDistance(s1.substr(1),s2.substr(1));
    
    
    int x = editDistance(s1.substr(1),s2); // Insrtting a char
    int y = editDistance(s1,s2.substr(1)); // Deleteing a char
    int z = editDistance(s1.substr(1),s2.substr(1)); // Updating or Replacing first char
    
    return 1 + min(x,min(y,z));
    
    
}


// 2. Memoization


int editDistance_mem(string s1, string s2, int **output){
    
    int m = s1.size();
    int n = s2.size();
    if(m==0 || n==0)
        return max(m,n);
    
    if(output[m][n]!=-1)
        return output[m][n];
    
    int ans;
    
    if(s1[0]==s2[0])
        ans = editDistance_mem(s1.substr(1),s2.substr(1),output);
    
    else{
    int x = editDistance_mem(s1.substr(1),s2,output) + 1; // Inserting a char
    int y = editDistance_mem(s1,s2.substr(1),output) + 1; // Deleting a char
    int z = editDistance_mem(s1.substr(1),s2.substr(1),output) + 1; // Updating or Replacing first char
    //cout<<m<<" "<<n<<endl;
    ans =  min(x,min(y,z));
    }
    output[m][n] = ans;
    
    return ans;
}

int editDistance_mem(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int **output = new int*[m+1];
    for(int i = 0; i <=m; i++){
        output[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    
    return editDistance_mem(s1,s2,output);
}

//3. Dynamic Programming

int editDistance_DP(string s1, string s2){
    
    int m = s1.size();
    int n = s2.size();
    
    int ** output = new int*[m+1];
    for(int i = 0 ; i<=m; i++){
        output[i] = new int[n+1];
    }
    
    //Filling first column
    for(int i = 0; i<=m; i++){
        output[i][0] = i;
    }
    
    //Filling first row
    for(int j = 1; j<=n; j++){
        output[0][j] = j;
    }
    
    for(int i = 1;i<=m;i++){
        for(int j= 1; j<=n; j++){
            if(s1[i-1]==s2[j-1])
                output[i][j] = output[i-1][j-1];
            else
                output[i][j] = min(output[i-1][j-1],min(output[i][j-1],output[i-1][j])) + 1;
        }
    }
    
    int res = output[m][n];
    
    delete output;
    
    return res;
}


// Driver Method

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  // cout << editDistance(s1,s2) << endl; // Brute force method 
  // cout << editDistance_mem(s1,s2) << endl; // Memoization Method
  cout << editDistance_DP(s1,s2) << endl; // Dynamic Programming Method 

}

