#include <iostream>
using namespace std;

class Interval{
    public:
    int buy;
    int sell;
};
int main() {
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
    	
    	int n;
    	cin>>n;
    	
    	if(n==1)
    	    continue;
    	    
    	int arr[n];  
    	
    	for(int i =0;i<n;i++)
    	    cin>>arr[i];
    	    
    	Interval result[n/2 + 1];
    	
    	int j =0; //index of result
    	
    	int i=0;
    	bool flag = true;
    	
    	while(i<n-1){
    	    
    	    //finding local minima
    	    while((i<n-1) && (arr[i+1]<=arr[i]))
    	            i++;
    	    
    	    if(i==n-1 && flag==true){
    	        cout<<"No Profit";
    	        break; }
    	        
    	    flag = false;
    	    result[j].buy = i++;
    	    
    	    //finding local maxima
    	    while((i<n) && (arr[i]>=arr[i-1]))
    	        i++;
    	   
    	   result[j].sell = i-1;
    	   
    	   if(result[j].buy!=result[j].sell)
    	        j++;
    	    
    	}
    
    	
    	for(int i =0; i<j;i++){
    	    cout<<"("<<result[i].buy<<" "<<result[i].sell<<")"<<" ";
    	}
    	
    	cout<<endl;
	    
	}
	return 0;
}