
#include <iostream>
using namespace std;


int FindSecondLargest(int arr[], int n){
    int i ,max = INT_MIN,second_max = INT_MIN;
    for(i = 0; i<n;i++){
        if(arr[i]>max){
            second_max = max;
            max = arr[i];
            
        }
        else if(arr[i]>second_max && arr[i]!=max){
            second_max = arr[i];
        }
        else continue;
        
    }
    return second_max;
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSecondLargest(input,size);
	
	return 0;

}