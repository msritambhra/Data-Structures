// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

#include<unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
    
    unordered_map<int,int> umap;
    for(int i =0; i<size1; i++){
        if (umap.count(input1[i])>0)
            umap[input1[i]]+=1;
        else
            umap[input1[i]]=1;
    }
    
    for(int i = 0; i <size2; i++){
        if(umap.count(input2[i])>0){
            cout<<input2[i]<<endl;
            umap[input2[i]]--;
            if(umap[input2[i]] == 0) 
             	umap.erase(input2[i]);
        }
    }

}



int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}
