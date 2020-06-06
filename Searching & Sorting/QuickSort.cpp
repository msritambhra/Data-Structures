#include<iostream>
using namespace std;

void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;

}

int partition(int input[], int start, int end){

    int p = input[end]; //pivot element

    int i = start - 1;

    for(int j = start; j<end; j++){
        if (input[j] < p){

            i++;
            swap(&input[i],&input[j]);

        }
    }

    swap(&input[i+1],&input[end]);
    return i+1;
}

void helper(int input[],int start,int end){
    
    if(start>=end)
        return;
    
    int c=partition(input,start,end);
    
    helper(input,start,c-1);
    helper(input,c+1,end);
}

void quickSort(int input[], int size) {
    
    helper(input, 0, size-1);
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


