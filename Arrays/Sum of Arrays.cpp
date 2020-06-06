#include<iostream>
using namespace std;

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){
    
    int i = size1-1;
    int j = size2-1;
    int carry = 0,k;
    if(size1>size2)
        k = size1;
    else
        k = size2;
    //cout<<i<<j<<k<<endl;
    while(i>=0 && j>=0){
        
        int sum = input1[i] + input2[j] + carry;
        //cout<<sum;
        if(sum<=9){
            output[k] = sum;
            carry = 0;
            k--;
        }
        else{
            output[k] = sum%10;
            carry = sum/10;
            k--;
            if((i==0)&&(j==0))
                      output[k]=carry;
        }
        
       	i--;
    	j--;
        
        
    }
    
	if(j<0){
        while(i>=0){
            int sum = input1[i] + carry;
            if(sum<=9){
                output[k] = sum;
                carry =0;
                k--;}
            else{
                output[k] = sum%10;
                carry = sum/10;
                k--;
                if(i==0)
                    output[k] = carry;   
            }
            i--;
        }
    }
    
    if(i<0){
        while(j>=0){
            int sum = input2[j] + carry;
            if(sum<=9){
                output[k] = sum;
                carry =0;
                k--;}
            else{
                output[k] = sum%10;
                carry = sum/10;
                k--;
                if(j==0)
                    output[k] = carry;   
            }
            j--;
        }
    }   

}



int main(){
	int size1,size2;
	cin>>size1;
	int * input1=new int[1+size1];
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

   	 cin>>size2;
	 int * input2=new int[1+size2];
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	int *output=new int[1+max(size1,size2)];
	int outsize = 1+max(size1,size2);
	sumOfTwoArrays(input1,size1,input2,size2,output);	
	
	for(int i=0;i<outsize;i++)
		cout<<output[i]<<" ";


}
