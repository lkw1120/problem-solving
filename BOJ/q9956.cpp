#include<bits/stdc++.h>
using namespace std;
string input,output;
string makeReveres(const string &word) {
    int cnt = 0;
    for(char ch: word) {
        if(isalpha(ch)) {
            cnt++;
        }
    }
    if(cnt < 2) {
        return word;
    }
    vector<char> v;
    for(char ch: word) {
        if(isalpha(ch)) {
            v.push_back(ch);
        }
    }
    reverse(v.begin(), v.end());
    string str = "";
    int idx = 0;
    for(char ch: word) {
        if(isalpha(ch)) {
            char tmp = v[idx];
            tmp = isupper(ch)? toupper(tmp): tolower(tmp);
            str+=tmp;
            idx++;
        } 
        else {
            str+=ch;
        }
    }
    return str;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(getline(cin, input)) {
        if(input == "#") break;
        int size,p;
        size = input.size();
        p = 0;
        output = "";
        while(p < size) {
            if(isspace(input[p])) {
                output+=input[p];
                p++;
            }
            else {
                int q = p;
                while(p < size && !isspace(input[p])) {
                    p++;
                }
                string word = input.substr(q, p-q);
                output+=makeReveres(word);
            }
        }
        cout<<output<<"\n";
    }
    return 0;
}