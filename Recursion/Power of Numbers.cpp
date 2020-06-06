/*
Given a number N, let the reverse of the number be R.
The task is to print the output of the Expression pow(N,R), where pow function represents N raised to power R.
Note: As answers can be very large, print the result modulo 1000000007.

*/


#include<iostream>
using namespace std;
#define ul unsigned long long int

ul reverse(ul n){
    ul result =0;
    
    while(n>0){
        result = (result*10) + (n%10) ;
        n = n/10;
    }
    
    return result;
}

ul power(ul num,ul x){
    
    if(x==0)
        return 1;
    ul result=0;
    
    if(x%2==0){
        result = power(num, x/2);
        result = (result*result)%1000000007;
    }
    else{
        result = num;
        result = (result*(power(num,x-1)%1000000007))%1000000007;
    }
    
    return result;
}
int main() {
	
	int T;
	cin>>T;
	
	for(int t =0;t<T; t++){
	    
	    ul num;
    	cin>>num;
    	
    	ul rev = reverse(num);
    	// TO find: num^rev
    	//cout<<num<<rev;
    	cout<<power(num,rev)<<endl;
	    
	}
	
	
	return 0;
}