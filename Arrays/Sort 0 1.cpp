
#include <iostream>
using namespace std;

void SortZeroesAndOne(int arr[], int n){
    
    int i = 0 , j= n-1;
    
    while(i<j){
        if(arr[i]>arr[j]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
            continue;
        }
        if(arr[i]==0)
            i++;
        if(arr[j]==1)
            j--;
    }

}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	SortZeroesAndOne(input,size);
		
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";	
	return 0;
}