#include<iostream>
using namespace std;

// Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.



void rotate(int **input, int n){
    
    int temp; 
    
    for(int i = 0; i<n; i++){
        for(int j =i+1; j<n; j++){
            temp = input[i][j];
    		input[i][j] = input[j][i];
            input[j][i] = temp;
        }
    }
    
    int start= 0, end = n-1;
    
    while(start<end){
        for(int j = 0; j<n; j++){
            temp = input[start][j];
            input[start][j] = input[end][j];
            input[end][j] = temp;
        }
        
        start++;
        end--;
    }
}


int main() {
    int n;
    cin >> n;
    
    int **input = new int*[n];
    
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    rotate(input, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}
