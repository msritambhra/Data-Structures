
#include<iostream>
using namespace std;

void swapAlternate(int arr[],int size){
 
  int i = 0,j=1;
    int temp;
    for(i=0;i<size-1;i+=2){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j+=2;
    }


}




int main(){
  int size;  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  } 
  swapAlternate(arr, size);
 for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  delete arr;
}
