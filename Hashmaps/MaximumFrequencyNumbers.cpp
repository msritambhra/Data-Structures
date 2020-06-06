#include<unordered_map>	
#include<iostream>
using namespace std;

int highestFrequency(int *input, int n){	 

    unordered_map<int,int> umap;
	int max = 0;
    int maxn = input[0];
    for(int i =0 ; i <n; i++){
        if (umap.count(input[i])>0)
            umap[input[i]]+=1;
        else
            umap[input[i]] = 1;
        
        if( umap[input[i]]>max){
            max = umap[input[i]];
            maxn = input[i];
        }
    }

    return maxn;


}




int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}


