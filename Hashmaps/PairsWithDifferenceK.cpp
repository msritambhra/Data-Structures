#include<unordered_map>
#include<iostream>
using namespace std;

void printPairs(int *input, int n, int k) {
    
    unordered_map<int,int> umap;
    
    if(k<0)
        k *=-1;
    for(int i = 0; i<n; i++){
        if(umap.count(input[i]-k)>0){
            for(int j = 0; j<umap[input[i]-k];j++)
                cout<<input[i]-k<<" "<<input[i]<<endl;
        }
        
        if(k!=0 && umap.count(input[i]+k)>0){
            for(int j = 0; j<umap[input[i]+k];j++)
                cout<<input[i]<<" "<<input[i]+k<<endl;
        }
        
        if(umap.count(input[i])>0)
            umap[input[i]]+=1;
        else
            umap[input[i]]=1;
        
    }
}



int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
