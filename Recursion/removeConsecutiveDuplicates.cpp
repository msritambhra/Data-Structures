#include<cstring>
#include <iostream>
using namespace std;


void removeConsecutiveDuplicates(char *input) {
    int size=strlen(input);

    if(size==1)
        return;

    removeConsecutiveDuplicates(input+1);

    if(input[0]==input[1]){
        for(int i =1; i<size; i++)
            input[i] = input[i+1];

    }

}


int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}