#include<cstring>
#include<cmath>
#include <iostream>
using namespace std;

int stringToNumber(char input[]){ 
    
    int size = strlen(input);
    
    if(size<=0)
        return 0;

    int ans = stringToNumber(input+1);

    int num = int(input[0]) - 48;
    return (num*pow(10,size-1)) + ans;
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
