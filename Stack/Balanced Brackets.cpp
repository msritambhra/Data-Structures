#include <bits/stdc++.h>
#include<stack>
using namespace std;

string isBalanced(string s) {
    stack<char> st;
    string result = "NO";
    char t;
    for(int i = 0 ; s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            st.push(s[i]);
            continue;
        }

        switch(s[i]){
            case ')':

                    if(st.empty())
                        return result;
                    t = st.top();
                    st.pop();
                    if(t!='(')
                        return result;
                    break;

            case ']':

                    if(st.empty())
                        return result;
                    t = st.top();
                    st.pop();
                    if(t!='[')
                        return result;
                    break;

            case '}':

                    if(st.empty())
                        return result;
                    t = st.top();
                    st.pop();
                    if(t!='{')
                        return result;
                    break;
        }
    }

    if(!st.empty())
        return result;
    else
        result = "YES";
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
