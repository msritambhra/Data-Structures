#include <iostream>

#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    
    int i=0;
    vector<int> result;
    
    // Priority queue havinf element of Pair type : first-> element of array , second->pair: first->number of array(1,2..k),
    //second-> next index of element of given array
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
   
    //Creating a Min Heap with k elements
    for(i = 0; i<input.size();i++){
        
       pair<int,pair<int,int>> p;
       p.first = input[i]->at(0);
       p.second.first = i;
       p.second.second = 1;
        
       pq.push(p);
        
   }
    
    
    while(!pq.empty()){
        
        // pushing minimum of heap into our result vector
        result.push_back(pq.top().first);
        
        // if the minimum element is not the last of its array, then pushing next element in out heap or priority queue
        if(pq.top().second.second<input[pq.top().second.first]->size()){
            
            pair<int,pair<int,int>> p;
            
            int x = pq.top().second.first;
            int y  = pq.top().second.second;
            
            p.first = input[x]->at(y);
            p.second.first = x;
            p.second.second = y+1;
            
            pq.push(p);
            
        }
        
        //Removing the minimum element from our heap or priority queue
        pq.pop();       
        
    }
        
    return result;
    
    

}


int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
