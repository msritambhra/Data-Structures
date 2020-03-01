#include <vector>
#include<climits>

class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    // Inserts the element in Priority Queue while mainting Min Heap and CBT Property
    void insert(int element) {
       
        pq.push_back(element);
    
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1)/2;
    
        while(parentIndex>=0){
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
        
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
        
    }
    
    // Removes & returns the minimum element in Priority Queue while mainting Min Heap and CBT Property
    int removeMin() {
        
        if(pq.size()==0){
            return INT_MIN;
        }
        
        int min = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;
        int leftChild = 2*parentIndex + 1;
        int rightChild = 2*parentIndex + 2;
        
        while(leftChild<pq.size()){
            
            if( pq[parentIndex]>pq[leftChild] && pq[leftChild]<pq[rightChild]){
                
                int temp = pq[parentIndex];
                pq[parentIndex]  = pq[leftChild];
                pq[leftChild] = temp;
                
                parentIndex = leftChild;
            }
            
            else if(rightChild<pq.size() && pq[parentIndex]>pq[rightChild]){
                
                int temp = pq[parentIndex];
                pq[parentIndex]  = pq[rightChild];
                pq[rightChild] = temp;
                
                parentIndex = rightChild;
            }
            
            else{
                break;
            }
            leftChild = 2*parentIndex + 1;
            rightChild = 2*parentIndex + 2;
        
        }
        
        return min;
        
    }
    
    
};





