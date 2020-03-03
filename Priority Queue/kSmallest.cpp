#include<iostream>
using namespace std;
#include <vector>
#include<queue>


vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here

    
    priority_queue<int> pq;
    
    // Creating Max Heap Priority Queue of first k elements
    for(int i = 0 ; i < k ; i++){
        pq.push(input[i]);
    }
    
    // Comparing laready existing set of smallest k elements with rest of them  
    for(int i = k; i < n ;i++){
        
        // If element is less than max of existing et
        if(input[i]<pq.top()){
            pq.pop();      // pop the max element from priority queue
            pq.push(input[i]);  // push the smaller element into the priority queue
        }
        
    }
    
    // Creating resultant vector 
    vector<int> result;
    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }
    
    return result;
}


int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}
