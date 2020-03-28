#include<iostream>
using namespace std;

int main(){
     int n;
  cin>>n;
  int i,arr[1000000];
  for(i=0;i<n;i++)
  {  cin>>arr[i];}
   int sum=0;
  for(i=0;i<n;i++)
  { 
  sum+=arr[i];}
  cout<<sum;
    
}