#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i = 0, j = 0, k = l ;

    int s1 = m-l+1;
    int s2 = r-m;
    int left[s1], right[s2];


    for(i = 0; i<s1; i++){
        left[i] = arr[l+i];
    }

    for(j = 0; j<s2; j++){
        right[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;

    while(i<s1&&j<s2){

        if (left[i]<right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while(j<s2){
        arr[k] = right[j];
        k++;
        j++;
    }


    while(i<s1){
        arr[k] = left[i];
        k++;
        i++;
    }

}

void helper(int input[], int start, int end){

    if(start<end){
        int mid = (start+end)/2;

        helper(input,start,mid);
        helper(input,mid+1,end);
        merge(input,start,mid,end);
    }}

void mergeSort(int input[], int size){

    if(size<=1)
        return;
    helper(input,0,size-1);       
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

