/*

Arrange Numbers in Array

Given a number n, 
put all elements from 1 to n in an array in order - 1,3,.......4,2.

*/
#include<iostream>
using namespace std;

void arrange(int arr[],int n){
  
  
  int i,v=1;
  for(i=0;i<n/2;i++)
  {
      arr[i]=v;
      v+=2;
  }
  v=n;
  arr[n/2]=v;
  if(n%2==0){ v-=2;
    arr[(n/2)+1]=v;}
 else
 {
    v-=1;
    arr[(n/2)+1]=v;
 }
  for(i=((n/2)+2);i<n;i++)
  {
      v-=2;
     arr[i]=v;
       
  }
   

}



int main(){
  int n;  
  cin >> n;
  
  int* arr = new int[n];
  arrange(arr,n);
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  delete arr;
}

