#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	
    unordered_map<int,int> umap;
    
    for(int i =0; i<n; i++)
            umap[arr[i]]+=1;
    
    int curr;
    vector<int> result,current;
    
    if(n==0)
        return result;
    for(int i =0; i<n; i++){
        curr = arr[i];
        
        while(umap.count(curr)>0){
            current.push_back(curr);
            curr = curr+1;
        }
        
        if(result.size()<current.size())
            result = current;
        
        if(current.size()==n)
            return current;
        
        current.clear();
        
    }
    
    return result;
}


int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}