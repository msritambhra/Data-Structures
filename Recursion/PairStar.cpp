#include <iostream>
#include<cstring>
using namespace std;

/*

Given a string S, compute recursively a new string 
where identical chars that are adjacent in the original string are separated from each other by a "*".

*/

void pairStar(char input[]){  

    int size = strlen(input);

    if(size==0)
        return;

    if(input[0]==input[1]){
        for(int i = size-1 ;i>=1;i--){
            input[i+1] = input[i];
        }
        input[size+1] = '\0';
        input[1] = '*';
        pairStar(input+2);
    }

    else
        pairStar(input+1);
}



int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
