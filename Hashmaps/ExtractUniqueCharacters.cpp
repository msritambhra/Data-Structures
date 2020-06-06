#include<unordered_map>
#include<cstring>
#include<iostream>
using namespace std;


char* uniqueChar(char *str){
    
    int len = strlen(str);
    char *str1 = new char[len];
    
    unordered_map<char,bool> umap;
    int count = 0;
    char current_char;
    
    for(int i =0 ;i<len; i++){
        current_char = str[i];
        if (umap.count(current_char)>0)
            continue;
        else{
            umap[current_char] = true;
            str1[count] = current_char;
            count++;
        }
    }
   return str1;
}


int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
