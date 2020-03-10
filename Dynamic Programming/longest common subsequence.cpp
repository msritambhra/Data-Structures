#include <iostream>
using namespace std;

// 1. Brute Force
int lcs(string s, string t) {

	//Base Case
	if(s.size()==0 || t.size()==0)
		return 0;

	if(s[0] == t[0])
		return 1 + lcs(s.substr(1),t.substr(1));

	else {
		
		int x = lcs(s.substr(1),t.substr(1));
		int y = lcs(s.substr(1),t);
		int z = lcs(s,t.substr(1));
		
		return max(x,max(y,z));

	}
}

//2. Memoization

int lcs_mem(string s, string t, int **output){
	
	int m = s.size();
	int n = t.size();
	
	if(m==0 || n==0)
		return 0;

	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;

	// Recursive calls
	if(s[0] == t[0]) {
		ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
	}
	else {
		int a = lcs_mem(s.substr(1), t, output);
		int b = lcs_mem(s, t.substr(1), output);
		int c = lcs_mem(s.substr(1), t.substr(1), output);
		ans = max(a, max(b, c));
	}

	// Save your calculation
	output[m][n] = ans;

	// Return ans
	return ans;


}

int lcs_mem(string s, string t){
	
	int m = s.size();
	int n = t.size();

	int ** output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}

	return lcs_mem(s, t, output);
	
}


// 3. Dynamic Programming

int lcs_DP(string s, string t){
    
    int m = s.size();
    int n = t.size();
    
    int **output = new int*[m+1];
    for(int i = 0;i<m; i++)
        output[i] = new int[n+1];
    
    output[0][0] =0;
    
    //Filling first column with 0
    for(int i =1; i <=m;i++)
        output[i][0] = 0;
    
    //Filling first row as 0
    for(int j = 1; j <=n; j++)
        output[0][j] = 0;
    

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[i-1]==t[j-1])
                output[i][j] = 1 + output[i-1][j-1];
            
            else
                output[i][j] = max(output[i-1][j],max(output[i][j-1],output[i-1][j-1]));
            
        }
    }
    
    int ans = output[m][n];
    delete output;
    
    return ans;
}



int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;
	
  // cout << lcs(s1,s2) << endl; // Brute force method 
  // cout << lcs_mem(s1,s2) << endl; // Memoization Method
  cout << lcs_DP(s1,s2) << endl; // Dynamic Programming Method 
 
}







