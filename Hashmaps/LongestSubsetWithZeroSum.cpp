
#include<unordered_map>
#include<iostream>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  
    if(size==0)
        return 0;
    if(size==1){
        if(arr[0] == 0)
            return 1;
        else
            return 0 ;
    }
    int sum = 0;
    int max = 0;
    

    unordered_map<int,int> umap;
    
    for(int i = 0;i<size;i++){
        sum += arr[i];
        if(umap.count(sum)>0){
            int sublen = i - umap[sum];
            if(sublen>max)
                max = sublen;
            if(max == size)
                return max;
            
        }
        else{
            umap[sum] = i; 
        }
    }
    
    return max;
}


int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}



