
#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched


int helper(int input[],int start,int end,int val){

    if(start>end)
        return -1;

    int mid=(start+end)/2;

    if(input[mid]==val)
        return mid;
    else if(input[mid]<val)
        start=mid+1;
    else if(input[mid]>val)
        end=mid-1;

    return helper(input,start,end,val);  
}


int binarySearch(int input[], int size, int element) {
    int start=0,end=size-1;

    int ans=helper(input,start,end,element);
    return ans;
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
