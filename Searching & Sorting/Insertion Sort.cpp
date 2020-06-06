#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    
    int i,j,current;
   
    for(i=1;i<n;i++){
        
        current=arr[i];
        for(j=i-1;j>=0;j--){
            
            if(current<arr[j])
              arr[j+1]=arr[j];
            else break;
        }
       
     arr[j+1]=current;
   }

}



int main() {
	
	int size;
	cin>>size;
	int *input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	InsertionSort(input,size);

	for(int i=0;i<size;i++)
		cout << input[i]<<" ";
	
	return 0;
}
