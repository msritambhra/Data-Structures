#include<climits>
#include<unordered_map>
#include<iostream>


using namespace std;

/*int FindUnique(int * arr, int size){
    
    int unique;
    
    for(int i = 0 ; i<size; i++){
        bool flag = true;
        for(int j = 0 ; j<size; j++){
            if(i!=j && arr[i]==arr[j])
                flag = false;
        }
        if(flag ==true){
            unique = arr[i];
            return unique;
        }
    }
    
    return INT_MIN;
}*/


// 2. Using Hashmaps


int FindUnique(int * arr, int size){
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i<size; i++){
        if(umap.count(arr[i])>0)
            umap[arr[i]] +=1;
        else
            umap[arr[i]] = 1;
    }
    
    for(auto it = umap.begin(); it!=umap.end(); it++)
        if(it->second==1)
            return it->first;
    
    return INT_MIN;
}



int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindUnique(input,size)<<endl;
		
	return 0;
}

