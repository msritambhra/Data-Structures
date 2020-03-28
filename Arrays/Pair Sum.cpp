#include <iostream>
using namespace std;

void pairSum(int input[], int size, int x) {
   

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if( input[i]+input[j]==x)
                cout<<min(input[i],input[j])<<" "<<max(input[i],input[j])<<endl;            
        }
    }
    
}



int main() {

	int size;
	int x;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;
	pairSum(input,size,x);
		
	return 0;
}
