#include<unordered_map>
#include<cmath>
#include<iostream>
using namespace std;

void PairSum(int *a, int size) {	 
    unordered_map<int,int> umap;
    for (int i =0;i<size;i++){
        if (umap.count(-1*a[i])>0){
            
            for(int j=0;j<umap[-1*a[i]];j++){
                if (a[i]<0){
                    cout<<a[i]<<" "<<-1*a[i]<<endl;
                }
                else{
                    cout<<-1*a[i]<<" "<<a[i]<<endl;
                }
            }

        }
        umap[a[i]]++;


    }


}




int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

