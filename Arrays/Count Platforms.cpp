/*

Given two arrays (both of size n), one containing arrival time of trains and other containing the corresponding trains departure time (in the form of an integer) respectively.
Return the minimum number of platform required, such that no train waits.

*/


#include<iostream>
using namespace std;

#include<algorithm>
int platformsNeeded(int arrival[], int departure[], int n) {
    
    
    sort(arrival,arrival+n);
    sort(departure,departure+n);
    
    int i = 1, j =0;
    
    int platforms = 1, result = 1;
    
    while(i<n && j<n){
        
        if(arrival[i]<departure[j]){
            platforms++;
            i++;
            if(platforms>result)
                result = platforms;
        }
        
        else{
            platforms--;
            j++;
        }
    }
    
    return result;
}


int main()
{
	int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
    {
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);
}
