/*

The span si of a stock’s price on a certain day i is the minimum number of consecutive days
(up to the current day) the price of the stock has been less than its price on that ith day. 
If for a particular day,if no stock price is greater then just count the number of days till 0th day including current day.

*/


#include<stack>
#include <iostream>
using namespace std;


int* stockSpan(int *price, int size){
    int* output = new int[size];
    
    stack<int> s;
    
    s.push(0);
    output[0] = 1;
    
    for(int i = 1; i<size; i++){
        //Popping all elements less than current element
        while(!s.empty() && price[s.top()]<price[i])
            s.pop();
        
        // If stack is empty i.e. current element is the greatest encountered
        if(s.empty())
            output[i] = i+1;
        else
            output[i] = i - s.top();
        //Pushing current element's index into stack
        s.push(i);
        
    }
    
    return output;
}



int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}
