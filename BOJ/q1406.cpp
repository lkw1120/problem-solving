#include <bits/stdc++.h>
using namespace std;
stack<char> st1,st2;
string str;
char cmd,c;
int M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
    for(int i=0;i<str.size();i++) {
        st1.push(str[i]);
    }
	cin>>M;
	for(int i=0;i<M;i++) {
        cin>>cmd;
        if(cmd == 'L') {
            if(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else if(cmd == 'D') {
            if(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
        else if(cmd == 'B') {
            if (!st1.empty()) {
                st1.pop();
            }
        }
        else if(cmd == 'P') {
            cin>>c;
            st1.push(c);
        }
    }
    while(!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }
    while(!st2.empty()) {
        cout<<st2.top();
        st2.pop();
    }
	cout<<"\n";
	return 0;
}